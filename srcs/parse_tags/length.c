/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:16:06 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:16:07 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		fp_parse_length(const char *format, t_fp_tags *tags)
{
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
		{
			tags->mask |= FP_MASK_LENGTH_HH;
			return (2);
		}
		tags->mask |= FP_MASK_LENGTH_H;
	}
	else if (*format == 'l')
	{
		if (*(format + 1) == 'l')
		{
			tags->mask |= FP_MASK_LENGTH_LL;
			return (2);
		}
		tags->mask |= FP_MASK_LENGTH_L;
	}
	else if (*format == 'L')
		tags->mask |= FP_MASK_LENGTH_FL;
	else
		return (0);
	return (1);
}
