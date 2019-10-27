#include "ft_printf.h"

static void		case_fraction_part_only(
	t_fixedpoint *fraction_part,
	t_fp_tags *tags,
	t_fp_buffer *buf
)
{
	size_t		fraction_len;
	size_t		precision;

	precision = tags->precision;
	fraction_len = bcd_len(&fraction_part->num);
	fp_write_buffer(buf,
		bcd_get_digit(&fraction_part->num, fraction_len - 1) + '0');
	if (precision > 0 || (tags->mask & FP_MASK_FLAG_SHARP))
		fp_write_buffer(buf, '.');
	while (precision && --fraction_len)
	{
		fp_write_buffer(buf,
			bcd_get_digit(&fraction_part->num, fraction_len - 1) + '0');
		precision--;
	}
	while (precision--)
		fp_write_buffer(buf, '0');
}

static void		write_exponent(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part,
	t_fp_buffer *buf
)
{
	int		exponent;
	int		divider;

	exponent = fp_get_scientific_exponent(int_part, fraction_part);
	fp_write_buffer(buf, 'e');
	if (exponent < 0)
	{
		fp_write_buffer(buf, '-');
		exponent = -exponent;
	}
	else
		fp_write_buffer(buf, '+');
	if (exponent < 10)
		fp_write_buffer(buf, '0');
	divider = 1;
	while ((exponent / divider) >= 10)
		divider *= 10;
	while (divider)
	{
		fp_write_buffer(buf, exponent / divider % 10 + '0');
		divider /= 10;
	}
}

void			fp_double_write_scientific_parts(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part,
	t_fp_tags *tags,
	t_fp_buffer *buf
)
{
	size_t		int_len;
	size_t		precision;

	precision = tags->precision;
	if (int_part->num.occupied == 0)
		case_fraction_part_only(fraction_part, tags, buf);
	else
	{
		int_len = bcd_len(&int_part->num);
		fp_write_buffer(buf, bcd_get_digit(&int_part->num, int_len - 1) + '0');
		if (precision > 0 || (tags->mask & FP_MASK_FLAG_SHARP))
			fp_write_buffer(buf, '.');
		while (precision && --int_len)
		{
			fp_write_buffer(buf,
				bcd_get_digit(&int_part->num, int_len - 1) + '0');
			precision--;
		}
		fp_double_write_fraction_part(fraction_part, precision, buf);
	}
	write_exponent(int_part, fraction_part, buf);
}
