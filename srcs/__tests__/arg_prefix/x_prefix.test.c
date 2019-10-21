#include "ft_printf.test.h"

// case no # in mask
void		test_arg_x_prefix_case1(void)
{
	printf(KYEL "test_arg_x_prefix_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 123;

	fp_arg_x_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "") == 0,
		"arg_x_prefix : prefix"
	);
}

// case #
void		test_arg_x_prefix_case2(void)
{
	printf(KYEL "test_arg_x_prefix_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 123;
	tags.mask |= FP_MASK_FLAG_SHARP;

	fp_arg_x_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "0x") == 0,
		"arg_x_prefix : prefix"
	);
}

// case 0
void		test_arg_x_prefix_case3(void)
{
	printf(KYEL "test_arg_x_prefix_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;

	fp_arg_x_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "") == 0,
		"arg_x_prefix : prefix"
	);
}

// case no # in mask
void		test_arg_upper_x_prefix_case1(void)
{
	printf(KYEL "test_arg_upper_x_prefix_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 123;

	fp_arg_upper_x_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "") == 0,
		"arg_upper_x_prefix : prefix"
	);
}

// case #
void		test_arg_upper_x_prefix_case2(void)
{
	printf(KYEL "test_arg_upper_x_prefix_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 123;
	tags.mask |= FP_MASK_FLAG_SHARP;

	fp_arg_upper_x_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "0X") == 0,
		"arg_upper_x_prefix : prefix"
	);
}

// case 0
void		test_arg_upper_x_prefix_case3(void)
{
	printf(KYEL "test_arg_upper_x_prefix_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;

	fp_arg_upper_x_prefix(&data, &tags, prefix);

	test(
		ft_strcmp(prefix, "") == 0,
		"arg_upper_x_prefix : prefix"
	);
}
