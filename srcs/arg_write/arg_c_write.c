#include "ft_printf.h"

void		fp_arg_c_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)tags;
	(void)length;
	fp_write_buffer(buf, (char)data->i);
}
