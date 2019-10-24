/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_f_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:14:38 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:17:53 by jebae            ###   ########.fr       */
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

void			fp_arg_f_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(length);
	if (handle_inf_nan(data->f, buf))
		return ;
	fp_double_write(data->f, tags->precision, buf);
	if (tags->precision == 0 && (tags->mask & FP_MASK_FLAG_SHARP))
		fp_write_buffer(buf, '.');
}

void			fp_arg_lf_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
)
{
	(void)(length);
	if (handle_inf_nan(data->lf, buf))
		return ;
	fp_ldouble_write(data->lf, tags->precision, buf);
	if (tags->precision == 0 && (tags->mask & FP_MASK_FLAG_SHARP))
		fp_write_buffer(buf, '.');
}
