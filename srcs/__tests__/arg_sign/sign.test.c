#include "ft_printf.test.h"

void	test_num_sign_case1(void)
{
	printf(KYEL "test_num_sign_case1\n" KNRM);
	t_fp_tags		tags;

	tags.mask = 0;

	test(
		fp_num_sign(1, &tags) == -1,
		"num_sign (positive, NO_MASK) : return value"
	);
}

void	test_num_sign_case2(void)
{
	printf(KYEL "test_num_sign_case2\n" KNRM);
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_SPACE;

	test(
		fp_num_sign(1, &tags) == ' ',
		"num_sign (positive, SPACE) : return value"
	);
}

void	test_num_sign_case3(void)
{
	printf(KYEL "test_num_sign_case3\n" KNRM);
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.mask |= FP_MASK_FLAG_SPACE;

	test(
		fp_num_sign(1, &tags) == '+',
		"num_sign (positive, PLUS, SPACE) : return value"
	);
}

void	test_num_sign_case4(void)
{
	printf(KYEL "test_num_sign_case4\n" KNRM);
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.mask |= FP_MASK_FLAG_SPACE;

	test(
		fp_num_sign(0, &tags) == '-',
		"num_sign (negative, PLUS, SPACE) : return value"
	);
}

void	test_num_sign_case5(void)
{
	printf(KYEL "test_num_sign_case5\n" KNRM);
	t_fp_tags		tags;

	tags.mask = 0;
	tags.mask |= FP_MASK_FLAG_PLUS;

	test(
		fp_num_sign(1, &tags) == '+',
		"num_sign (positive, PLUS) : return value"
	);
}

