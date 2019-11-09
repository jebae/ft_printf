/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:31:38 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:31:38 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_extract_double(
	double num,
	short *exponent,
	unsigned long long *mantissa
)
{
	if (exponent == NULL || mantissa == NULL)
		return ;
	*mantissa = *((unsigned long long *)&num);
	*exponent = (*mantissa >> 52) & 0x7ff;
	*mantissa &= 0xfffffffffffff;
}

void		ft_extract_ldouble(
	long double num,
	short *exponent,
	unsigned long long *mantissa
)
{
	char		*ptr;

	if (exponent == NULL || mantissa == NULL)
		return ;
	ptr = (char *)&num;
	ft_memcpy(mantissa, ptr, 8);
	ft_memcpy(exponent, ptr + 8, 2);
	*exponent &= 0x7fff;
}
