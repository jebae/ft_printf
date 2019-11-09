/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:26:18 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:26:19 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcpy(char *dst, const char *src)
{
	char	*p_dst;

	if (dst == NULL || src == NULL)
		return (dst);
	p_dst = dst;
	while (*src != '\0')
		*(p_dst++) = *(src++);
	*p_dst = *src;
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while (*(str++) != '\0')
		len++;
	return (len);
}
