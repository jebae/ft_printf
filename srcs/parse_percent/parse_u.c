#include "ft_printf.h"

static void		case_hu(t_fp_arg *arg)
{
	arg->length = &fp_arg_hu_length;
	arg->write = &fp_arg_hu_write;
}

static void		case_hhu(t_fp_arg *arg)
{
	arg->length = &fp_arg_hhu_length;
	arg->write = &fp_arg_hhu_write;
}

static void		case_lu(t_fp_arg *arg)
{
	arg->length = &fp_arg_lu_length;
	arg->write = &fp_arg_lu_write;
}

static void		case_llu(t_fp_arg *arg)
{
	arg->length = &fp_arg_llu_length;
	arg->write = &fp_arg_llu_write;
}

void			fp_parse_u(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	arg->data.i = va_arg(ap, unsigned long long);
	if (tags->mask & FP_MASK_LENGTH_LL)
		case_llu(arg);
	else if (tags->mask & FP_MASK_LENGTH_L)
		case_lu(arg);
	else if (tags->mask & FP_MASK_LENGTH_H)
		case_hu(arg);
	else if (tags->mask & FP_MASK_LENGTH_HH)
		case_hhu(arg);
	else
	{
		arg->length = &fp_arg_u_length;
		arg->write = &fp_arg_u_write;
	}
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	if (tags->mask & FP_MASK_PRECISION)
		tags->mask &= ~FP_MASK_FLAG_ZERO;
}
