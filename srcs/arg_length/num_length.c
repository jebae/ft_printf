#include "ft_printf.h"

size_t			fp_int_length(long long num, int base)
{
	size_t		len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

size_t			fp_uint_length(unsigned long long num, int base)
{
	size_t		len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

size_t			fp_double_int_part_length(double num)
{
	size_t		len;

	if (ABS_SMALLER_THEN(num, 1))
		return (1);
	len = 0;
	while (!ABS_SMALLER_THEN(num, 1) &&
		!ft_is_nan(num) && !ft_is_inf(num))
	{
		num /= 10.0f;
		len++;
	}
	return (len);
}

size_t			fp_ldouble_int_part_length(long double num)
{
	size_t		len;

	if (ABS_SMALLER_THEN(num, 1))
		return (1);
	len = 0;
	while (!ABS_SMALLER_THEN(num, 1) &&
		!ft_is_nan_l(num) && !ft_is_inf_l(num))
	{
		num /= 10.0L;
		len++;
	}
	return (len);
}
