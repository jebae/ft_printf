#include "ft_printf.test.h"

void		test_arg_c_length_case1(void)
{
	printf(KYEL "test_arg_c_length_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	data.i = 'h';

	test(
		fp_arg_c_length(&data, &tags) == 1,
		"arg_c_length : return value"
	);
}
