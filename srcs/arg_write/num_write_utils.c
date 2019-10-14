#include "ft_printf.h"

static int		double_fraction_part_handle_fail(t_fixedpoint *recip)
{
	ft_memdel((void **)&(recip->num.data));
	return (FP_FAIL);
}

static int		get_reciprocal(t_fixedpoint *recip, size_t num_bits)
{
	size_t			i;
	t_fixedpoint	one_half;

	if (num_bits == 0)
		return (FP_SUCCESS);
	if (fxp_new(&one_half, 1, BI_SIGN_POSITIVE) == FXP_FAIL)
		return (FP_FAIL);
	bi_push(&(one_half.num), 5);
	one_half.e = -1;
	i = 0;
	while (i < num_bits)
	{
		if (fxp_mul_fxp(recip, &one_half, recip) == FXP_FAIL)
		{
			ft_memdel((void **)&one_half.num.data);
			return (FP_FAIL);
		}
		i++;
	}
	ft_memdel((void **)&one_half.num.data);
	return (FP_SUCCESS);
}

static void		get_sum(
	t_fixedpoint *sum,
	unsigned long long mantissa,
	size_t num_bits
)
{
	size_t		i;
	size_t		j;

	num_bits = MIN(num_bits, 53);
	j = num_bits / 8;
	i = 0;
	while (i < j)
	{
		bi_push(&(sum->num), mantissa & 0xff);
		mantissa >>= 8;
		i++;
	}
	j = num_bits % 8;
	while (j > 0)
	{
		bi_set_bit(&(sum->num), i * 8 + j - 1, (mantissa >> (j - 1)) & 1);
		j--;
	}
	bi_update_occupied(&(sum->num));
}

int				fp_double_fraction_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *fraction_part
)
{
	t_fixedpoint	recip;
	size_t			size;
	size_t			num_bits;

	if (fxp_new(&recip, 1, BI_SIGN_POSITIVE) == FXP_FAIL)
		return (FP_FAIL);
	bi_push(&(recip.num), 1);
	if (exponent < 52)
		num_bits = 52 - exponent;
	else
		num_bits = 0;
	size = (num_bits % BI_UNIT_BITS)
		? num_bits / BI_UNIT_BITS + 1
		: num_bits / BI_UNIT_BITS;
	if (fxp_new(fraction_part, MAX(size, 1), BI_SIGN_POSITIVE) == FXP_FAIL)
		return (double_fraction_part_handle_fail(&recip));
	if (get_reciprocal(&recip, num_bits) == FP_FAIL)
		return (double_fraction_part_handle_fail(&recip));
	get_sum(fraction_part, mantissa, num_bits);
	if (fxp_mul_fxp(fraction_part, &recip, fraction_part) == FXP_FAIL)
		return (FP_FAIL);
	ft_memdel((void **)&recip.num.data);
	return (FP_SUCCESS);
}

int				fp_double_integer_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
)
{
	size_t		size;

	mantissa >>= 52 - MIN(exponent, 52);
	size = 1;
	if (exponent > 0)
		size += exponent;
	size = (size % BI_UNIT_BITS)
		? size / BI_UNIT_BITS + 1
		: size / BI_UNIT_BITS;
	if (fxp_new(int_part, size, BI_SIGN_POSITIVE) == FXP_FAIL)
		return (FP_FAIL);
	while (mantissa)
	{
		bi_push(&(int_part->num), mantissa & 0xff);
		mantissa >>= 8;
	}
	if (exponent > 52)
		bi_left_shift(&(int_part->num), exponent - 52, &(int_part->num));
	if (fxp_compact(int_part) == FXP_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}