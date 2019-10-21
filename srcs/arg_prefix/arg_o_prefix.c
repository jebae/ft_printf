#include "ft_printf.h"

void	fp_arg_o_prefix(t_fp_arg_data *data, t_fp_tags *tags, char *prefix)
{
	if (data->i == 0)
		return ;
	if (tags->mask & FP_MASK_FLAG_SHARP)
		ft_strcpy(prefix, "0");
}
