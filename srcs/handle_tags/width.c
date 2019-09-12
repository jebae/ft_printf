#include "ft_printf.h"

size_t		handle_width(const char *format, t_tags *tags)
{
	tags->width = 0;
	while (ft_isdigit(format[tags->width]))
		tags->width++;
	if (tags->width)
		tags->bit_mask |= PRTF_BIT_MASK_WIDTH;
	return (tags->width);
}
