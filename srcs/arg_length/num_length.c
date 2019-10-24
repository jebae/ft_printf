/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:09 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			fp_int_length(long long num, int base)
{
	size_t		len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

size_t			fp_uint_length(unsigned long long num, int base)
{
	size_t		len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

size_t			fp_double_int_part_length(double num)
{
	size_t		len;

	if (num < 1.0 && num > -1.0)
		return (1);
	len = 0;
	while (!(num < 1.0 && num > -1.0))
	{
		num /= 10.0f;
		len++;
		if (ft_is_nan(num) || ft_is_inf(num))
			return (len);
	}
	return (len);
}

size_t			fp_ldouble_int_part_length(long double num)
{
	size_t		len;

	if (num < 1.0 && num > -1.0)
		return (1);
	len = 0;
	while (!(num < 1.0 && num > -1.0))
	{
		num /= 10.0L;
		len++;
		if (ft_is_nan(num) || ft_is_inf(num))
			return (len);
	}
	return (len);
}
