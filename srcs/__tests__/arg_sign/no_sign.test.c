#include "ft_printf.test.h"

void		test_arg_no_sign_case1(void)
{
	printf(KYEL "test_arg_no_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.i = 123;

	test(
		fp_arg_no_sign(&data, &tags) == FP_NO_SIGN,
		"arg_no_sign (PLUS, SPACE) : return value"
	);
}

void		test_arg_no_sign_case2(void)
{
	printf(KYEL "test_arg_no_sign_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.i = 123;

	test(
		fp_arg_no_sign(&data, &tags) == FP_NO_SIGN,
		"arg_no_sign (SPACE) : return value"
	);
}

void		test_arg_no_sign_case3(void)
{
	printf(KYEL "test_arg_no_sign_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.i = 123;

	test(
		fp_arg_no_sign(&data, &tags) == FP_NO_SIGN,
		"arg_no_sign (PLUS) : return value"
	);
}
