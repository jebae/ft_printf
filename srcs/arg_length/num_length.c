#include "ft_printf.h"

size_t			fp_int_length(long long num)
{
	size_t		len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

size_t			fp_uint_length(unsigned long long num)
{
	size_t		len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= 10;
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
	while (!ABS_SMALLER_THEN(num, 1))
	{
		num /= 10.0f;
		len++;
	}
	return (len);
}

size_t			fp_long_double_int_part_length(long double num)
{
	size_t		len;

	if (ABS_SMALLER_THEN(num, 1))
		return (1);
	len = 0;
	while (!ABS_SMALLER_THEN(num, 1))
	{
		num /= 10.0f;
		len++;
	}
	return (len);
}
