/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_u_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:03 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:04 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		fp_arg_u_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned int)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned int)(data->i), 10));
}

size_t		fp_arg_hu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned short)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned short)(data->i), 10));
}

size_t		fp_arg_hhu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned char)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned char)(data->i), 10));
}

size_t		fp_arg_lu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned long)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned long)(data->i), 10));
}

size_t		fp_arg_llu_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (tags->precision == 0 && (unsigned long long)data->i == 0)
		return (0);
	return (fp_uint_length((unsigned long long)(data->i), 10));
}
