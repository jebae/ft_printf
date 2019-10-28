/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_f_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:29:21 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:29:21 by jebae            ###   ########.fr       */
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

static void		f_write(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part,
	t_fp_tags *tags,
	t_fp_buffer *buf
)
{
	fp_double_write_int_part(int_part, buf);
	if (tags->precision == 0)
	{
		if (tags->mask & FP_MASK_FLAG_SHARP)
			fp_write_buffer(buf, '.');
		return ;
	}
	fp_write_buffer(buf, '.');
	fp_double_write_fraction_part(fraction_part, tags->precision, buf);
}

void			fp_arg_f_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(length);
	if (handle_inf_nan(data->f.float64, buf))
		return ;
	f_write(&data->f.int_part, &data->f.fraction_part, tags, buf);
}

void			fp_arg_lf_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(length);
	if (handle_inf_nan(data->f.float128, buf))
		return ;
	f_write(&data->f.int_part, &data->f.fraction_part, tags, buf);
}
