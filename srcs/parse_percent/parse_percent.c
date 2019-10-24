/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:15:34 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:15:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_arg(t_fp_arg *arg)
{
	arg->length = NULL;
	arg->sign = NULL;
	arg->write = NULL;
	ft_memset(&arg->data, 0, sizeof(t_fp_arg_data));
}

size_t			fp_parse_percent(
	const char *format,
	va_list ap,
	t_fp_buffer *buf
)
{
	size_t		i;
	size_t		j;
	t_fp_arg	arg;
	t_fp_tags	tags;

	if (format == NULL || *format != '%')
		return (0);
	i = 1;
	fp_init_tags(&tags);
	init_arg(&arg);
	j = 1;
	while (j != 0)
	{
		j = 0;
		j += fp_parse_flag(format + i, &tags);
		j += fp_parse_width(format + i + j, &tags);
		j += fp_parse_precision(format + i + j, &tags);
		j += fp_parse_length(format + i + j, &tags);
		i += j;
	}
	j = fp_parse_specifier(format + i, ap, &tags, &arg);
	if (j)
		fp_write_percent_format(&arg, &tags, buf);
	return (i + j);
}
