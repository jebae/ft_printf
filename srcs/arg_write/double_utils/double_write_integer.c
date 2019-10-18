#include "ft_printf.h"

static int	handle_fail(t_bigint *bcd)
{
	bi_del(bcd);
	return (BI_FAIL);
}

static void		bcd_iter_f(unsigned char digit, void *arg)
{
	t_fp_buffer		*buf;

	buf = (t_fp_buffer *)arg;
	fp_write_buffer(buf, digit + '0');
}

int			fp_double_write_integer_part(
	t_fixedpoint *int_part,
	int carry,
	t_fp_buffer *buf
)
{
	t_bigint		bcd;

	bi_init(&bcd);
	if (carry && int_part->e == 0)
	{
		if (bi_push(&bcd, carry--) == BI_FAIL)
			return (BI_FAIL);
		if (bi_add_bi(&int_part->num, &bcd, &int_part->num) == BI_FAIL)
			return (handle_fail(&bcd));
	}
	if (bi_double_dabble(&int_part->num, &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	bcd_iter(&bcd, &bcd_iter_f, (void *)buf);
	while ((int_part->e)-- > 1)
		fp_write_buffer(buf, '0');
	if (int_part->e == 0)
		fp_write_buffer(buf, carry + '0');
	bi_del(&bcd);
	return (FP_SUCCESS);
}
