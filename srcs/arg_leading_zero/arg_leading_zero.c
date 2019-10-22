#include "ft_printf.h"

size_t			fp_arg_leading_zero(t_fp_tags *tags, size_t length)
{
	if ((tags->mask & FP_MASK_PRECISION) && tags->precision > length)
		return (tags->precision - length);
	return (0);
}
