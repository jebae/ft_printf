#include "ft_printf.h"

size_t		fp_arg_x_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((unsigned int)(data->i), 16));
}

size_t		fp_arg_hx_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((unsigned short)(data->i), 16));
}

size_t		fp_arg_hhx_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((unsigned char)(data->i), 16));
}

size_t		fp_arg_lx_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((unsigned long)(data->i), 16));
}

size_t		fp_arg_llx_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_int_length((unsigned long long)data->i, 16));
}
