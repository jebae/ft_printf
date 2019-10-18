#include "ft_printf.h"

static void		bcd_iter_f(unsigned char digit, void *arg)
{
	t_fp_buffer		*buf;

	buf = (t_fp_buffer *)arg;
	fp_write_buffer(buf, digit + '0');
}

static void		handle_return(t_fixedpoint *int_part, t_fixedpoint *fraction_part)
{
	if (int_part != NULL)
		ft_memdel((void **)&int_part->num.data);
	ft_memdel((void **)&fraction_part->num.data);
}

static int		write_integer_part(
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
		{
			bi_del(&bcd);
			return (BI_FAIL);
		}
	}
	if (bi_double_dabble(&int_part->num, &bcd) == BI_FAIL)
	{
		bi_del(&bcd);
		return (FP_FAIL);
	}
	bcd_iter(&bcd, &bcd_iter_f, (void *)buf);
	while ((int_part->e)-- > 1)
		fp_write_buffer(buf, '0');
	if (int_part->e == 0)
		fp_write_buffer(buf, carry + '0');
	bi_del(&bcd);
	return (FP_SUCCESS);
}

static int		write_fraction_part(
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
		return (FP_FAIL);
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
}

void			fp_double_write(
	double num,
	size_t precision,
	t_fp_buffer *buf
)
{
	short				exponent
	unsigned long long	mantissa;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;

	// handle 0, inf
	mantissa = *((unsigned long long *)&num);
	exponent = ((mantissa >> 52) & 0x7ff) - 0x3ff;
	mantissa &= 0xfffffffffffff;
	mantissa |= 0x10000000000000;
	fxp_init(&int_part);
	fxp_init(&fraction_part);
	if (fp_double_fraction_part(
		exponent, mantissa, precision, &fraction_part) == FP_FAIL)
		return (handle_return(NULL, &fraction_part));
	if (fp_double_integer_part(exponent, mantissa, &int_part) == FP_FAIL)
		return (handle_return(NULL, &fraction_part));
	// write_integer_part();
	if (precision > 0)
	{
		fp_write_buffer(buf, '.');
		// write fraction part
	}
}
