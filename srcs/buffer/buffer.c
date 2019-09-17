#include "ft_printf.h"

void		fp_init_buffer(t_fp_buffer *buf)
{
	buf->i = -1;
	ft_bzero(buf->data, FP_BUFFER_SIZE);
}

void		fp_write_buffer(t_fp_buffer *buf, char value)
{
	if (buf->i == FP_BUFFER_SIZE - 1)
		fp_flush_buffer(buf);
	buf->data[++(buf->i)] = value;
}

void		fp_flush_buffer(t_fp_buffer *buf)
{
	if (buf->i < 0)
		return ;
	write(FP_OUTPUT, buf->data, buf->i + 1);
	ft_bzero(buf->data, buf->i + 1);
	buf->i = -1;
}
