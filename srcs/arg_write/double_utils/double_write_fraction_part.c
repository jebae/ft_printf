/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_write_fraction_part.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:46 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:47 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
