/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_mem2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:39:42 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 15:03:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bi_expand_at_least(t_bigint *bi, size_t size)
{
	if (bi->size >= size)
		return (BI_SUCCESS);
	if (bi_expand(bi, size - bi->size) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}

int		bi_push(t_bigint *bi, unsigned char data)
{
	if (bi->size == bi->occupied)
	{
		if (bi_expand(bi, 1) == BI_FAIL)
			return (BI_FAIL);
	}
	bi->data[bi->occupied] = data;
	(bi->occupied)++;
	return (BI_SUCCESS);
}

int		bi_copy(t_bigint *dst, t_bigint *src)
{
	size_t	i;

	if (dst == src)
		return (BI_SUCCESS);
	if (bi_memalloc(dst, src->occupied) == BI_FAIL)
		return (BI_FAIL);
	dst->sign = src->sign;
	dst->occupied = src->occupied;
	i = 0;
	while (i < src->occupied)
	{
		dst->data[i] = src->data[i];
		i++;
	}
	return (BI_SUCCESS);
}

void	bi_update_occupied(t_bigint *bi)
{
	size_t		i;

	i = bi->size;
	while (i > 0 && bi->data[i - 1] == 0x00)
		i--;
	bi->occupied = i;
	if (bi->occupied == 0)
		bi->sign = BI_SIGN_POSITIVE;
}
