#include "ft_printf.h"

static int		preprocess(
	t_fp_double_fields *df,
	t_fixedpoint *int_part,
	t_bigint *bcd
)
{
	if (fp_double_integer_part(
	df->exponent, df->mantissa, int_part) == FP_FAIL)
	{
		ft_memdel((void **)&(int_part->num.data));
		return (FP_FAIL);
	}
	if (bi_double_dabble(&(int_part->num), bcd) == BI_FAIL)
	{
		ft_memdel((void **)&(int_part->num.data));
		return (FP_FAIL);
	}
	return (FP_SUCCESS);
}

int		fp_double_write_integer_part(
	t_fp_double_fields *df,
	t_bigint *bcd,
	t_fp_buffer *buf
)
{
	size_t			i;
	t_fixedpoint	int_part;

	if (preprocess(df, &int_part, bcd) == FP_FAIL)
		return (FP_FAIL);
	i = 0;
	if (bcd->occupied != 0)
		i = bcd->occupied - 1;
	if ((bcd->data[i] >> 4) != 0)
		fp_write_buffer(buf, (bcd->data[i] >> 4) + '0');
	fp_write_buffer(buf, (bcd->data[i] & 0x0f) + '0');
	while (i > 0)
	{
		fp_write_buffer(buf, (bcd->data[i - 1] >> 4) + '0');
		fp_write_buffer(buf, (bcd->data[i - 1] & 0x0f) + '0');
		i--;
	}
	while (--int_part.e >= 0)
		fp_write_buffer(buf, '0');
	ft_memdel((void **)&int_part.num.data);
	return (FP_SUCCESS);
}
