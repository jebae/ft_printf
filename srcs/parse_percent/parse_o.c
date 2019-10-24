/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:15:29 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:15:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		case_ho(t_fp_arg *arg)
{
	arg->length = &fp_arg_ho_length;
	arg->write = &fp_arg_ho_write;
}

static void		case_hho(t_fp_arg *arg)
{
	arg->length = &fp_arg_hho_length;
	arg->write = &fp_arg_hho_write;
}

static void		case_lo(t_fp_arg *arg)
{
	arg->length = &fp_arg_lo_length;
	arg->write = &fp_arg_lo_write;
}

static void		case_llo(t_fp_arg *arg)
{
	arg->length = &fp_arg_llo_length;
	arg->write = &fp_arg_llo_write;
}

void			fp_parse_o(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	arg->data.i = va_arg(ap, unsigned long long);
	if (tags->mask & FP_MASK_LENGTH_LL)
		case_llo(arg);
	else if (tags->mask & FP_MASK_LENGTH_L)
		case_lo(arg);
	else if (tags->mask & FP_MASK_LENGTH_H)
		case_ho(arg);
	else if (tags->mask & FP_MASK_LENGTH_HH)
		case_hho(arg);
	else
	{
		arg->length = &fp_arg_o_length;
		arg->write = &fp_arg_o_write;
	}
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_o_leading_zero;
	arg->prefix = &fp_arg_o_prefix;
	if (tags->mask & FP_MASK_PRECISION)
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}
