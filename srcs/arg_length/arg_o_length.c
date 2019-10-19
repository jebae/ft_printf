#include "ft_printf.h"

size_t		fp_arg_o_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned int)(data->i), 8));
}

size_t		fp_arg_ho_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned short)(data->i), 8));
}

size_t		fp_arg_hho_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned char)(data->i), 8));
}

size_t		fp_arg_lo_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned long)(data->i), 8));
}

size_t		fp_arg_llo_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned long long)data->i, 8));
}
