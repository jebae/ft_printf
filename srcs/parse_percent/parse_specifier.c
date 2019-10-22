#include "ft_printf.h"

static void		parse_non_specifier(t_fp_arg *arg, char ch)
{
	arg->data.i = ch;
	arg->length = &fp_arg_c_length;
	arg->sign = &fp_arg_no_sign;
	arg->leading_zero = &fp_arg_no_leading_zero;
	arg->prefix = &fp_arg_no_prefix;
	arg->write = &fp_arg_c_write;
}

size_t			fp_parse_specifier(
	const char *format,
	va_list ap,
	t_fp_tags *tags,
	t_fp_arg *arg
)
{
	if (format == NULL || *format == '\0')
		return (0);
	if (*format == 'd' || *format == 'i')
		fp_parse_d(ap, tags, arg);
	else if (*format == 'u')
		fp_parse_u(ap, tags, arg);
	else if (*format == 'f')
		fp_parse_f(ap, tags, arg);
	else if (*format == 'x')
		fp_parse_x(ap, tags, arg);
	else if (*format == 'X')
		fp_parse_upper_x(ap, tags, arg);
	else if (*format == 'o')
		fp_parse_o(ap, tags, arg);
	else if (*format == 's')
		fp_parse_s(ap, tags, arg);
	else if (*format == 'c')
		fp_parse_c(ap, tags, arg);
	else if (*format == 'p')
		fp_parse_p(ap, tags, arg);
	else
		parse_non_specifier(arg, *format);
	return (1);
}
