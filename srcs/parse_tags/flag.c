#include "ft_printf.h"

size_t	fp_parse_flag(const char *format, t_fp_tags *tags)
{
	if (*format == '-')
		tags->mask |= FP_MASK_FLAG_MINUS;
	else if (*format == '+')
		tags->mask |= FP_MASK_FLAG_PLUS;
	else if (*format == ' ')
		tags->mask |= FP_MASK_FLAG_SPACE;
	else if (*format == '0')
		tags->mask |= FP_MASK_FLAG_ZERO;
	else
		return (0);
	return (1);
}
