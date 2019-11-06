/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:16:09 by jebae             #+#    #+#             */
/*   Updated: 2019/11/06 15:54:55 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		handle_asterisk(va_list ap, t_fp_tags *tags)
{
	int			extra_arg;

	extra_arg = va_arg(ap, int);
	if (extra_arg >= 0)
	{
		tags->mask |= FP_MASK_PRECISION;
		tags->precision = extra_arg;
	}
	return (2);
}

size_t				fp_parse_precision(
	const char *format,
	va_list ap,
	t_fp_tags *tags
)
{
	size_t		i;

	if (format[0] != '.')
		return (0);
	i = 1;
	if (format[i] == '*')
		return (handle_asterisk(ap, tags));
	else
	{
		tags->mask |= FP_MASK_PRECISION;
		tags->precision = 0;
		while (ft_isdigit(format[i]))
		{
			tags->precision *= 10;
			tags->precision += format[i] - '0';
			i++;
		}
		return (i);
	}
}
