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
