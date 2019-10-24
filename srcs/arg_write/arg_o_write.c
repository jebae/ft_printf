/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_o_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:14:41 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:14:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fp_arg_o_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned int)(data->i), length, 8, buf);
}

void		fp_arg_ho_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned short)(data->i), length, 8, buf);
}

void		fp_arg_hho_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned char)(data->i), length, 8, buf);
}

void		fp_arg_lo_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned long)(data->i), length, 8, buf);
}

void		fp_arg_llo_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_uint_write((unsigned long long)data->i, length, 8, buf);
}
