#include "ft_printf.h"

void		fp_init_tags(t_fp_tags *tags)
{
	tags->width = 0;
	tags->precision = 6;
	tags->mask = 0;
}
