#include "ft_printf.h"

void		fp_parse_c(va_list ap, t_fp_tags *tags, t_fp_arg *arg)
{
	(void)tags;
	arg->data.i = va_arg(ap, unsigned long long);
	arg->length = &fp_arg_c_length;
	arg->sign = &fp_arg_no_sign;
	arg->write = &fp_arg_c_write;
}
