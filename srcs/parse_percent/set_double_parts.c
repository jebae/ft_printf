#include "ft_printf.h"

static void		extract_double(
	double num,
	short *exponent,
	unsigned long long *mantissa,
	int *is_exception
)
{
	if (ft_is_nan(num) || ft_is_inf(num))
	{
		*is_exception = 1;
		return ;
	}
	ft_extract_double(num, exponent, mantissa);
	if (*exponent == 0 && *mantissa == 0)
	{
		*is_exception = 1;
		return ;
	}
	*mantissa |= 0x10000000000000;
	*exponent -= 0x3ff;
	*is_exception = 0;
}

int				fp_set_double_parts(
	double num,
	size_t precision,
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	short				exponent;
	int					carry;
	int					is_exception;
	unsigned long long	mantissa;

	extract_double(num, &exponent, &mantissa, &is_exception);
	if (is_exception)
		return (FP_SUCCESS);
	if (fp_double_get_fraction_part(
		exponent, mantissa, fraction_part) == FP_FAIL)
		return (FP_FAIL);
	if (fp_round_fraction_part(fraction_part, precision) == FP_FAIL)
		return (FP_FAIL);
	carry = (fraction_part->e >= 0 && fraction_part->num.occupied != 0);
	if (carry)
		bi_erase(&fraction_part->num);
	if (fp_double_get_integer_part(
		exponent, mantissa, carry, int_part) == FP_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}

static int		case_int_part_only(
	size_t precision,
	size_t len,
	t_fixedpoint *int_part
)
{
	size_t		pos;

	pos = len - 1 - precision;
	if (bcd_round(&int_part->num, pos, &int_part->num) == BI_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}

static int		handle_carry(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part,
	size_t int_len
)
{
	unsigned char	digit;
	int				carry;
	size_t			i;

	if (fraction_part->e < 0 || fraction_part->num.occupied == 0)
		return (FP_SUCCESS);
	bi_erase(&fraction_part->num);
	carry = 1;
	i = 0;
	while (i < int_len && carry)
	{
		digit = bcd_get_digit(&int_part->num, i) + carry;
		bcd_set_digit(&int_part->num, i, digit % 10);
		carry = digit / 10;
		i++;
	}
	if (carry)
	{
		if (int_len & 1)
			bcd_set_digit(&int_part->num, int_len, 1);
		else if (bi_push(&int_part->num, 0x01) == BI_FAIL)
			return (FP_FAIL);
	}
	bi_update_occupied(&int_part->num);
	return (FP_SUCCESS);
}

int				fp_set_scientific_double_parts(
	double num,
	size_t precision,
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	short				exponent;
	int					is_exception;
	unsigned long long	mantissa;
	size_t				int_len;

	extract_double(num, &exponent, &mantissa, &is_exception);
	if (is_exception)
		return (FP_SUCCESS);
	if (fp_double_get_integer_part(
		exponent, mantissa, 0, int_part) == FP_FAIL)
		return (FP_FAIL);
	int_len = bcd_len(&int_part->num);
	if (int_len - 1 > precision)
		return (case_int_part_only(precision, int_len, int_part));
	if (fp_double_get_fraction_part(
		exponent, mantissa, fraction_part) == FP_FAIL)
		return (FP_FAIL);
	if (int_part->num.occupied == 0)
		precision -= bcd_len(&fraction_part->num) - 1 + fraction_part->e;
	else
		precision -= int_len - 1;
	if (fp_round_fraction_part(fraction_part, precision) == FP_FAIL)
		return (FP_FAIL);
	return (handle_carry(int_part, fraction_part, int_len));
}
