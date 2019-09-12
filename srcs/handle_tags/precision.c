#include "ft_printf.h"

size_t		handle_precision(const char *format, t_tags *tags)
{

	tags->precision = 0;
	while (ft_isdigit(format[i]))
		tags->width++;
	if (tags->width != 0)
		tags->bit_mask |= PRTF_BIT_MASK_WIDTH;
	return (tags->width);
}
