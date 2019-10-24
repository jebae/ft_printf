/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble_get_integer_part.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:55 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:56 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		handle_fail(t_bigint *bi)
{
	bi_del(bi);
	return (BI_FAIL);
}

static size_t	get_size(short exponent)
{
	size_t	size;

	size = (exponent > 0) ? (1 + exponent) : 1;
	return ((size % BI_UNIT_BITS)
		? size / BI_UNIT_BITS + 1
		: size / BI_UNIT_BITS);
}

int				fp_ldouble_get_integer_part(
	short exponent,
	unsigned long long mantissa,
	int carry,
	t_fixedpoint *int_part
)
{
	size_t		size;
	t_bigint	bcd;

	bi_init(&bcd);
	size = get_size(exponent);
	if (bi_memalloc(&int_part->num, size) == FXP_FAIL)
		return (FP_FAIL);
	if (exponent < 0)
		mantissa = 0;
	else
		mantissa >>= 63 - ft_max_int(ft_min_int(exponent, 63), -1);
	while (mantissa)
	{
		bi_push(&int_part->num, mantissa & 0xff);
		mantissa >>= 8;
	}
	if (exponent > 63)
		bi_left_shift(&int_part->num, exponent - 63, &int_part->num);
	if (carry && fp_double_handle_carry(int_part) == FP_FAIL)
		return (handle_fail(&bcd));
	if (bi_double_dabble(&int_part->num, &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	bi_del(&int_part->num);
	int_part->num = bcd;
	return (FP_SUCCESS);
}
