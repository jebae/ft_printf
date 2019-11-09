/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:26:08 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:26:08 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_empty(int empty, char *utf8)
{
	int		i;

	i = 0;
	while (i < empty)
	{
		utf8[3 - i] = 0x00;
		i++;
	}
}

static void		fill_bits(int empty, wchar_t wch, char *utf8)
{
	int		i;

	if (empty == 4)
		return ;
	if (empty == 3)
	{
		utf8[0] = wch;
		return ;
	}
	i = 3 - empty;
	while (i > 0)
	{
		utf8[i] = (wch & 0x3f) | 0x80;
		wch >>= 6;
		i--;
	}
	utf8[0] |= wch & (0x1f >> (2 - empty));
}

void			ft_to_utf8(wchar_t wch, char *utf8)
{
	int		empty;

	if (utf8 == NULL)
		return ;
	empty = 4;
	if (wch > 0x00000000)
		empty--;
	if (wch > 0x0000007f && empty--)
		utf8[0] = 0xc0;
	if (wch > 0x000007ff && empty--)
		utf8[0] = 0xe0;
	if (wch > 0x0000ffff && empty--)
		utf8[0] = 0xf0;
	fill_empty(empty, utf8);
	fill_bits(empty, wch, utf8);
}

int				ft_utf8_byte_len(char *utf8)
{
	unsigned char	ch;

	if (utf8 == NULL)
		return (0);
	ch = utf8[0];
	if ((ch >> 5) == 0x06)
		return (2);
	else if ((ch >> 4) == 0x0e)
		return (3);
	else if ((ch >> 3) == 0x1e)
		return (4);
	else
		return (1);
}
