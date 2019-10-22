#include "ft_printf.h"

static void		case_hx(t_fp_arg *arg)
{
	arg->length = &fp_arg_hx_length;
	arg->write = &fp_arg_h_upper_x_write;
}

static void		case_hhx(t_fp_arg *arg)
{
	arg->length = &fp_arg_hhx_length;
	arg->write = &fp_arg_hh_upper_x_write;
}

static void		case_lx(t_fp_arg *arg)
{
	arg->length = &fp_arg_lx_length;
	arg->write = &fp_arg_l_upper_x_write;
}

static void		case_llx(t_fp_arg *arg)
{
	arg->length = &fp_arg_llx_length;
	arg->write = &fp_arg_ll_upper_x_write;
}

void			fp_parse_upper_x(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	arg->data.i = va_arg(ap, unsigned long long);
	if (tags->mask & FP_MASK_LENGTH_LL)
		case_llx(arg);
	else if (tags->mask & FP_MASK_LENGTH_L)
		case_lx(arg);
	else if (tags->mask & FP_MASK_LENGTH_H)
		case_hx(arg);
	else if (tags->mask & FP_MASK_LENGTH_HH)
		case_hhx(arg);
	else
	{
		arg->length = &fp_arg_x_length;
		arg->write = &fp_arg_upper_x_write;
	}
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_leading_zero;
	arg->prefix = &fp_arg_upper_x_prefix;
	if (tags->mask & FP_MASK_PRECISION)
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}
