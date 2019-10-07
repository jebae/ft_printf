#include "ft_printf.h"

size_t		fp_parse_specifier(
	const char *format,
	va_list valist,
	t_fp_tags *tags,
	t_fp_arg *arg
)
{
	if (format == NULL || *format == '\0')
		return (0);
	if (*format == 'd')
		fp_parse_d(valist, tags, arg);
	else
		// handle character which is not specifier
	return (1);
}
