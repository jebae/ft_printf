#include "ft_printf.h"

static void		handle_null(size_t precision, t_fp_buffer *buf)
{
	static char		*null_expr = "(null)";
	int				i;

	i = 0;
	while (null_expr[i] != '\0' && precision--)
	{
		fp_write_buffer(buf, null_expr[i]);
		i++;
	}
}

void			fp_arg_s_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	char			*str;
	size_t			precision;

	(void)length;
	str = (char *)data->ptr;
	precision = tags->precision;
	if (str == NULL)
		return (handle_null(precision, buf));
	if (tags->mask & FP_MASK_PRECISION)
	{
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
