#include "ft_printf.h"

size_t		fp_arg_e_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	size_t		len;
	int			exponent;

	if (ft_is_nan(data->f.float64) || ft_is_inf(data->f.float64))
		return (3);
	len = 1 + tags->precision + 2 + 2;
	if (tags->precision > 0 || (tags->mask & FP_MASK_FLAG_SHARP))
		len++;
	exponent = fp_get_scientific_exponent(
		&data->f.int_part, &data->f.fraction_part);
	exponent /= 100;
	while (exponent != 0)
	{
		len++;
		exponent /= 10;
	}
	return (len);
}
