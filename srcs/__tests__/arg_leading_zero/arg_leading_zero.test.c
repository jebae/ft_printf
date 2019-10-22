#include "ft_printf.test.h"

// case precision > length
void		test_arg_leading_zero_case1(void)
{
	printf(KYEL "test_arg_leading_zero_case1\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 5;

	test(
		fp_arg_leading_zero(&tags, 3) == 2,
		"arg_leading_zero : return value"
	);
}

// case no mask PRECISION
void		test_arg_leading_zero_case2(void)
{
	printf(KYEL "test_arg_leading_zero_case2\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 6;

	test(
		fp_arg_leading_zero(&tags, 3) == 0,
		"arg_leading_zero : return value"
	);
}

// case precision < length
void		test_arg_leading_zero_case3(void)
{
	printf(KYEL "test_arg_leading_zero_case3\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 6;

	test(
		fp_arg_leading_zero(&tags, 10) == 0,
		"arg_leading_zero : return value"
	);
}
