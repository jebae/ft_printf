#include "ft_printf.h"

size_t		fp_arg_d_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((int)(data->i)));
}

size_t		fp_arg_hd_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((short)(data->i)));
}

size_t		fp_arg_hhd_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((char)(data->i)));
}

size_t		fp_arg_ld_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((long)(data->i)));
}

size_t		fp_arg_lld_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((long long)(data->i)));
}
