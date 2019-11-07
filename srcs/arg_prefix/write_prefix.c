/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:50:24 by jebae             #+#    #+#             */
/*   Updated: 2019/11/07 15:50:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_hex_prefix(
	unsigned long long num,
	t_fp_tags *tags,
	int is_upper,
	char *prefix
)
{
	if (num == 0)
		return ;
	if (tags->mask & FP_MASK_FLAG_SHARP)
	{
		if (is_upper)
			ft_strcpy(prefix, "0X");
		else
			ft_strcpy(prefix, "0x");
	}
}

void		write_octal_prefix(
	unsigned long long num,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	if (num == 0 && length == 1)
		return ;
	if (tags->mask & FP_MASK_FLAG_SHARP)
	{
		if ((tags->mask & FP_MASK_PRECISION) &&
			tags->precision > length)
			return ;
		ft_strcpy(prefix, "0");
	}
}
