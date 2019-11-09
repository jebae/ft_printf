/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_write_parts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:07:05 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:07:06 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		bcd_iter_f(unsigned char digit, void *arg)
{
	t_fp_buffer		*buf;

	buf = (t_fp_buffer *)arg;
	fp_write_buffer(buf, digit + '0');
}

void			fp_double_write_int_part(
	t_fixedpoint *int_part,
	t_fp_buffer *buf
)
{
	bcd_iter(&int_part->num, &bcd_iter_f, (void *)buf);
}

void			fp_double_write_fraction_part(
	t_fixedpoint *fraction_part,
	size_t precision,
	t_fp_buffer *buf
)
{
	long long		i;
	size_t			len;

	len = bcd_len(&fraction_part->num);
	i = fraction_part->e + (long long)len;
	while (precision && i < 0)
	{
		fp_write_buffer(buf, '0');
		i++;
		precision--;
	}
	while (precision && len--)
	{
		fp_write_buffer(buf, bcd_get_digit(&fraction_part->num, len) + '0');
		precision--;
	}
	while (precision--)
		fp_write_buffer(buf, '0');
}
