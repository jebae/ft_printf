/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:15:31 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:15:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fp_parse_p(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	arg->data.i = va_arg(ap, long long);
	arg->length = &fp_arg_llx_length;
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_leading_zero;
	arg->prefix = &fp_arg_p_prefix;
	arg->write = &fp_arg_llx_write;
	if (tags->mask & FP_MASK_PRECISION)
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}
