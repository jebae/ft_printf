#include "ft_printf.h"

static int		handle_fail(t_bigint *bi)
{
	bi_del(bi);
	return (BI_FAIL);
}

int				fp_double_handle_carry(t_fixedpoint *int_part)
{
	t_bigint	carry;

	bi_init(&carry);
	if (bi_push(&carry, 1) == BI_FAIL)
		return (FP_FAIL);
	if (bi_add_bi(&int_part->num, &carry, &int_part->num) == BI_FAIL)
	{
		bi_del(&carry);
		return (FP_FAIL);
	}
	bi_del(&carry);
	return (FP_SUCCESS);
}

int				fp_double_get_integer_part(
	short exponent,
	unsigned long long mantissa,
	int carry,
	t_fixedpoint *int_part
)
{
	size_t		size;
	t_bigint	bcd;

	bi_init(&bcd);
	size = (exponent > 0) ? (1 + exponent) : 1;
	size = (size % BI_UNIT_BITS)
		? size / BI_UNIT_BITS + 1
		: size / BI_UNIT_BITS;
	if (bi_memalloc(&int_part->num, size) == FXP_FAIL)
		return (FP_FAIL);
	mantissa >>= 52 - MAX(MIN(exponent, 52), -1);
	while (mantissa)
	{
		bi_push(&int_part->num, mantissa & 0xff);
		mantissa >>= 8;
	}
	if (exponent > 52)
		bi_left_shift(&int_part->num, exponent - 52, &int_part->num);
	if (carry && fp_double_handle_carry(int_part) == FP_FAIL)
		return (handle_fail(&bcd));
	if (bi_double_dabble(&int_part->num, &bcd) == BI_FAIL)
		return (handle_fail(&bcd));
	bi_del(&int_part->num);
	int_part->num = bcd;
	return (FP_SUCCESS);
}
