/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:02:53 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 15:02:54 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long				ft_powd(long long num, size_t e)
{
	size_t		i;
	long long	res;

	if (e == 0)
		return (1);
	res = num;
	i = 1;
	while (i < e)
	{
		res *= num;
		i++;
	}
	return (res);
}

unsigned long long		ft_powud(unsigned long long num, size_t e)
{
	size_t				i;
	unsigned long long	res;

	if (e == 0)
		return (1);
	res = num;
	i = 1;
	while (i < e)
	{
		res *= num;
		i++;
	}
	return (res);
}

long long				ft_min_int(long long a, long long b)
{
	return ((a > b) ? b : a);
}

long long				ft_max_int(long long a, long long b)
{
	return ((a < b) ? b : a);
}
