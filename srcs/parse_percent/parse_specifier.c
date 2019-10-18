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
	/*
	else
		// handle character which is not specifier
		// similar to %c
		// but arg.data.i has to be assigned without va_list
	*/
	return (1);
}
