#include "ft_printf.h"

static int		ldouble_fraction_part_handle_fail(t_fixedpoint *recip)
{
	fxp_del(recip);
	return (FP_FAIL);
}

static int		get_reciprocal(t_fixedpoint *recip, size_t num_bits)
{
	size_t			i;
	t_fixedpoint	one_half;

	if (num_bits == 0)
		return (FP_SUCCESS);
	fxp_init(&one_half);
	bi_push(&one_half.num, 5);
	one_half.e = -1;
	i = 0;
	while (i < num_bits)
	{
		if (fxp_mul_fxp(recip, &one_half, recip) == FXP_FAIL)
		{
			fxp_del(&one_half);
			return (FP_FAIL);
		}
		i++;
	}
	fxp_del(&one_half);
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

	num_bits = MIN(num_bits, 64);
	j = num_bits / 8;
	i = 0;
	while (i < j)
	{
		bi_push(&sum->num, mantissa & 0xff);
		mantissa >>= 8;
		i++;
	}
	j = num_bits % 8;
	while (j > 0)
	{
		bi_set_bit(&sum->num, i * 8 + j - 1, (mantissa >> (j - 1)) & 1);
		j--;
	}
}

int				fp_ldouble_fraction_part(
	short exponent,
	unsigned long long mantissa,
	size_t precision,
	t_fixedpoint *fraction_part
)
{
	t_fixedpoint	recip;
	size_t			size;
	size_t			num_bits;

	fxp_init(&recip);
	if (bi_push(&recip.num, 1) == BI_FAIL)
		return (FP_FAIL);
	if (exponent < 63)
		num_bits = 63 - exponent;
	else
		num_bits = 0;
	size = (num_bits % BI_UNIT_BITS)
		? num_bits / BI_UNIT_BITS + 1
		: num_bits / BI_UNIT_BITS;
	if (bi_memalloc(&fraction_part->num, MAX(size, 1)) == FXP_FAIL)
		return (ldouble_fraction_part_handle_fail(&recip));
	if (get_reciprocal(&recip, num_bits) == FP_FAIL)
		return (ldouble_fraction_part_handle_fail(&recip));
	get_sum(fraction_part, mantissa, num_bits);
	if (fxp_mul_fxp(fraction_part, &recip, fraction_part) == FXP_FAIL)
		return (ldouble_fraction_part_handle_fail(&recip));
	if (fxp_round(fraction_part, precision, fraction_part) == FXP_FAIL)
		return (ldouble_fraction_part_handle_fail(&recip));
	fxp_del(&recip);
	return (FP_SUCCESS);
}

int				fp_ldouble_integer_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
)
{
	size_t		size;

	size = 1;
	if (exponent > 0)
		size += exponent;
	size = (size % BI_UNIT_BITS)
		? size / BI_UNIT_BITS + 1
		: size / BI_UNIT_BITS;
	if (bi_memalloc(&int_part->num, size) == FXP_FAIL)
		return (FP_FAIL);
	if (exponent < 0)
		mantissa = 0;
	else
		mantissa >>= 63 - MAX(MIN(exponent, 63), -1);
	while (mantissa)
	{
		bi_push(&int_part->num, mantissa & 0xff);
		mantissa >>= 8;
	}
	if (exponent > 63)
		bi_left_shift(&int_part->num, exponent - 63, &int_part->num);
	if (fxp_compact(int_part) == FXP_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}
