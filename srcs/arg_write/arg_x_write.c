#include "ft_printf.h"

void		fp_arg_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned int)(data->i), length, 16, buf);
}

void		fp_arg_hx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned short)(data->i), length, 16, buf);
}

void		fp_arg_hhx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned char)(data->i), length, 16, buf);
}

void		fp_arg_lx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned long)(data->i), length, 16, buf);
}

void		fp_arg_llx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned long long)data->i, length, 16, buf);
}
