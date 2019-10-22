#include "ft_printf.h"

static size_t	parse_str(const char *format, t_fp_buffer *buf)
{
	size_t		i;

	i = 0;
	while (*(format + i) != '\0' && *(format + i) != '%')
	{
		fp_write_buffer(buf, *(format + i));
		i++;
		if (i == FP_ULLONG_MAX)
			return (i);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	va_start(ap, format);
	if (format == NULL)
		return (0);
	while (*format != '\0')
	{
		format += fp_parse_percent(format, ap, &buf);
		format += parse_str(format, &buf);
	}
	fp_flush_buffer(&buf);
	va_end(ap);
	return (buf.written);
}
