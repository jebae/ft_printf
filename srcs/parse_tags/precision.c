#include "ft_printf.h"

size_t		fp_parse_precision(const char *format, t_fp_tags *tags)
{
	size_t		i;

	if (format[0] != '.')
		return (0);
	tags->mask |= FP_MASK_PRECISION;
	tags->precision = 0;
	i = 1;
	while (ft_isdigit(format[i]))
	{
		tags->precision *= 10;
		tags->precision += format[i] - '0';
		i++;
	}
	return (i);
}
