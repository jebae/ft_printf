#include "ft_printf.h"

void		fp_arg_f_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(length);
	fp_double_write(data->f, tags->precision, buf);
}

void		fp_arg_lf_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(length);
	fp_ldouble_write(data->lf, tags->precision, buf);
}
