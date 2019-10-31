/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:32:54 by jebae             #+#    #+#             */
/*   Updated: 2019/10/31 16:07:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_tags_and_arg(t_fp_tags *tags, t_fp_arg *arg)
{
	fp_init_tags(tags);
	arg->length = NULL;
	arg->sign = NULL;
	arg->write = NULL;
	fxp_init(&arg->data.f.int_part);
	fxp_init(&arg->data.f.fraction_part);
}

static void		del_arg(t_fp_arg *arg)
{
	fxp_del(&arg->data.f.int_part);
	fxp_del(&arg->data.f.fraction_part);
}

static int		check_error(size_t written, size_t width, int *error)
{
	if (written + width >= FP_INT_MAX)
		*error = 1;
	return (*error);
}

size_t			fp_parse_percent(
	const char *format,
	va_list ap,
	t_fp_buffer *buf,
	int *error
)
{
	size_t		i;
	size_t		j;
	t_fp_arg	arg;
	t_fp_tags	tags;

	if (format == NULL || *format != '%')
		return (0);
	i = 1;
	init_tags_and_arg(&tags, &arg);
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
	if (check_error(buf->written, tags.width, error))
		return (0);
	if ((j = fp_parse_specifier(format + i, ap, &tags, &arg)))
		fp_write_percent_format(&arg, &tags, buf);
	del_arg(&arg);
	return (i + j);
}
