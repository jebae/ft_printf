/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_o_leading_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:12:45 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:12:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			fp_arg_o_leading_zero(t_fp_tags *tags, size_t length)
{
	if (length == 0 && (tags->mask & FP_MASK_FLAG_SHARP))
		return (1);
	if ((tags->mask & FP_MASK_PRECISION) && tags->precision > length)
	{
		if (tags->mask & FP_MASK_FLAG_SHARP)
			return (tags->precision - length - 1);
		return (tags->precision - length);
	}
	return (0);
}
