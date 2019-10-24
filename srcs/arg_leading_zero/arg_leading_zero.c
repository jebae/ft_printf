/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_leading_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:12:39 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:12:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			fp_arg_leading_zero(t_fp_tags *tags, size_t length)
{
	if ((tags->mask & FP_MASK_PRECISION) && tags->precision > length)
		return (tags->precision - length);
	return (0);
}
