/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:29:46 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:29:47 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		case_le(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	t_fp_double		*f;

	f = &arg->data.f;
	f->float128 = va_arg(ap, long double);
	if (fp_ldouble_get_scientific_parts(f->float128, tags->precision,
		&f->int_part, &f->fraction_part) == FP_FAIL)
	{
		fxp_del(&f->int_part);
		fxp_del(&f->fraction_part);
	}
	arg->length = &fp_arg_le_length;
	arg->sign = &fp_arg_lf_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_le_write;
	if (ft_is_nan_l(f->float128) || ft_is_inf_l(f->float128))
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}

void			fp_parse_e(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	t_fp_double		*f;

	if (tags->mask & FP_MASK_LENGTH_FL)
		return (case_le(ap, tags, arg));
	f = &arg->data.f;
	f->float64 = va_arg(ap, double);
	if (fp_double_get_scientific_parts(f->float64, tags->precision,
		&f->int_part, &f->fraction_part) == FP_FAIL)
	{
		fxp_del(&f->int_part);
		fxp_del(&f->fraction_part);
	}
	arg->length = &fp_arg_e_length;
	arg->sign = &fp_arg_f_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_e_write;
	if (ft_is_nan(f->float64) || ft_is_inf(f->float64))
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}
