#include "ft_printf.h"

void		fp_int_write(
	long long num,
	size_t length,
	t_fp_buffer *buf
)
{
	long long		divider;

	if (num == 0)
	{
		fp_write_buffer(buf, '0');
		return ;
	}
	divider = ft_powd(10, length - 1);
	while (divider != 0)
	{
		fp_write_buffer(buf, '0' + ABS(num / divider % 10));
		divider /= 10;
	}
}

void		fp_uint_write(
	unsigned long long num,
	size_t length,
	t_fp_buffer *buf
)
{
	unsigned long long		divider;

	if (num == 0)
	{
		fp_write_buffer(buf, '0');
		return ;
	}
	divider = ft_powd(10, length - 1);
	while (divider != 0)
	{
		fp_write_buffer(buf, '0' + num / divider % 10);
		divider /= 10;
	}
}
