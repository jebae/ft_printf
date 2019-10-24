/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:14:36 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:14:37 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fp_arg_d_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_int_write((int)(data->i), length, buf);
}

void		fp_arg_hd_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_int_write((short)(data->i), length, buf);
}

void		fp_arg_hhd_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_int_write((char)(data->i), length, buf);
}

void		fp_arg_ld_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_int_write((long)(data->i), length, buf);
}

void		fp_arg_lld_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(tags);
	fp_int_write(data->i, length, buf);
}
