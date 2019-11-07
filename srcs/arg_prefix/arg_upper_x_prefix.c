/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_upper_x_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:41:26 by jebae             #+#    #+#             */
/*   Updated: 2019/11/07 16:05:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fp_arg_upper_x_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned int)data->i, tags, 1, prefix);
}

void			fp_arg_upper_hx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned short)data->i, tags, 1, prefix);
}

void			fp_arg_upper_hhx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned char)data->i, tags, 1, prefix);
}

void			fp_arg_upper_lx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned long)data->i, tags, 1, prefix);
}

void			fp_arg_upper_llx_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	(void)length;
	write_hex_prefix((unsigned long long)data->i, tags, 1, prefix);
}
