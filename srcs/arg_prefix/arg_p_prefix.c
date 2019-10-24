/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:13:19 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:13:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fp_arg_p_prefix(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	char *prefix
)
{
	(void)data;
	(void)tags;
	ft_strcpy(prefix, "0x");
}
