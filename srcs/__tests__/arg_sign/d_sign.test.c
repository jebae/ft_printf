#include "ft_printf.test.h"

void		test_arg_d_sign_case1(void)
{
	printf(KYEL "test_arg_d_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.i = 123;

	test(
		fp_arg_d_sign(&data, &tags) == '+',
		"arg_d_sign (123, PLUS) : return value"
	);
}

void		test_arg_d_sign_case2(void)
{
	printf(KYEL "test_arg_d_sign_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = -123;
	test(
		fp_arg_d_sign(&data, &tags) == '-',
		"arg_d_sign (-123, NO_MASK) : return value"
	);
}

void		test_arg_d_sign_case3(void)
{
	printf(KYEL "test_arg_d_sign_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = 2147483648;
	test(
		fp_arg_d_sign(&data, &tags) == '-',
		"arg_d_sign (2147483648, NO_MASK) : return value"
	);
}

void		test_arg_d_sign_case4(void)
{
	printf(KYEL "test_arg_d_sign_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.i = 123;
	test(
		fp_arg_d_sign(&data, &tags) == ' ',
		"arg_d_sign (123, SPACE) : return value"
	);
}

void		test_arg_d_sign_case5(void)
{
	printf(KYEL "test_arg_d_sign_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.i = 123;
	test(
		fp_arg_d_sign(&data, &tags) == '+',
		"arg_d_sign (123, PLUS, SPACE) : return value"
	);
}

void		test_arg_d_sign_case6(void)
{
	printf(KYEL "test_arg_d_sign_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.i = -123;
	test(
		fp_arg_d_sign(&data, &tags) == '-',
		"arg_d_sign (-123, PLUS, SPACE) : return value"
	);
}

void		test_arg_d_sign_case7(void)
{
	printf(KYEL "test_arg_d_sign_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = 0;
	test(
		fp_arg_d_sign(&data, &tags) == FP_NO_SIGN,
		"arg_d_sign (0, NO_MASK) : return value"
	);
}

void		test_arg_d_sign_case8(void)
{
	printf(KYEL "test_arg_d_sign_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.i = 0;
	test(
		fp_arg_d_sign(&data, &tags) == '+',
		"arg_d_sign (0, PLUS, SPACE) : return value"
	);
}

void		test_arg_d_sign_case9(void)
{
	printf(KYEL "test_arg_d_sign_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.i = 0;
	test(
		fp_arg_d_sign(&data, &tags) == ' ',
		"arg_d_sign (0, SPACE) : return value"
	);
}

void		test_arg_d_sign_case10(void)
{
	printf(KYEL "test_arg_d_sign_case10\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = 123;
	test(
		fp_arg_d_sign(&data, &tags) == FP_NO_SIGN,
		"arg_d_sign (123, NO_MASK) : return value"
	);
}

void		test_arg_hd_sign_case1(void)
{
	printf(KYEL "test_arg_hd_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = 32768;
	test(
		fp_arg_hd_sign(&data, &tags) == '-',
		"arg_hd_sign (32768, NO_MASK) : return value"
	);
}

void		test_arg_hhd_sign_case1(void)
{
	printf(KYEL "test_arg_hhd_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = 128;
	test(
		fp_arg_hhd_sign(&data, &tags) == '-',
		"arg_hhd_sign (128, NO_MASK) : return value"
	);
}

void		test_arg_ld_sign_case1(void)
{
	printf(KYEL "test_arg_ld_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = 123123123123123;
	test(
		fp_arg_ld_sign(&data, &tags) == FP_NO_SIGN,
		"arg_ld_sign (123123123123123, NO_MASK) : return value"
	);
}

void		test_arg_lld_sign_case1(void)
{
	printf(KYEL "test_arg_lld_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.i = 123123123123123;
	test(
		fp_arg_lld_sign(&data, &tags) == FP_NO_SIGN,
		"arg_lld_sign (123123123123123, NO_MASK) : return value"
	);
}
