#include "ft_printf.h"

size_t		fp_arg_f_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	size_t		len;

	len = tags->precision;
	if (len > 0)
		len++;
	return (fp_double_int_part_length(data->f) + len);
}
