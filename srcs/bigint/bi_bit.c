/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_bit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:45:41 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:45:46 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int			bi_get_bit(t_bigint *bi, size_t n)
{
	unsigned char	byte;

	if (bi->occupied == 0)
		return (0);
	if (bi_max_bit(bi) <= n)
		return (0);
	byte = bi->data[n / BI_UNIT_BITS];
	return ((byte >> (n % BI_UNIT_BITS)) & 0x1);
}

void		bi_set_bit(t_bigint *bi, size_t n, int value)
{
	unsigned char	*byte;

	if (value != 0 && value != 1)
		return ;
	if (bi->size * BI_UNIT_BITS <= n)
		return ;
	byte = bi->data + n / BI_UNIT_BITS;
	if (value & 1)
		*byte |= 1 << (n % BI_UNIT_BITS);
	else
		*byte &= ~(1 << (n % BI_UNIT_BITS));
	bi_update_occupied(bi);
}

size_t		bi_max_bit(t_bigint *bi)
{
	size_t			res;
	int				i;

	if (bi->occupied == 0)
		return (1);
	res = (bi->occupied - 1) * BI_UNIT_BITS;
	i = BI_UNIT_BITS;
	while (i > 0)
	{
		if (bi->data[bi->occupied - 1] & (1 << (i - 1)))
			return (res + i);
		i--;
	}
	return (res);
}
