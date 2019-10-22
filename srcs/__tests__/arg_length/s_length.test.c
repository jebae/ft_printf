#include "ft_printf.test.h"

// case simple
void		test_arg_s_length_case1(void)
{
	printf(KYEL "test_arg_s_length_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	data.ptr = (void *)"hello world";

	test(
		fp_arg_s_length(&data, &tags) == 11,
		"arg_s_length : return value"
	);
}

// case precision
void		test_arg_s_length_case2(void)
{
	printf(KYEL "test_arg_s_length_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 2;
	data.ptr = (void *)"hello world";

	test(
		fp_arg_s_length(&data, &tags) == 2,
		"arg_s_length : return value"
	);
}

// case precision bigger than str len
void		test_arg_s_length_case3(void)
{
	printf(KYEL "test_arg_s_length_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 20;
	data.ptr = (void *)"hello world";

	test(
		fp_arg_s_length(&data, &tags) == 11,
		"arg_s_length : return value"
	);
}

// case strlen -> 0
void		test_arg_s_length_case4(void)
{
	printf(KYEL "test_arg_s_length_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 20;
	data.ptr = (void *)"";

	test(
		fp_arg_s_length(&data, &tags) == 0,
		"arg_s_length : return value"
	);
}

// case precision = 0
void		test_arg_s_length_case5(void)
{
	printf(KYEL "test_arg_s_length_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 0;
	data.ptr = (void *)"hello world";

	test(
		fp_arg_s_length(&data, &tags) == 0,
		"arg_s_length : return value"
	);
}

// case null
void		test_arg_s_length_case6(void)
{
	printf(KYEL "test_arg_s_length_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	data.ptr = NULL;

	test(
		fp_arg_s_length(&data, &tags) == 6,
		"arg_s_length : return value"
	);
}

// case null with precision
void		test_arg_s_length_case7(void)
{
	printf(KYEL "test_arg_s_length_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 2;
	data.ptr = NULL;

	test(
		fp_arg_s_length(&data, &tags) == 2,
		"arg_s_length : return value"
	);
}
