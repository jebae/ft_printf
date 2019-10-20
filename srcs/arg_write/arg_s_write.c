#include "ft_printf.h"

void		fp_arg_s_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	char	*str;
	size_t	precision;

	(void)length;
	str = (char *)data->ptr;
	if (tags->mask & FP_MASK_PRECISION)
	{
		precision = tags->precision;
		while (*str != '\0' && precision--)
		{
			fp_write_buffer(buf, *str);
			str++;
		}
		return ;
	}
	while (*str != '\0')
	{
		fp_write_buffer(buf, *str);
		str++;
	}
}
