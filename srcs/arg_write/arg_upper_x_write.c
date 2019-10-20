#include "ft_printf.h"

void		fp_arg_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_upper_write((unsigned int)(data->i), length, 16, buf);
}

void		fp_arg_h_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_upper_write((unsigned short)(data->i), length, 16, buf);
}

void		fp_arg_hh_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_upper_write((unsigned char)(data->i), length, 16, buf);
}

void		fp_arg_l_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_upper_write((unsigned long)(data->i), length, 16, buf);
}

void		fp_arg_ll_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_upper_write((unsigned long long)data->i, length, 16, buf);
}
