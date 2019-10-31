/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:16:15 by jebae             #+#    #+#             */
/*   Updated: 2019/10/31 16:09:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_str(const char *format, t_fp_buffer *buf)
{
	int		i;

	i = 0;
	while (*(format + i) != '\0' && *(format + i) != '%')
	{
		fp_write_buffer(buf, *(format + i));
		i++;
		if (i == FP_INT_MAX)
			return (i);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_fp_buffer		buf;
	int				error;

	error = 0;
	fp_init_buffer(&buf);
	va_start(ap, format);
	if (format == NULL)
		return (0);
	while (*format != '\0')
	{
		format += fp_parse_percent(format, ap, &buf, &error);
		if (error)
		{
			va_end(ap);
			return (FP_ERROR);
		}
		format += parse_str(format, &buf);
	}
	fp_flush_buffer(&buf);
	va_end(ap);
	return (buf.written);
}
