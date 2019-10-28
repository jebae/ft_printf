/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_e_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:29:00 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:29:01 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		handle_inf_nan(
	long double num,
	t_fp_buffer *buf
)
{
	static char		*inf = "inf";
	static char		*nan = "nan";
	char			*word;
	int				i;

	word = NULL;
	if (ft_is_inf_l(num))
		word = inf;
	else if (ft_is_nan_l(num))
		word = nan;
	else
		return (0);
	i = 0;
	while (i < 3)
	{
		fp_write_buffer(buf, word[i]);
		i++;
	}
	return (1);
}

void			fp_arg_e_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)length;
	if (handle_inf_nan(data->f.float64, buf))
		return ;
	fp_double_write_scientific_parts(
		&data->f.int_part, &data->f.fraction_part, tags, buf);
}

void			fp_arg_le_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)length;
	if (handle_inf_nan(data->f.float128, buf))
		return ;
	fp_double_write_scientific_parts(
		&data->f.int_part, &data->f.fraction_part, tags, buf);
}
