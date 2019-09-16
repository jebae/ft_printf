#include "ft_printf.h"

size_t		fp_arg_u_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned int)(data->i)));
}

size_t		fp_arg_hu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned short)(data->i)));
}

size_t		fp_arg_hhu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned char)(data->i)));
}

size_t		fp_arg_lu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned long)(data->i)));
}

size_t		fp_arg_llu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	(void)(tags);
	return (fp_uint_length((unsigned long long)(data->i)));
}
