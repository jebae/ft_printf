/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_get_bcd_fraction_part.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:29:29 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:29:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				fp_double_get_bcd_fraction_part(
	short exponent,
	unsigned long long mantissa,
	int (*get_fraction_part)(short, unsigned long long, t_fixedpoint *),
	t_fixedpoint *fraction_part
)
{
	t_bigint		bcd;

	bi_init(&bcd);
	if (get_fraction_part(exponent, mantissa, fraction_part) == FXP_FAIL)
		return (FP_FAIL);
	if (bi_double_dabble(&fraction_part->num, &bcd) == BI_FAIL)
	{
		bi_del(&bcd);
		return (FP_FAIL);
	}
	bi_del(&fraction_part->num);
	fraction_part->num = bcd;
	return (FP_SUCCESS);
}
