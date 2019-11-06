/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_percent_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:33:43 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:33:44 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_percent_format_vars(
	t_fp_arg *arg,
	t_fp_tags *tags,
	t_fp_percent_format_vars *v
)
{
	ft_bzero(v->prefix, 2);
	v->sign = arg->sign(&arg->data, tags);
	v->content_len = arg->length(&arg->data, tags);
	arg->prefix(&arg->data, tags, v->content_len, v->prefix);
	v->leading_zero = arg->leading_zero(tags, v->content_len);
	v->total_len = v->content_len +
		((v->sign == FP_NO_SIGN) ? 0 : 1) +
		ft_strlen(v->prefix) + v->leading_zero;
	if (v->total_len < v->content_len)
		v->total_len = FP_ULLONG_MAX;
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

static void		write_content(
	t_fp_arg *arg,
	t_fp_tags *tags,
	t_fp_percent_format_vars *v,
	t_fp_buffer *buf
)
{
	while (v->leading_zero)
	{
		fp_write_buffer(buf, '0');
		(v->leading_zero)--;
	}
	arg->write(&arg->data, tags, v->content_len, buf);
}

void			fp_write_percent_format(
	t_fp_arg *arg,
	t_fp_tags *tags,
	t_fp_buffer *buf
)
{
	t_fp_percent_format_vars	v;

	set_percent_format_vars(arg, tags, &v);
	if (tags->mask & FP_MASK_FLAG_MINUS)
	{
		write_sign_prefix(v.sign, v.prefix, buf);
		write_content(arg, tags, &v, buf);
		write_padding(tags, v.total_len, ' ', buf);
		return ;
	}
	else if ((tags->mask & FP_MASK_FLAG_ZERO))
	{
		write_sign_prefix(v.sign, v.prefix, buf);
		write_padding(tags, v.total_len, '0', buf);
		write_content(arg, tags, &v, buf);
		return ;
	}
	write_padding(tags, v.total_len, ' ', buf);
	write_sign_prefix(v.sign, v.prefix, buf);
	write_content(arg, tags, &v, buf);
}
