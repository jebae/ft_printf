#include "ft_printf.test.h"

void		test_arg_f_sign_case1(void)
{
	printf(KYEL "test_arg_f_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.f = 3.14;

	test(
		fp_arg_f_sign(&data, &tags) == -1,
		"arg_f_sign (3.14, NO_MASK) : return value"
	);
}

void		test_arg_f_sign_case2(void)
{
	printf(KYEL "test_arg_f_sign_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.f = 3.14;

	test(
		fp_arg_f_sign(&data, &tags) == ' ',
		"arg_f_sign (3.14, SPACE) : return value"
	);
}

void		test_arg_f_sign_case3(void)
{
	printf(KYEL "test_arg_f_sign_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.f = 3.14;

	test(
		fp_arg_f_sign(&data, &tags) == '+',
		"arg_f_sign (3.14, PLUS) : return value"
	);
}

void		test_arg_f_sign_case4(void)
{
	printf(KYEL "test_arg_f_sign_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.f = -3.14;

	test(
		fp_arg_f_sign(&data, &tags) == '-',
		"arg_f_sign (-3.14, NO_MASK) : return value"
	);
}

void		test_arg_f_sign_case5(void)
{
	printf(KYEL "test_arg_f_sign_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.f = -3.14;

	test(
		fp_arg_f_sign(&data, &tags) == '-',
		"arg_f_sign (-3.14, SPACE) : return value"
	);
}

void		test_arg_f_sign_case6(void)
{
	printf(KYEL "test_arg_f_sign_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.f = -3.14;

	test(
		fp_arg_f_sign(&data, &tags) == '-',
		"arg_f_sign (-3.14, PLUS) : return value"
	);
}

void		test_arg_f_sign_case7(void)
{
	printf(KYEL "test_arg_f_sign_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.f = 0.0;

	test(
		fp_arg_f_sign(&data, &tags) == '+',
		"arg_f_sign (0.0, PLUS, SPACE) : return value"
	);
}

void		test_arg_f_sign_case8(void)
{
	printf(KYEL "test_arg_f_sign_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.f = 3.14;

	test(
		fp_arg_f_sign(&data, &tags) == '+',
		"arg_f_sign (3.14, PLUS, SPACE) : return value"
	);
}

void		test_arg_lf_sign_case1(void)
{
	printf(KYEL "test_arg_lf_sign_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.lf = 3.14;

	test(
		fp_arg_lf_sign(&data, &tags) == -1,
		"arg_lf_sign (3.14, NO_MASK) : return value"
	);
}

void		test_arg_lf_sign_case2(void)
{
	printf(KYEL "test_arg_lf_sign_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.lf = 3.14;

	test(
		fp_arg_lf_sign(&data, &tags) == ' ',
		"arg_lf_sign (3.14, SPACE) : return value"
	);
}

void		test_arg_lf_sign_case3(void)
{
	printf(KYEL "test_arg_lf_sign_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.lf = 3.14;

	test(
		fp_arg_lf_sign(&data, &tags) == '+',
		"arg_lf_sign (3.14, PLUS) : return value"
	);
}

void		test_arg_lf_sign_case4(void)
{
	printf(KYEL "test_arg_lf_sign_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	data.lf = -3.14;

	test(
		fp_arg_lf_sign(&data, &tags) == '-',
		"arg_lf_sign (-3.14, NO_MASK) : return value"
	);
}

void		test_arg_lf_sign_case5(void)
{
	printf(KYEL "test_arg_lf_sign_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.lf = -3.14;

	test(
		fp_arg_lf_sign(&data, &tags) == '-',
		"arg_lf_sign (-3.14, SPACE) : return value"
	);
}

void		test_arg_lf_sign_case6(void)
{
	printf(KYEL "test_arg_lf_sign_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.lf = -3.14;

	test(
		fp_arg_lf_sign(&data, &tags) == '-',
		"arg_lf_sign (-3.14, PLUS) : return value"
	);
}

void		test_arg_lf_sign_case7(void)
{
	printf(KYEL "test_arg_lf_sign_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.mask |= FP_MASK_FLAG_SPACE;
	data.lf = 0.0;

	test(
		fp_arg_lf_sign(&data, &tags) == '+',
		"arg_lf_sign (0.0, PLUS, SPACE) : return value"
	);
}

void		test_arg_lf_sign_case8(void)
{
	printf(KYEL "test_arg_lf_sign_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.mask |= FP_MASK_FLAG_PLUS;
	data.lf = 3.14;

	test(
		fp_arg_lf_sign(&data, &tags) == '+',
		"arg_lf_sign (3.14, PLUS, SPACE) : return value"
	);
}
