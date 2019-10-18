#include "ft_printf.h"

size_t		fp_arg_d_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((int)(data->i), 10));
}

size_t		fp_arg_hd_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((short)(data->i), 10));
}

size_t		fp_arg_hhd_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((char)(data->i), 10));
}

size_t		fp_arg_ld_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((long)(data->i), 10));
}

size_t		fp_arg_lld_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length(data->i, 10));
}
