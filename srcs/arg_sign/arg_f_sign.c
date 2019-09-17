#include "ft_printf.h"

char	fp_arg_f_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	return (fp_num_sign(data->f >= 0.0, tags));
}

char	fp_arg_lf_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	return (fp_num_sign(data->lf >= 0.0, tags));
}
