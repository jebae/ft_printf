#include "ft_printf.h"

size_t		fp_arg_s_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	size_t		len;
	char		*str;

	str = (char *)data->ptr;
	len = 0;
	while (*(str++) != '\0')
	{
		len++;
		if (len == FP_ULLONG_MAX)
			return (len);
	}
	if ((tags->mask & FP_MASK_PRECISION) && tags->precision < len)
		return (tags->precision);
	return (len);
}
