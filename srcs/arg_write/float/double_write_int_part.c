#include "ft_printf.h"

static void		bcd_iter_f(unsigned char digit, void *arg)
{
	t_fp_buffer		*buf;

	buf = (t_fp_buffer *)arg;
	fp_write_buffer(buf, digit + '0');
}

void			fp_double_write_int_part(
	t_fixedpoint *int_part,
	t_fp_buffer *buf
)
{
	bcd_iter(&int_part->num, &bcd_iter_f, (void *)buf);
}