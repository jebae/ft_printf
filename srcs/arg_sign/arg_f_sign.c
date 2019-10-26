#include "ft_printf.h"

char	fp_arg_f_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (ft_is_nan(data->f.float64))
		return (FP_NO_SIGN);
	if (*((long long *)&data->f.float64) & 0x8000000000000000)
		return ('-');
	return (fp_num_sign(data->f.float64 >= 0.0, tags));
}

char	fp_arg_lf_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	char	*ptr;

	if (ft_is_nan_l(data->f.float128))
		return (FP_NO_SIGN);
	ptr = ((char *)&data->f.float128) + 9;
	if (*ptr & 0x80)
		return ('-');
	return (fp_num_sign(data->f.float128 >= 0.0, tags));
}
