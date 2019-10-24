/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:15:21 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:15:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fp_parse_c(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	(void)tags;
	arg->data.i = va_arg(ap, unsigned long long);
	arg->length = &fp_arg_c_length;
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_c_write;
}
