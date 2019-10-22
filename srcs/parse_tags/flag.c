#include "ft_printf.h"

static int		case_extra(char ch)
{
	static char		*extras = ",'*:;_";
	int				i;

	i = 0;
	while (i < 6)
	{
		if (ch == extras[i])
			return (1);
		i++;
	}
	return (0);
}

size_t			fp_parse_flag(const char *format, t_fp_tags *tags)
{
	if (*format == '-')
		tags->mask |= FP_MASK_FLAG_MINUS;
	else if (*format == '+')
		tags->mask |= FP_MASK_FLAG_PLUS;
	else if (*format == ' ')
		tags->mask |= FP_MASK_FLAG_SPACE;
	else if (*format == '0')
		tags->mask |= FP_MASK_FLAG_ZERO;
	else if (*format == '#')
		tags->mask |= FP_MASK_FLAG_SHARP;
	else
		return (case_extra(*format));
	return (1);
}
