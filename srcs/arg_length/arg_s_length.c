/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_s_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:31:42 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:31:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	handle_null(t_fp_tags *tags)
{
	static size_t	len = 6;

	if ((tags->mask & FP_MASK_PRECISION) && tags->precision < len)
		return (tags->precision);
	return (len);
}

static size_t	ls_length_case_precision(
	wchar_t *str,
	size_t precision,
	char *utf8
)
{
	unsigned int	byte_len;
	size_t			len;

	len = 0;
	while (*str != 0)
	{
		ft_to_utf8(*str, utf8);
		byte_len = ft_utf8_byte_len(utf8);
		if (len > len + byte_len || len + byte_len > precision)
			return (len);
		len += byte_len;
		str++;
	}
	return (len);
}

size_t			fp_arg_s_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	size_t		len;
	char		*str;

	str = (char *)data->ptr;
	if (str == NULL)
		return (handle_null(tags));
	len = 0;
	while (*(str++) != '\0')
	{
		len++;
		if (len == FP_ULLONG_MAX)
			break ;
	}
	if ((tags->mask & FP_MASK_PRECISION) && tags->precision < len)
		return (tags->precision);
	return (len);
}

size_t			fp_arg_ls_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	unsigned int	byte_len;
	size_t			len;
	char			utf8[4];
	wchar_t			*str;

	str = (wchar_t *)data->ptr;
	if (str == NULL)
		return (handle_null(tags));
	if (tags->mask & FP_MASK_PRECISION)
		return (ls_length_case_precision(str, tags->precision, utf8));
	len = 0;
	while (*str != 0)
	{
		ft_to_utf8(*str, utf8);
		byte_len = ft_utf8_byte_len(utf8);
		if (len > len + byte_len)
			return (len);
		len += byte_len;
		str++;
	}
	return (len);
}
