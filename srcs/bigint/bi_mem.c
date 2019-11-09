/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:38:19 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:38:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void	bi_del(t_bigint *bi)
{
	ft_memdel((void **)&bi->data);
	bi_init(bi);
}

int		bi_memalloc(t_bigint *bi, size_t size)
{
	if (bi->data != NULL && bi->size >= size)
	{
		bi_erase(bi);
		return (BI_SUCCESS);
	}
	bi_del(bi);
	if (size == 0)
		return (BI_SUCCESS);
	if ((bi->data = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	bi->size = size;
	return (BI_SUCCESS);
}

void	bi_init(t_bigint *bi)
{
	bi->data = NULL;
	bi->sign = BI_SIGN_POSITIVE;
	bi->size = 0;
	bi->occupied = 0;
}

void	bi_erase(t_bigint *bi)
{
	ft_bzero(bi->data, bi->occupied);
	bi->occupied = 0;
}

int		bi_expand(t_bigint *bi, size_t size)
{
	unsigned char	*temp;

	if (size == 0)
		return (BI_SUCCESS);
	if ((temp = ft_memalloc(bi->size + size)) == NULL)
		return (BI_FAIL);
	ft_memcpy(temp, bi->data, bi->occupied);
	ft_memdel((void **)&bi->data);
	bi->data = temp;
	bi->size += size;
	return (BI_SUCCESS);
}
