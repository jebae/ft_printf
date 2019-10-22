#include "ft_printf.test.h"

// case precision > length
void		test_arg_o_leading_zero_case1(void)
{
	printf(KYEL "test_arg_o_leading_zero_case1\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 5;

	test(
		fp_arg_o_leading_zero(&tags, 3) == 2,
		"arg_o_leading_zero : return value"
	);
}

// case precision < length
void		test_arg_o_leading_zero_case2(void)
{
	printf(KYEL "test_arg_o_leading_zero_case2\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 3;

	test(
		fp_arg_o_leading_zero(&tags, 5) == 0,
		"arg_o_leading_zero : return value"
	);
}

// case #
void		test_arg_o_leading_zero_case3(void)
{
	printf(KYEL "test_arg_o_leading_zero_case3\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.mask |= FP_MASK_FLAG_SHARP;
	tags.precision = 5;

	test(
		fp_arg_o_leading_zero(&tags, 3) == 1,
		"arg_o_leading_zero : return value"
	);
}

// case no mask precision
void		test_arg_o_leading_zero_case4(void)
{
	printf(KYEL "test_arg_o_leading_zero_case4\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_SHARP;
	tags.precision = 6;

	test(
		fp_arg_o_leading_zero(&tags, 3) == 0,
		"arg_o_leading_zero : return value"
	);
}

// case special : #, length is 0 (this means data = 0, precision = 0)
void		test_arg_o_leading_zero_case5(void)
{
	printf(KYEL "test_arg_o_leading_zero_case5\n" KNRM);
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_SHARP;
	tags.precision = 0;

	test(
		fp_arg_o_leading_zero(&tags, 0) == 1,
		"arg_o_leading_zero : return value"
	);
}
