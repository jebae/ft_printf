#include "ft_printf.h"

void		fp_write_sign(char sign, t_fp_buffer *buf)
{
	if (sign == FP_NO_SIGN)
		return ;
	fp_write_buffer(buf, sign);
}

void		fp_write_padding(
	t_fp_tags *tags,
	size_t content_length,
	char pad,
	t_fp_buffer *buf
)
{
	size_t	length;

	if (tags->width <= content_length)
		return ;
	length = tags->width - content_length;
	while (length--)
		fp_write_buffer(buf, pad);
}

void		fp_write_percent_format(
	t_fp_arg *arg,
	t_fp_tags *tags,
	t_fp_buffer *buf
)
{
	char		sign;
	size_t		len;

	len = arg->length(&(arg->data), tags);
	sign = arg->sign(&(arg->data), tags);
	if (tags->mask & FP_MASK_FLAG_MINUS)
	{
		fp_write_sign(sign, buf);
		arg->write(&arg->data, tags, len, buf);
		fp_write_padding(tags, (sign == FP_NO_SIGN) ? len : len + 1, ' ', buf);
		return ;
	}
	if ((tags->mask & FP_MASK_FLAG_ZERO) &&
		!(tags->mask & FP_MASK_IGNORE_ZERO_PAD))
	{
		fp_write_sign(sign, buf);
		fp_write_padding(tags, (sign == FP_NO_SIGN) ? len : len + 1, '0', buf);
	}
	else
	{
		fp_write_padding(tags, (sign == FP_NO_SIGN) ? len : len + 1, ' ', buf);
		fp_write_sign(sign, buf);
	}
	arg->write(&arg->data, tags, len, buf);
}
