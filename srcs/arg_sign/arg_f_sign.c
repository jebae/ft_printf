/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_f_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:27 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	fp_arg_f_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	if (ft_is_nan(data->f))
		return (FP_NO_SIGN);
	if (*((long long *)&data->f) & 0x8000000000000000)
		return ('-');
	return (fp_num_sign(data->f >= 0.0, tags));
}

char	fp_arg_lf_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	char	*ptr;

	if (ft_is_nan_l(data->lf))
		return (FP_NO_SIGN);
	ptr = ((char *)&data->lf) + 9;
	if (*ptr & 0x80)
		return ('-');
	return (fp_num_sign(data->lf >= 0.0, tags));
}
