#include "ft_printf.h"

size_t		fp_arg_o_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned int)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned int)(data->i), 8));
}

size_t		fp_arg_ho_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned short)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned short)(data->i), 8));
}

size_t		fp_arg_hho_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned char)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned char)(data->i), 8));
}

size_t		fp_arg_lo_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned long)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned long)(data->i), 8));
}

size_t		fp_arg_llo_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned long long)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned long long)data->i, 8));
}
