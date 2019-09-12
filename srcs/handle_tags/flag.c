#include "ft_printf.h"

size_t		handle_flag(const char *format, t_tags *tags)
{
	size_t		stride;

	stride = 1;
	tags->bit_mask |= PRTF_BIT_MASK_FLAG;
	if (*format == '-')
		tags->flag = PRTF_FLAG_MINUS;
	else if (*format == '+')
		tags->flag = PRTF_FLAG_PLUS;
	else if (*format == ' ')
		tags->flag = PRTF_FLAG_SPACE;
	else if (*format == '0')
		tags->flag = PRTF_FLAG_ZERO;
	else
	{
		stride = 0;
		tags->bit_mask &= ~PRTF_BIT_MASK_FLAG;
	}
	return (stride);
}
