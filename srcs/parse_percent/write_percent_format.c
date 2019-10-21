#include "ft_printf.h"

static void		get_sign_prefix(
	t_fp_arg *arg,
	t_fp_tags *tags,
	char *sign,
	char *prefix
)
{
	ft_bzero(prefix, 2);
	*sign = arg->sign(&arg->data, tags);
	arg->prefix(&arg->data, tags, prefix);
}

static size_t	get_total_length(
	size_t content_len,
	char sign,
	char *prefix
)
{
	size_t		total_len;

	total_len = content_len +
		((sign == FP_NO_SIGN) ? 0 : 1) + ft_strlen(prefix);
	if (total_len < content_len)
		total_len = FP_ULLONG_MAX;
	return (total_len);
}

static void		write_sign_prefix(char sign, char *prefix, t_fp_buffer *buf)
{
	if (sign != FP_NO_SIGN)
		fp_write_buffer(buf, sign);
	while (*prefix != '\0')
	{
		fp_write_buffer(buf, *prefix);
		prefix++;
	}
}

static void		write_padding(
	t_fp_tags *tags,
	size_t total_len,
	char pad,
	t_fp_buffer *buf
)
{
	size_t	len;

	if (tags->width <= total_len)
		return ;
	len = tags->width - total_len;
	while (len--)
		fp_write_buffer(buf, pad);
}

void			fp_write_percent_format(
	t_fp_arg *arg,
	t_fp_tags *tags,
	t_fp_buffer *buf
)
{
	char		sign;
	char		prefix[2];
	size_t		content_len;
	size_t		total_len;

	get_sign_prefix(arg, tags, &sign, prefix);
	content_len = arg->length(&arg->data, tags);
	total_len = get_total_length(content_len, sign, prefix);
	if (tags->mask & FP_MASK_FLAG_MINUS)
	{
		write_sign_prefix(sign, prefix, buf);
		arg->write(&arg->data, tags, content_len, buf);
		write_padding(tags, total_len, ' ', buf);
		return ;
	}
	else if ((tags->mask & FP_MASK_FLAG_ZERO))
	{
		write_sign_prefix(sign, prefix, buf);
		write_padding(tags, total_len, '0', buf);
		arg->write(&arg->data, tags, content_len, buf);
		return ;
	}
	write_padding(tags, total_len, ' ', buf);
	write_sign_prefix(sign, prefix, buf);
	arg->write(&arg->data, tags, content_len, buf);
}
