/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:24 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	fp_arg_d_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	return (fp_num_sign((int)(data->i) >= 0, tags));
}

char	fp_arg_hd_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	return (fp_num_sign((short)(data->i) >= 0, tags));
}

char	fp_arg_hhd_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	return (fp_num_sign((char)(data->i) >= 0, tags));
}

char	fp_arg_ld_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	return (fp_num_sign((long)(data->i) >= 0, tags));
}

char	fp_arg_lld_sign(t_fp_arg_data *data, t_fp_tags *tags)
{
	return (fp_num_sign(data->i >= 0, tags));
}
