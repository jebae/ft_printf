#include "ft_printf.h"

size_t	fp_parse_width(const char *format, t_fp_tags *tags)
{
	size_t		i;

	if (!ft_isdigit(format[0]) || format[0] == '0')
		return (0);
	tags->width = 0;
	i = 0;
	while (ft_isdigit(format[i]))
	{
		tags->width *= 10;
		tags->width += format[i] - '0';
		i++;
	}
	return (i);
}
