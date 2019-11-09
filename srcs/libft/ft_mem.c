/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:20:37 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:28:18 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

void	ft_memdel(void **ap)
{
	if (ap == NULL || *ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL || src == NULL)
		return (dst);
	while (n-- > 0)
		((unsigned char *)dst)[n] = ((const unsigned char *)src)[n];
	return (dst);
}

void	ft_memnegate(unsigned char *mem, size_t size)
{
	size_t			i;
	unsigned char	carry;
	unsigned short	added;

	i = 0;
	while (i < size)
	{
		mem[i] = ~(mem[i]);
		i++;
	}
	i = 0;
	carry = 0x01;
	while (i < size)
	{
		added = (unsigned short)(mem[i]) + carry;
		carry = added >> 8;
		mem[i] = (unsigned char)added;
		i++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len-- != 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}
