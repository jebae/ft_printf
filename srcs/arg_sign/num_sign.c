/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:31 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:17:12 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		fp_num_sign(int positive, t_fp_tags *tags)
{
	if (positive)
	{
		if (tags->mask & FP_MASK_FLAG_PLUS)
			return ('+');
		else if (tags->mask & FP_MASK_FLAG_SPACE)
			return (' ');
		else
			return (FP_NO_SIGN);
	}
	return ('-');
}
