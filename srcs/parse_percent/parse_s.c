#include "ft_printf.h"

void		fp_parse_s(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	(void)tags;
	arg->data.ptr = va_arg(ap, char *);
	arg->length = &fp_arg_s_length;
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_s_write;
}
