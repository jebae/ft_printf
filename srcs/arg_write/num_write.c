#include "ft_printf.h"

void			fp_int_write(
	long long num,
	size_t length,
	t_fp_buffer *buf
)
{
	long long		divider;

	if (num == 0)
	{
		fp_write_buffer(buf, '0');
		return ;
	}
	divider = ft_powd(10, length - 1);
	while (divider != 0)
	{
		fp_write_buffer(buf, '0' + ABS(num / divider % 10));
		divider /= 10;
	}
}

void			fp_uint_write(
	unsigned long long num,
	size_t length,
	t_fp_buffer *buf
)
{
	unsigned long long		divider;

	if (num == 0)
	{
		fp_write_buffer(buf, '0');
		return ;
	}
	divider = ft_powd(10, length - 1);
	while (divider != 0)
	{
		fp_write_buffer(buf, '0' + num / divider % 10);
		divider /= 10;
	}
}

static int		float_write_integer_part(
	short exponent,
	unsigned long long mantissa,
	t_bigint *bcd,
	t_fp_buffer *buf
)
{
	size_t			i;
	t_fixedpoint	int_part;

	if (fp_double_integer_part(exponent, mantissa, &int_part) == FP_FAIL)
		return (FP_FAIL);
	if (bi_double_dabble(&int_part.num, bcd) == BI_FAIL)
	{
		ft_memdel((void **)&int_part.num.data);
		return (FP_FAIL);
	}
	i = 0;
	if (bcd.occupied != 0)
		i = bcd.occupied - 1;
	if ((bcd.data[i] >> 4) != 0)
		fp_write_buffer(buf, (bcd.data[i] >> 4) + '0');
	fp_write_buffer(buf, (bcd.data[i] & 0x0f) + '0');
	while (i > 0)
	{
		fp_write_buffer(buf, (bcd.data[i - 1] >> 4) + '0');
		fp_write_buffer(buf, (bcd.data[i - 1] & 0x0f) + '0');
		i--;
	}
	ft_memdel((void **)&int_part.num.data);
	return (FP_SUCCESS);
}

void			fp_float_write(
	double num,
	size_t precision,
	t_fp_buffer *buf
)
{
	short				exponent;
	unsigned long long	*int64;
	t_bigint			bcd;

	// handle 0, inf
	int64 = (unsigned long long *)&num;
	exponent = ((int64 >> 52) & 0x7ff) - 0x3ff;
	*int64 &= 0xfffffffffffff;
	*int64 |= 0x10000000000000;
	if (bi_new(&bcd, 1, BI_SIGN_POSITIVE) == BI_FAIL)
		return ;
	// write int part (double dabble print)
	// write fraction part by precition (rounding)
}
