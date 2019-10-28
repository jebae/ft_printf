#include "ft_printf.h"

int				fp_get_double_parts(
	double num,
	size_t precision,
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	short				exponent;
	int					is_exception;
	unsigned long long	mantissa;

	fp_extract_double(num, &exponent, &mantissa, &is_exception);
	if (is_exception)
		return (FP_SUCCESS);
	if (fp_double_get_bcd_fraction_part(exponent, mantissa,
		&fxp_double_get_fraction_part, fraction_part) == FP_FAIL)
		return (FP_FAIL);
	if (fp_round_bcd_fraction_part(fraction_part, precision) == FP_FAIL)
		return (FP_FAIL);
	if (fp_double_get_bcd_int_part(exponent, mantissa,
		&fxp_double_get_int_part, int_part) == FP_FAIL)
		return (FP_FAIL);
	if (fraction_part->e >= 0 && fraction_part->num.occupied != 0)
		return (fp_double_handle_carry(int_part, fraction_part));
	return (FP_SUCCESS);
}

int		fp_get_ldouble_parts(
	long double num,
	size_t precision,
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	short				exponent;
	int					is_exception;
	unsigned long long	mantissa;

	fp_extract_ldouble(num, &exponent, &mantissa, &is_exception);
	if (is_exception)
		return (FP_SUCCESS);
	if (fp_double_get_bcd_fraction_part(exponent, mantissa,
		&fxp_ldouble_get_fraction_part, fraction_part) == FP_FAIL)
		return (FP_FAIL);
	if (fp_round_bcd_fraction_part(fraction_part, precision) == FP_FAIL)
		return (FP_FAIL);
	if (fp_double_get_bcd_int_part(exponent, mantissa,
		&fxp_ldouble_get_int_part, int_part) == FP_FAIL)
		return (FP_FAIL);
	if (fraction_part->e >= 0 && fraction_part->num.occupied != 0)
		return (fp_double_handle_carry(int_part, fraction_part));
	return (FP_SUCCESS);
}
