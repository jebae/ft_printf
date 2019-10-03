#include "ft_printf.h"

void		fp_arg_u_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned int)(data->i), length, buf);
}

void		fp_arg_hu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned short)(data->i), length, buf);
}

void		fp_arg_hhu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned char)(data->i), length, buf);
}

void		fp_arg_lu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned long)(data->i), length, buf);
}

void		fp_arg_llu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned long long)(data->i), length, buf);
}
