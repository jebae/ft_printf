#include "ft_printf.test.h"

void		test_arg_x_length_case1(void)
{
	printf(KYEL "test_arg_x_length_case1\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0xff;
	test(
		fp_arg_x_length(&data, NULL) == 2,
		"arg_x_length : return value"
	);
}

void		test_arg_x_length_case2(void)
{
	printf(KYEL "test_arg_x_length_case2\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0x0ffff;
	test(
		fp_arg_x_length(&data, NULL) == 4,
		"arg_x_length : return value"
	);
}

void		test_arg_x_length_case3(void)
{
	printf(KYEL "test_arg_x_length_case3\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0xffffffff;
	test(
		fp_arg_x_length(&data, NULL) == 8,
		"arg_x_length : return value"
	);
}

// case overflow
void		test_arg_x_length_case4(void)
{
	printf(KYEL "test_arg_x_length_case4\n" KNRM);
	t_fp_arg_data	data;

	data.i = 0xfffffffff;
	test(
		fp_arg_x_length(&data, NULL) == 8,
		"arg_x_length : return value"
	);
}
