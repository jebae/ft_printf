/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:16:01 by jebae             #+#    #+#             */
/*   Updated: 2019/11/06 15:04:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		case_extra(char ch)
{
	static char		*extras = ",':;_";
	int				i;

	i = 0;
	while (i < 5)
	{
		if (ch == extras[i])
			return (1);
		i++;
	}
	return (0);
}

size_t			fp_parse_flag(const char *format, t_fp_tags *tags)
{
	if (*format == '-')
		tags->mask |= FP_MASK_FLAG_MINUS;
	else if (*format == '+')
		tags->mask |= FP_MASK_FLAG_PLUS;
	else if (*format == ' ')
		tags->mask |= FP_MASK_FLAG_SPACE;
	else if (*format == '0')
		tags->mask |= FP_MASK_FLAG_ZERO;
	else if (*format == '#')
		tags->mask |= FP_MASK_FLAG_SHARP;
	else
		return (case_extra(*format));
	return (1);
}
