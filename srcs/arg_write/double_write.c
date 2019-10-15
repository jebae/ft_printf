#include "ft_printf.h"

void			fp_double_write(
	double num,
	size_t precision,
	t_fp_buffer *buf
)
{
	t_fp_double_fields	df;
	t_bigint			bcd;

	// handle 0, inf
	df.mantissa = *((unsigned long long *)&num);
	df.exponent = ((df.mantissa >> 52) & 0x7ff) - 0x3ff;
	df.mantissa &= 0xfffffffffffff;
	df.mantissa |= 0x10000000000000;
	if (bi_new(&bcd, 1, BI_SIGN_POSITIVE) == BI_FAIL)
		return ;
	if (double_write_integer_part(&df, &bcd, buf) == FP_FAIL)
		return ;
	if (precision != 0)
		fp_write_buffer(buf, '.');
	if (double_write_fraction_part(&df, precision, &bcd, buf) == FP_FAIL)
		return ;
}
