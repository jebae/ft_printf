/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_f_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:28:28 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:28:29 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	f_length(t_fp_tags *tags, t_fixedpoint *int_part)
{
	size_t	len;

	len = tags->precision;
	if (tags->precision > 0 || (tags->mask & FP_MASK_FLAG_SHARP))
		len++;
	return (bcd_len(&int_part->num) + len);
}

size_t			fp_arg_f_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (ft_is_nan(data->f.float64) || ft_is_inf(data->f.float64))
		return (3);
	return (f_length(tags, &data->f.int_part));
}

size_t			fp_arg_lf_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (ft_is_nan_l(data->f.float128) || ft_is_inf_l(data->f.float128))
		return (3);
	return (f_length(tags, &data->f.int_part));
}
