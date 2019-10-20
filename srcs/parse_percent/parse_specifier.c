#include "ft_printf.h"

size_t		fp_parse_specifier(
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
	/*
	else
		// handle character which is not specifier -> test every ascii
		// similar to %c
		// but arg.data.i has to be assigned without va_list
	*/
	return (1);
}
