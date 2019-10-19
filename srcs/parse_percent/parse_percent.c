#include "ft_printf.h"

static size_t	handle_percent(t_fp_buffer *buf)
{
	fp_write_buffer(buf, '%');
	return (2);
}

static void		init_arg(t_fp_arg *arg)
{
	arg->length = NULL;
	arg->sign = NULL;
	arg->write = NULL;
	ft_memset(&arg->data, 0, sizeof(t_fp_arg_data));
}

size_t			fp_parse_percent(
	const char *format,
	va_list ap,
	t_fp_buffer *buf
)
{
	size_t		i;
	size_t		j;
	t_fp_arg	arg;
	t_fp_tags	tags;

	if (format == NULL || *format != '%')
		return (0);
	i = 1;
	if (format[i] == '%')
		return (handle_percent(buf));
	fp_init_tags(&tags);
	init_arg(&arg);
	j = 1;
	while (j != 0)
	{
		j = 0;
		j += fp_parse_flag(format + i, &tags);
		j += fp_parse_width(format + i, &tags);
		j += fp_parse_precision(format + i, &tags);
		j += fp_parse_length(format + i, &tags);
		i += j;
	}
	i += fp_parse_specifier(format + i, ap, &tags, &arg);
	fp_write_percent_format(&arg, &tags, buf);
	return (i);
}
