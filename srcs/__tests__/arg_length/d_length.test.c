#include "ft_printf.test.h"

void		test_arg_d_length_case1(void)
{
	printf(KYEL "test_arg_d_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_d_length(&data, NULL) == 3,
		"arg_d_length (123) : return value"
	);
}

void		test_arg_d_length_case2(void)
{
	printf(KYEL "test_arg_d_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_d_length(&data, NULL) == 9, // expected with -704351309
		"arg_d_length (123123123123123) : return value"
	);
}

void		test_arg_d_length_case3(void)
{
	printf(KYEL "test_arg_d_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_d_length(&data, NULL) == 1,
		"arg_d_length (0) : return value"
	);
}

void		test_arg_d_length_case4(void)
{
	printf(KYEL "test_arg_d_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_d_length(&data, NULL) == 1,
		"arg_d_length (-1) : return value"
	);
}

void		test_arg_hd_length_case1(void)
{
	printf(KYEL "test_arg_hd_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_hd_length(&data, NULL) == 3,
		"arg_hd_length (123) : return value"
	);
}

void		test_arg_hd_length_case2(void)
{
	printf(KYEL "test_arg_hd_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_hd_length(&data, NULL) == 5, // expected with -29619
		"arg_hd_length (123123123123123) : return value"
	);
}

void		test_arg_hd_length_case3(void)
{
	printf(KYEL "test_arg_hd_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_hd_length(&data, NULL) == 1,
		"arg_hd_length (0) : return value"
	);
}

void		test_arg_hd_length_case4(void)
{
	printf(KYEL "test_arg_hd_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_hd_length(&data, NULL) == 1,
		"arg_hd_length (-1) : return value"
	);
}

void		test_arg_hhd_length_case1(void)
{
	printf(KYEL "test_arg_hhd_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_hhd_length(&data, NULL) == 3,
		"arg_hhd_length (123) : return value"
	);
}

void		test_arg_hhd_length_case2(void)
{
	printf(KYEL "test_arg_hhd_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_hhd_length(&data, NULL) == 2, // expected with -77
		"arg_hhd_length (123123123123123) : return value"
	);
}

void		test_arg_hhd_length_case3(void)
{
	printf(KYEL "test_arg_hhd_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_hhd_length(&data, NULL) == 1,
		"arg_hhd_length (0) : return value"
	);
}

void		test_arg_hhd_length_case4(void)
{
	printf(KYEL "test_arg_hhd_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_hhd_length(&data, NULL) == 1,
		"arg_hhd_length (-1) : return value"
	);
}

void		test_arg_ld_length_case1(void)
{
	printf(KYEL "test_arg_ld_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_ld_length(&data, NULL) == 3,
		"arg_ld_length (123) : return value"
	);
}

void		test_arg_ld_length_case2(void)
{
	printf(KYEL "test_arg_ld_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_ld_length(&data, NULL) == 15, // expected with 123123123123123
		"arg_ld_length (123123123123123) : return value"
	);
}

void		test_arg_ld_length_case3(void)
{
	printf(KYEL "test_arg_ld_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_ld_length(&data, NULL) == 1,
		"arg_ld_length (0) : return value"
	);
}

void		test_arg_ld_length_case4(void)
{
	printf(KYEL "test_arg_ld_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_ld_length(&data, NULL) == 1,
		"arg_ld_length (-1) : return value"
	);
}

void		test_arg_lld_length_case1(void)
{
	printf(KYEL "test_arg_lld_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_lld_length(&data, NULL) == 3,
		"arg_lld_length (123) : return value"
	);
}

void		test_arg_lld_length_case2(void)
{
	printf(KYEL "test_arg_lld_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_lld_length(&data, NULL) == 15, // expected with 123123123123123
		"arg_lld_length (123123123123123) : return value"
	);
}

void		test_arg_lld_length_case3(void)
{
	printf(KYEL "test_arg_lld_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_lld_length(&data, NULL) == 1,
		"arg_lld_length (0) : return value"
	);
}

void		test_arg_lld_length_case4(void)
{
	printf(KYEL "test_arg_lld_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_lld_length(&data, NULL) == 1,
		"arg_lld_length (-1) : return value"
	);
}
