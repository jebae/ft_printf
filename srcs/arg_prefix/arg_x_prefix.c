/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_x_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:21 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	int is_upper,
	char *prefix
)
{
	if (data->i == 0)
		return ;
	if (tags->mask & FP_MASK_FLAG_SHARP)
	{
		if (is_upper)
			ft_strcpy(prefix, "0X");
		else
			ft_strcpy(prefix, "0x");
	}
}

void			fp_arg_x_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	char *prefix
)
{
	write_prefix(data, tags, 0, prefix);
}

void			fp_arg_upper_x_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	char *prefix
)
{
	write_prefix(data, tags, 1, prefix);
}
