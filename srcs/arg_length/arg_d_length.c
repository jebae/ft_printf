/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:12:51 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:12:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		fp_arg_d_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (int)data->i == 0)
		return (0);
	return (fp_int_length((int)(data->i), 10));
}

size_t		fp_arg_hd_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (short)data->i == 0)
		return (0);
	return (fp_int_length((short)(data->i), 10));
}

size_t		fp_arg_hhd_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (char)data->i == 0)
		return (0);
	return (fp_int_length((char)(data->i), 10));
}

size_t		fp_arg_ld_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (long)data->i == 0)
		return (0);
	return (fp_int_length((long)(data->i), 10));
}

size_t		fp_arg_lld_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (long long)data->i == 0)
		return (0);
	return (fp_int_length(data->i, 10));
}
