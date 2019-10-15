#include "ft_printf.h"

static int		preprocess(
	t_fp_double_fields *df,
	t_fixedpoint *fraction_part,
	t_bigint *bcd
)
{
	if (fp_double_fraction_part(
		df->exponent, df->mantissa, fraction_part) == FP_FAIL)
	{
		ft_memdel((void **)&(fraction_part->num.data));
		return (FP_FAIL);
	}
	if (bi_double_dabble(&(fraction_part->num), bcd) == BI_FAIL)
	{
		ft_memdel((void **)&(fraction_part->num.data));
		return (FP_FAIL);
	}
	return (FP_SUCCESS);
}

static void		write_preceding_zero(
	t_fixedpoint *fraction_part,
	size_t *precision,
	t_bigint *bcd,
	t_fp_buffer *buf
)
{
	size_t			i;
	unsigned char	first_digit;

	if (bcd->occupied == 0 || *precision == 0)
		return (0);
	i = bcd->occupied * 2;
	if ((bcd->data[bcd->occupied - 1] >> 4) == 0 && i--)
		first_digit = bcd->data[bcd->occupied - 1] & 0x0f;
	else
		first_digit = bcd->data[bcd->occupied - 1] >> 4;
	i = ABS(fraction_part->e) - i;
	while (i > 0 && *precision > 0)
	{
		fp_write_buffer(buf, '0');
		i--;
		(*precision)--;
	}
	if (*precision == 0 && i == 0) // handle rounding
		buf->data[buf->i] = (first_digit >= 5) ? '1' : '0';
}

static void		write_data(
	t_fixedpoint *fraction_part,
	size_t *precision,
	t_bigint *bcd,
	t_fp_buffer *buf
)
{
	size_t		i;

	i = 0;
	if (bcd->occupied != 0)
		i = bcd->occupied - 1;
	if ((bcd->data[i] >> 4) != 0 && (*precision)--)
		fp_write_buffer(buf, (bcd->data[i] >> 4) + '0');
	if (precision > 0 && (*precision)--)
		fp_write_buffer(buf, (bcd->data[i] & 0x0f) + '0');
	while (i > 0 && *precision > 0)
	{
		fp_write_buffer(buf, (bcd->data[i - 1] >> 4) + '0');
		(*precision)--;
		if (*precision > 0 && (*precision)--)
			fp_write_buffer(buf, (bcd->data[i - 1] & 0x0f) + '0');
		i--;
	}
	if (*precision == 0)
	{
		if (i > 0)
			buf->data[buf->i] += ( >= 5) ? '1' : '0'; // when 9?
	}
}


// write rest zero

int				fp_double_write_fraction_part(
	t_fp_double_fields *df,
	size_t precision,
	t_bigint *bcd,
	t_fp_buffer *buf
)
{
	size_t			i;
	t_fixedpoint	fraction_part;

	if (preprocess(
		&fp_double_fraction_part, df, &fraction_part, bcd) == FP_FAIL)
		return (FP_FAIL);
	precision = write_preceding_zero(&fraction_part, precision, bcd, buf);
	if (() != 0)
	{
	
		while (precision > 0 && precision--)
			fp_write_buffer(buf, '0');
	}
	ft_memdel((void **)&fraction_part.num.data);
	return (FP_SUCCESS);
}
