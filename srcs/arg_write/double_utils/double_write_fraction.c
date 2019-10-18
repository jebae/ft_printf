#include "ft_printf.h"

static int	handle_fail(t_bigint *bcd)
{
	bi_del(bcd);
	return (BI_FAIL);
}

int				fp_double_write_fraction_part(
	t_fixedpoint *fraction_part,
	size_t precision,
	t_fp_buffer *buf
)
{
	long long		i;
	t_bigint		bcd;
	size_t			len;

	bi_init(&bcd);
	if (bi_double_dabble(&fraction_part->num, &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	len = bcd_len(&bcd);
	i = fraction_part->e + (long long)len;
	while (precision && i < 0)
	{
		fp_write_buffer(buf, '0');
		i++;
		precision--;
	}
	while (precision && len--)
	{
		fp_write_buffer(buf, bcd_get_digit(&bcd, len) + '0');
		precision--;
	}
	while (precision--)
		fp_write_buffer(buf, '0');
	bi_del(&bcd);
	return (FP_SUCCESS);
}

