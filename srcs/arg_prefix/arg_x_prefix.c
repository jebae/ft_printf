/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_x_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:21 by jebae             #+#    #+#             */
/*   Updated: 2019/11/07 17:37:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fp_arg_x_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned int)data->i, tags, 0, prefix);
}

void			fp_arg_hx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned short)data->i, tags, 0, prefix);
}

void			fp_arg_hhx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned char)data->i, tags, 0, prefix);
}

void			fp_arg_lx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned long)data->i, tags, 0, prefix);
}

void			fp_arg_llx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned long long)data->i, tags, 0, prefix);
}
