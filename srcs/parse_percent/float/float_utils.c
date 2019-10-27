#include "ft_printf.h"

int				fp_round_bcd_fraction_part(
	t_fixedpoint *fraction_part,
	long long precision
)
{
	long long	len;
	long long	pos;

	len = bcd_len(&fraction_part->num);
	pos = -(precision + fraction_part->e);
	if (pos > len)
		bi_erase(&fraction_part->num);
	else if (pos > 0)
	{
		if (bcd_round(
			&fraction_part->num, pos, &fraction_part->num) == BI_FAIL)
			return (FP_FAIL);
	}
	if (fraction_part->num.occupied == 0)
		fraction_part->e = 0;
	else
		fraction_part->e += bcd_rm_trailing_zero(&fraction_part->num);
	return (FP_SUCCESS);
}

int				fp_double_handle_carry(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	bi_erase(&fraction_part->num);
	if (bcd_add_digit(&int_part->num, 1, &int_part->num) == BI_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}

void			fp_extract_double(
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

void			fp_extract_ldouble(
	long double num,
	short *exponent,
	unsigned long long *mantissa,
	int *is_exception
)
{
	if (ft_is_nan_l(num) || ft_is_inf_l(num))
	{
		*is_exception = 1;
		return ;
	}
	ft_extract_ldouble(num, exponent, mantissa);
	if (*exponent == 0 && *mantissa == 0)
	{
		*is_exception = 1;
		return ;
	}
	*exponent -= 0x3fff;
	*is_exception = 0;
}

int				fp_get_scientific_exponent(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	if (int_part->num.occupied == 0)
		return (fraction_part->e + bcd_len(&fraction_part->num) - 1);
	else
		return (bcd_len(&int_part->num) - 1);
}
