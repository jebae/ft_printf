/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble_get_fraction_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:53 by jebae             #+#    #+#             */
/*   Updated: 2019/10/26 21:45:15 by jebae            ###   ########.fr       */
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

	num_bits = (num_bits > 64) ? 64 : num_bits;
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

int				fp_ldouble_get_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
)
{
	size_t			size;
	size_t			num_bits;
	t_bigint		bcd;
	t_fixedpoint	recip;

	bi_init(&bcd);
	fxp_init(&recip);
	num_bits = (exponent < 63) ? (63 - exponent) : 0;
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
	fxp_del(&recip);
	return (FP_SUCCESS);
}
