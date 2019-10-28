#include "ft_printf.h"

void			fp_parse_e(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	t_fp_double		*f;

	//if (tags->mask & FP_MASK_LENGTH_FL)
	//	return (case_lf(ap, tags, arg));
	f = &arg->data.f;
	f->float64 = va_arg(ap, double);
	if (fp_get_double_scientific_parts(f->float64, tags->precision,
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
