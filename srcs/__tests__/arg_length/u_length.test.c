#include "ft_printf.test.h"

void		test_arg_u_length_case1(void)
{
	printf(KYEL "test_arg_u_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_u_length(&data, NULL) == 3,
		"arg_u_length (123) : return value"
	);
}

void		test_arg_u_length_case2(void)
{
	printf(KYEL "test_arg_u_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_u_length(&data, NULL) == 10, // expected with 3590615987
		"arg_u_length (123123123123123) : return value"
	);
}

void		test_arg_u_length_case3(void)
{
	printf(KYEL "test_arg_u_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_u_length(&data, NULL) == 1,
		"arg_u_length (0) : return value"
	);
}

void		test_arg_u_length_case4(void)
{
	printf(KYEL "test_arg_u_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_u_length(&data, NULL) == 10, // exepcted with 4294967295
		"arg_u_length (-1) : return value"
	);
}

void		test_arg_hu_length_case1(void)
{
	printf(KYEL "test_arg_hu_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_hu_length(&data, NULL) == 3,
		"arg_hu_length (123) : return value"
	);
}

void		test_arg_hu_length_case2(void)
{
	printf(KYEL "test_arg_hu_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_hu_length(&data, NULL) == 5, // expected with 29619
		"arg_hu_length (123123123123123) : return value"
	);
}

void		test_arg_hu_length_case3(void)
{
	printf(KYEL "test_arg_hu_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_hu_length(&data, NULL) == 1,
		"arg_hu_length (0) : return value"
	);
}

void		test_arg_hu_length_case4(void)
{
	printf(KYEL "test_arg_hu_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_hu_length(&data, NULL) == 5, // expected with 65535
		"arg_hu_length (-1) : return value"
	);
}

void		test_arg_hhu_length_case1(void)
{
	printf(KYEL "test_arg_hhu_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_hhu_length(&data, NULL) == 3,
		"arg_hhu_length (123) : return value"
	);
}

void		test_arg_hhu_length_case2(void)
{
	printf(KYEL "test_arg_hhu_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_hhu_length(&data, NULL) == 3, // expected with 179
		"arg_hhu_length (123123123123123) : return value"
	);
}

void		test_arg_hhu_length_case3(void)
{
	printf(KYEL "test_arg_hhu_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_hhu_length(&data, NULL) == 1,
		"arg_hhu_length (0) : return value"
	);
}

void		test_arg_hhu_length_case4(void)
{
	printf(KYEL "test_arg_hhu_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_hhu_length(&data, NULL) == 3, // expected with 255
		"arg_hhu_length (-1) : return value"
	);
}

void		test_arg_lu_length_case1(void)
{
	printf(KYEL "test_arg_lu_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_lu_length(&data, NULL) == 3,
		"arg_lu_length (123) : return value"
	);
}

void		test_arg_lu_length_case2(void)
{
	printf(KYEL "test_arg_lu_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_lu_length(&data, NULL) == 15, // expected with 123123123123123
		"arg_lu_length (123123123123123) : return value"
	);
}

void		test_arg_lu_length_case3(void)
{
	printf(KYEL "test_arg_lu_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_lu_length(&data, NULL) == 1,
		"arg_lu_length (0) : return value"
	);
}

void		test_arg_lu_length_case4(void)
{
	printf(KYEL "test_arg_lu_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_lu_length(&data, NULL) == 20, // expected with 18446744073709551615
		"arg_lu_length (-1) : return value"
	);
}

void		test_arg_llu_length_case1(void)
{
	printf(KYEL "test_arg_llu_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123;
	test(
		fp_arg_llu_length(&data, NULL) == 3,
		"arg_llu_length (123) : return value"
	);
}

void		test_arg_llu_length_case2(void)
{
	printf(KYEL "test_arg_llu_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 123123123123123;
	test(
		fp_arg_llu_length(&data, NULL) == 15, // expected with 123123123123123
		"arg_llu_length (123123123123123) : return value"
	);
}

void		test_arg_llu_length_case3(void)
{
	printf(KYEL "test_arg_llu_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0;
	test(
		fp_arg_llu_length(&data, NULL) == 1,
		"arg_llu_length (0) : return value"
	);
}

void		test_arg_llu_length_case4(void)
{
	printf(KYEL "test_arg_llu_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = -1;
	test(
		fp_arg_llu_length(&data, NULL) == 20, // expected with 18446744073709551615
		"arg_llu_length (-1) : return value"
	);
}
