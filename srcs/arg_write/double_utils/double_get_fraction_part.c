/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_get_fraction_part.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:35 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:18:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		handle_fail(t_fixedpoint *fxp, t_bigint *bi)
{
	fxp_del(fxp);
	if (bi != NULL)
		bi_del(bi);
	return (FP_FAIL);
}

static void		get_sum(
	t_fixedpoint *sum,
	unsigned long long mantissa,
	size_t num_bits
)
{
	size_t		i;
	size_t		j;

	num_bits = (num_bits > 53) ? 53 : num_bits;
	j = num_bits / 8;
	i = 0;
	while (i < j)
	{
		bi_push(&sum->num, mantissa & 0xff);
		mantissa >>= 8;
		i++;
	}
	j = num_bits % 8;
	while (j > 0)
	{
		bi_set_bit(&sum->num, i * 8 + j - 1, (mantissa >> (j - 1)) & 1);
		j--;
	}
}

int				fp_get_reciprocal(t_fixedpoint *recip, size_t num_bits)
{
	size_t			i;
	t_bigint		temp;

	if (bi_push(&recip->num, 1) == BI_FAIL)
		return (FP_FAIL);
	if (num_bits == 0)
		return (FP_SUCCESS);
	bi_init(&temp);
	i = 0;
	while (i < num_bits)
	{
		if (bi_copy(&temp, &recip->num) == BI_FAIL ||
			bi_left_shift(&recip->num, 2, &recip->num) == BI_FAIL ||
			bi_add_bi(&recip->num, &temp, &recip->num) == BI_FAIL)
		{
			bi_del(&temp);
			return (FP_FAIL);
		}
		i++;
	}
	recip->e -= (long long)num_bits;
	bi_del(&temp);
	return (FP_SUCCESS);
}

int				fp_round_fraction_part(
	t_fixedpoint *fraction_part,
	long long precision
)
{
	long long	len;
	long long	pos;

	len = bcd_len(&fraction_part->num);
	pos = -(precision + fraction_part->e);
	if (pos > len)
		bi_erase(&fraction_part->num);
	else if (pos > 0)
	{
		if (bcd_round(
			&fraction_part->num, pos, &fraction_part->num) == BI_FAIL)
			return (FP_FAIL);
	}
	if (fraction_part->num.occupied == 0)
		fraction_part->e = 0;
	else
		fraction_part->e += bcd_rm_trailing_zero(&fraction_part->num);
	return (FP_SUCCESS);
}

int				fp_double_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	size_t precision,
	t_fixedpoint *fraction_part
)
{
	size_t			size;
	size_t			num_bits;
	t_bigint		bcd;
	t_fixedpoint	recip;

	bi_init(&bcd);
	fxp_init(&recip);
	num_bits = (exponent < 52) ? (52 - exponent) : 0;
	size = (num_bits % BI_UNIT_BITS)
		? num_bits / BI_UNIT_BITS + 1
		: num_bits / BI_UNIT_BITS;
	size = (size > 1) ? size : 1;
	if (bi_memalloc(&fraction_part->num, size) == BI_FAIL ||
		fp_get_reciprocal(&recip, num_bits) == FP_FAIL)
		return (handle_fail(&recip, &bcd));
	get_sum(fraction_part, mantissa, num_bits);
	if (fxp_mul_fxp(fraction_part, &recip, fraction_part, 0) == FXP_FAIL ||
		bi_double_dabble(&fraction_part->num, &bcd) == BI_FAIL)
		return (handle_fail(&recip, &bcd));
	bi_del(&fraction_part->num);
	fraction_part->num = bcd;
	if (fp_round_fraction_part(fraction_part, precision) == FP_FAIL)
		return (handle_fail(&recip, NULL));
	fxp_del(&recip);
	return (FP_SUCCESS);
}
