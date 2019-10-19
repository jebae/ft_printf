#include "ft_printf.h"

void		fp_parse_f(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	(void)tags;
	arg->data.f = va_arg(ap, double);
	arg->length = &fp_arg_f_length;
	arg->sign = &fp_arg_f_sign;
	arg->write = &fp_arg_f_write;
	if (ft_is_nan(arg->data.f) || ft_is_inf(arg->data.f))
		tags->mask |= FP_MASK_IGNORE_ZERO_PAD;
}
