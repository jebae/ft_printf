/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:15:27 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:15:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fp_parse_lf(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	arg->data.lf = va_arg(ap, long double);
	arg->length = &fp_arg_lf_length;
	arg->sign = &fp_arg_lf_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_lf_write;
	if (ft_is_nan_l(arg->data.lf) || ft_is_inf_l(arg->data.lf))
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}

void		fp_parse_f(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	if (tags->mask & FP_MASK_LENGTH_FL)
		return (fp_parse_lf(ap, tags, arg));
	arg->data.f = va_arg(ap, double);
	arg->length = &fp_arg_f_length;
	arg->sign = &fp_arg_f_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_f_write;
	if (ft_is_nan(arg->data.f) || ft_is_inf(arg->data.f))
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}
