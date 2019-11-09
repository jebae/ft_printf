/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_nan_inf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:30:41 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:30:41 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_inf(double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_double(num, &exponent, &mantissa);
	if (exponent == 0x7ff && mantissa == 0)
		return (1);
	return (0);
}

int		ft_is_inf_l(long double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_ldouble(num, &exponent, &mantissa);
	if (exponent != 0x7fff)
		return (0);
	if (mantissa == 0 || mantissa == 0x8000000000000000)
		return (1);
	return (0);
}

int		ft_is_nan(double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_double(num, &exponent, &mantissa);
	if (exponent == 0x7ff && (mantissa == 1 ||
		mantissa == 0x8000000000001 || mantissa == 0x8000000000000))
		return (1);
	return (0);
}

int		ft_is_nan_l(long double num)
{
	char				d;
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_ldouble(num, &exponent, &mantissa);
	if (exponent != 0x7fff)
		return (0);
	d = mantissa >> 62;
	mantissa &= ~0xc000000000000000;
	if (d == 1 || d == 3)
		return (1);
	if (d == 0 && mantissa != 0)
		return (1);
	if (d == 2 && mantissa != 0)
		return (1);
	return (0);
}
