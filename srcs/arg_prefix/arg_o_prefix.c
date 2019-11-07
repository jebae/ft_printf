/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_o_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:16 by jebae             #+#    #+#             */
/*   Updated: 2019/11/07 17:37:15 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fp_arg_o_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	write_octal_prefix((unsigned int)data->i, tags, length, prefix);
}

void	fp_arg_ho_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	write_octal_prefix((unsigned short)data->i, tags, length, prefix);
}

void	fp_arg_hho_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	write_octal_prefix((unsigned char)data->i, tags, length, prefix);
}

void	fp_arg_lo_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	write_octal_prefix((unsigned long)data->i, tags, length, prefix);
}

void	fp_arg_llo_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	char *prefix
)
{
	write_octal_prefix((unsigned long long)data->i, tags, length, prefix);
}
