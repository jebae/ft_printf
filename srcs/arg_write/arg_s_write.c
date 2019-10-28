/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_s_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:34:19 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:34:36 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void		ls_write_case_precision(
	wchar_t *str,
	size_t precision,
	char *utf8,
	t_fp_buffer *buf
)
{
	unsigned int	i;
	unsigned int	byte_len;
	size_t			len;

	len = 0;
	while (*str != 0)
	{
		ft_to_utf8(*str, utf8);
		byte_len = ft_utf8_byte_len(utf8);
		if (len + byte_len > precision)
			return ;
		i = 0;
		while (i < byte_len)
			fp_write_buffer(buf, utf8[i++]);
		len += byte_len;
		str++;
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
	if (str == NULL)
		return (handle_null(tags->precision, buf));
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

void			fp_arg_ls_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	char			utf8[4];
	unsigned int	i;
	unsigned int	byte_len;
	wchar_t			*str;

	(void)length;
	str = (wchar_t *)data->ptr;
	if (str == NULL)
		return (handle_null(tags->precision, buf));
	if (tags->mask & FP_MASK_PRECISION)
		return (ls_write_case_precision(str, tags->precision, utf8, buf));
	while (*str != 0)
	{
		ft_to_utf8(*str, utf8);
		byte_len = ft_utf8_byte_len(utf8);
		i = 0;
		while (i < byte_len)
			fp_write_buffer(buf, utf8[i++]);
		str++;
	}
}
