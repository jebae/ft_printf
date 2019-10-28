/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_e_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:28:23 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:31:11 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	e_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	size_t		len;
	int			exponent;

	len = 1 + tags->precision + 2 + 2;
	if (tags->precision > 0 || (tags->mask & FP_MASK_FLAG_SHARP))
		len++;
	exponent = fp_get_scientific_exponent(
		&data->f.int_part, &data->f.fraction_part);
	exponent /= 100;
	while (exponent != 0)
	{
		len++;
		exponent /= 10;
	}
	return (len);
}

size_t			fp_arg_e_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (ft_is_nan(data->f.float64) || ft_is_inf(data->f.float64))
		return (3);
	return (e_length(data, tags));
}

size_t			fp_arg_le_length(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (ft_is_nan_l(data->f.float128) || ft_is_inf_l(data->f.float128))
		return (3);
	return (e_length(data, tags));
}
