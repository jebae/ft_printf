/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:13:34 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 15:02:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		case_ls(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	(void)tags;
	arg->data.ptr = va_arg(ap, wchar_t *);
	arg->length = &fp_arg_ls_length;
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_ls_write;
}

void			fp_parse_s(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	if (tags->mask & FP_MASK_LENGTH_L)
		return (case_ls(ap, tags, arg));
	arg->data.ptr = va_arg(ap, char *);
	arg->length = &fp_arg_s_length;
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_s_write;
}

void			fp_parse_c(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	(void)tags;
	arg->data.i = va_arg(ap, unsigned long long);
	arg->length = &fp_arg_c_length;
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_c_write;
}
