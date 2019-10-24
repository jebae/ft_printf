/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:15:08 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:15:09 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_lower_digit(int n)
{
	static char		*digits = "0123456789abcdef";

	return (digits[n]);
}

static int		get_upper_digit(int n)
{
	static char		*digits = "0123456789ABCDEF";

	return (digits[n]);
}

void			fp_int_write(
	long long num,
	size_t length,
	t_fp_buffer *buf
)
{
	long long		divider;
	char			ch;

	if (length == 0)
		return ;
	if (num == 0)
	{
		fp_write_buffer(buf, '0');
		return ;
	}
	divider = ft_powd(10, length - 1);
	while (divider != 0)
	{
		ch = num / divider % 10;
		if (ch < 0)
			ch = -ch;
		fp_write_buffer(buf, '0' + ch);
		divider /= 10;
	}
}

void			fp_uint_write(
	unsigned long long num,
	size_t length,
	int base,
	t_fp_buffer *buf
)
{
	unsigned long long		divider;

	if (length == 0)
		return ;
	if (num == 0)
	{
		fp_write_buffer(buf, '0');
		return ;
	}
	divider = ft_powud(base, length - 1);
	while (divider != 0)
	{
		fp_write_buffer(buf, get_lower_digit(num / divider % base));
		divider /= base;
	}
}

void			fp_uint_upper_write(
	unsigned long long num,
	size_t length,
	int base,
	t_fp_buffer *buf
)
{
	unsigned long long		divider;

	if (length == 0)
		return ;
	if (num == 0)
	{
		fp_write_buffer(buf, '0');
		return ;
	}
	divider = ft_powud(base, length - 1);
	while (divider != 0)
	{
		fp_write_buffer(buf, get_upper_digit(num / divider % base));
		divider /= base;
	}
}
