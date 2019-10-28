/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_get_bcd_int_part.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:29:32 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:32:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				fp_double_get_bcd_int_part(
	short exponent,
	unsigned long long mantissa,
	int (*get_int_part)(short, unsigned long long, t_fixedpoint *),
	t_fixedpoint *int_part
)
{
	t_bigint	bcd;

	bi_init(&bcd);
	if (get_int_part(exponent, mantissa, int_part) == FXP_FAIL)
		return (FP_FAIL);
	if (bi_double_dabble(&int_part->num, &bcd) == BI_FAIL)
	{
		bi_del(&bcd);
		return (FP_FAIL);
	}
	bi_del(&int_part->num);
	int_part->num = bcd;
	return (FP_SUCCESS);
}
