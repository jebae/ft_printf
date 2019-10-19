#include "ft_printf.test.h"

void		test_arg_o_length_case1(void)
{
	printf(KYEL "test_arg_o_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0144423;

	test(
		fp_arg_o_length(&data, NULL) == 6,
		"arg_o_length : return value"
	);
}

void		test_arg_o_length_case2(void)
{
	printf(KYEL "test_arg_o_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 037777777777;

	test(
		fp_arg_o_length(&data, NULL) == 11,
		"arg_o_length : return value"
	);
}

// case overflow
void		test_arg_o_length_case3(void)
{
	printf(KYEL "test_arg_o_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 040000000000;

	test(
		fp_arg_o_length(&data, NULL) == 1,
		"arg_o_length : return value"
	);
}

// case 0
void		test_arg_o_length_case4(void)
{
	printf(KYEL "test_arg_o_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = 00;

	test(
		fp_arg_o_length(&data, NULL) == 1,
		"arg_o_length : return value"
	);
}

void		test_arg_ho_length_case1(void)
{
	printf(KYEL "test_arg_ho_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0177777;

	test(
		fp_arg_ho_length(&data, NULL) == 6,
		"arg_ho_length : return value"
	);
}

// case overflow
void		test_arg_ho_length_case2(void)
{
	printf(KYEL "test_arg_ho_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0200000;

	test(
		fp_arg_ho_length(&data, NULL) == 1,
		"arg_ho_length : return value"
	);
}

void		test_arg_hho_length_case1(void)
{
	printf(KYEL "test_arg_hho_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0377;

	test(
		fp_arg_hho_length(&data, NULL) == 3,
		"arg_hho_length : return value"
	);
}

// case overflow
void		test_arg_hho_length_case2(void)
{
	printf(KYEL "test_arg_hho_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0400;

	test(
		fp_arg_hho_length(&data, NULL) == 1,
		"arg_hho_length : return value"
	);
}

void		test_arg_lo_length_case1(void)
{
	printf(KYEL "test_arg_lo_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 01777777777777777777777;

	test(
		fp_arg_lo_length(&data, NULL) == 22,
		"arg_lo_length : return value"
	);
}

void		test_arg_llo_length_case1(void)
{
	printf(KYEL "test_arg_llo_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 01777777777777777777777;

	test(
		fp_arg_llo_length(&data, NULL) == 22,
		"arg_llo_length : return value"
	);
}
