/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:33:16 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:33:17 by jebae            ###   ########.fr       */
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
