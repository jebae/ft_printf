#include "ft_printf.h"

size_t		fp_arg_f_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	size_t		len;

	if (ft_is_nan(data->f) || ft_is_inf(data->f))
		return (3);
	len = tags->precision;
	if (tags->precision > 0 || (tags->mask & FP_MASK_FLAG_SHARP))
		len++;
	return (fp_double_int_part_length(data->f) + len);
}

size_t		fp_arg_lf_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	size_t		len;

	if (ft_is_nan_l(data->lf) || ft_is_inf_l(data->lf))
		return (3);
	len = tags->precision;
	if (tags->precision > 0 || (tags->mask & FP_MASK_FLAG_SHARP))
		len++;
	return (fp_ldouble_int_part_length(data->lf) + len);
}
