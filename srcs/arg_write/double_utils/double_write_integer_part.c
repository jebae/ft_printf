/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_write_integer_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:49 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:49 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		bcd_iter_f(unsigned char digit, void *arg)
{
	t_fp_buffer		*buf;

	buf = (t_fp_buffer *)arg;
	fp_write_buffer(buf, digit + '0');
}

void			fp_double_write_integer_part(
	t_fixedpoint *int_part,
	t_fp_buffer *buf
)
{
	bcd_iter(&int_part->num, &bcd_iter_f, (void *)buf);
}
