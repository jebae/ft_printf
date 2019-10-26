#include "ft_printf.h"

int		fp_set_double_parts(
	double num,
	size_t precision,
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	short				exponent;
	int					carry;
	unsigned long long	mantissa;

	if (ft_is_nan(num) || ft_is_inf(num))
		return (FP_SUCCESS);
	ft_extract_double(num, &exponent, &mantissa);
	if (exponent == 0 && mantissa == 0)
		return (FP_SUCCESS);
	mantissa |= 0x10000000000000;
	exponent -= 0x3ff;
	if (fp_double_get_fraction_part(
		exponent, mantissa, precision, fraction_part) == FP_FAIL)
		return (FP_FAIL);
	carry = (fraction_part->e >= 0 && fraction_part->num.occupied != 0);
	if (carry)
		bi_erase(&fraction_part->num);
	if (fp_double_get_integer_part(
		exponent, mantissa, carry, int_part) == FP_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}

int		fp_set_ldouble_parts(
	long double num,
	size_t precision,
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	short				exponent;
	int					carry;
	unsigned long long	mantissa;

	if (ft_is_nan_l(num) || ft_is_inf_l(num))
		return (FP_SUCCESS);
	ft_extract_ldouble(num, &exponent, &mantissa);
	if (exponent == 0 && mantissa == 0)
		return (FP_SUCCESS);
	exponent -= 0x3fff;
	if (fp_ldouble_get_fraction_part(
		exponent, mantissa, precision, fraction_part) == FP_FAIL)
		return (FP_FAIL);
	carry = (fraction_part->e >= 0 && fraction_part->num.occupied != 0);
	if (carry)
		bi_erase(&fraction_part->num);
	if (fp_ldouble_get_integer_part(
		exponent, mantissa, carry, int_part) == FP_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}
