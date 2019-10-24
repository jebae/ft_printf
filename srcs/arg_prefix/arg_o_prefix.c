/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_o_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:16 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fp_arg_o_prefix(t_fp_arg_data *data, t_fp_tags *tags, char *prefix)
{
	if (data->i == 0)
		return ;
	if (tags->mask & FP_MASK_FLAG_SHARP)
		ft_strcpy(prefix, "0");
}
