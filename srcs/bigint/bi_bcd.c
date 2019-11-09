/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_bcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:49:52 by jebae             #+#    #+#             */
/*   Updated: 2019/11/09 14:49:54 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

size_t				bcd_len(t_bigint *bcd)
{
	if (bcd->occupied == 0)
		return (1);
	if (bcd->data[bcd->occupied - 1] & 0xf0)
		return (bcd->occupied * 2);
	return (bcd->occupied * 2 - 1);
}

unsigned char		bcd_get_digit(t_bigint *bcd, size_t n)
{
	unsigned char	byte;

	if (bcd->occupied * 2 < n + 1)
		return (0);
	byte = bcd->data[n / 2];
	if (n & 1)
		return (byte >> 4);
	return (byte & 0x0f);
}

void				bcd_set_digit(t_bigint *bcd, size_t n, unsigned char val)
{
	unsigned char	*byte;

	if (bcd->size * 2 < n + 1 || val > 9)
		return ;
	byte = bcd->data + n / 2;
	if (n & 1)
	{
		*byte = (*byte & 0x0f) | (val << 4);
		return ;
	}
	*byte = (*byte & 0xf0) | val;
}

size_t				bcd_rm_trailing_zero(t_bigint *bcd)
{
	size_t		n;
	size_t		i;

	n = 0;
	i = 0;
	while (i < bcd->occupied && (bcd->data[i] & 0x0f) == 0)
	{
		n += 1;
		if (bcd->data[i] != 0)
			break ;
		n += 1;
		i++;
	}
	if (n)
		bi_right_shift(bcd, 4 * n, bcd);
	return (n);
}

void				bcd_iter(
	t_bigint *bcd,
	void (*f)(unsigned char, void *),
	void *arg
)
{
	size_t	len;

	len = bcd_len(bcd);
	while (len > 0)
		f(bcd_get_digit(bcd, --len), arg);
}
