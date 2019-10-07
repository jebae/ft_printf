#include "ft_printf.h"

static void		case_hd(t_fp_arg *arg)
{
	arg->length = &fp_arg_hd_length;
	arg->sign = &fp_arg_hd_sign;
	arg->write = &fp_arg_hd_write;
}

static void		case_hhd(t_fp_arg *arg)
{
	arg->length = &fp_arg_hhd_length;
	arg->sign = &fp_arg_hhd_sign;
	arg->write = &fp_arg_hhd_write;
}

static void		case_ld(t_fp_arg *arg)
{
	arg->length = &fp_arg_ld_length;
	arg->sign = &fp_arg_ld_sign;
	arg->write = &fp_arg_ld_write;
}

static void		case_lld(t_fp_arg *arg)
{
	arg->length = &fp_arg_lld_length;
	arg->sign = &fp_arg_lld_sign;
	arg->write = &fp_arg_lld_write;
}

void			fp_parse_d(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	arg->data.i = va_arg(ap, long long);
	if (tags->mask & FP_MASK_LENGTH_LL)
		case_lld(arg);
	else if (tags->mask & FP_MASK_LENGTH_L)
		case_ld(arg);
	else if (tags->mask & FP_MASK_LENGTH_H)
		case_hd(arg);
	else if (tags->mask & FP_MASK_LENGTH_HH)
		case_hhd(arg);
	else
	{
		arg->length = &fp_arg_d_length;
		arg->sign = &fp_arg_d_sign;
		arg->write = &fp_arg_d_write;
	}
}
