#include "ft_printf.h"

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

static int		handle_round_carry(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part,
	size_t precision,
	size_t int_len
)
{
	if (int_part->num.occupied == 0)
		precision -= bcd_len(&fraction_part->num) - 1 + fraction_part->e;
	else
		precision -= int_len - 1;
	if (fp_round_bcd_fraction_part(fraction_part, precision) == FP_FAIL)
		return (FP_FAIL);
	if (fraction_part->e >= 0 && fraction_part->num.occupied != 0)
		return (fp_double_handle_carry(int_part, fraction_part));
	return (FP_SUCCESS);
}

int				fp_get_double_scientific_parts(
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

	fp_extract_double(num, &exponent, &mantissa, &is_exception);
	if (is_exception)
		return (FP_SUCCESS);
	if (fp_double_get_bcd_int_part(exponent, mantissa,
		&fxp_double_get_int_part, int_part) == FP_FAIL)
		return (FP_FAIL);
	int_len = bcd_len(&int_part->num);
	if (int_len - 1 > precision)
		return (case_int_part_only(precision, int_len, int_part));
	if (fp_double_get_bcd_fraction_part(exponent, mantissa,
		&fxp_double_get_fraction_part, fraction_part) == FP_FAIL)
		return (FP_FAIL);
	return (handle_round_carry(int_part, fraction_part, precision, int_len));
}
