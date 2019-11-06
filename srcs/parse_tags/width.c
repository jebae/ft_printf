/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:16:12 by jebae             #+#    #+#             */
/*   Updated: 2019/11/06 16:20:03 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		handle_asterisk(va_list ap, t_fp_tags *tags)
{
	int			extra_arg;

	extra_arg = va_arg(ap, int);
	if (extra_arg >= 0)
		tags->width = extra_arg;
	else
	{
		tags->width = -extra_arg;
		tags->mask |= FP_MASK_FLAG_MINUS;
	}
	return (1);
}

size_t				fp_parse_width(
	const char *format,
	va_list ap,
	t_fp_tags *tags
)
{
	size_t		i;

	if (format[0] == '*')
		return (handle_asterisk(ap, tags));
	else if (ft_isdigit(format[0]) && format[0] != '0')
	{
		tags->width = 0;
		i = 0;
		while (ft_isdigit(format[i]))
		{
			tags->width *= 10;
			tags->width += format[i] - '0';
			i++;
		}
		return (i);
	}
	return (0);
}
