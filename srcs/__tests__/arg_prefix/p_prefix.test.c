#include "ft_printf.test.h"

void		test_arg_p_prefix_case1(void)
{
	printf(KYEL "test_arg_p_prefix_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 0x123456;

	fp_arg_p_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "0x") == 0,
		"arg_p_prefix : prefix"
	);
}

// case 0
void		test_arg_p_prefix_case2(void)
{
	printf(KYEL "test_arg_p_prefix_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 0x0;

	fp_arg_p_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "0x") == 0,
		"arg_p_prefix : prefix"
	);
}
