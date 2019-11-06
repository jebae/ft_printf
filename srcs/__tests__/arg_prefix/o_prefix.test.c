#include "ft_printf.test.h"

// case no # in mask
void		test_arg_o_prefix_case1(void)
{
	printf(KYEL "test_arg_o_prefix_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];
	size_t			length;

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 123;
	length = 3;

	fp_arg_o_prefix(&data, &tags, length, prefix);

	test(
		ft_strcmp(prefix, "") == 0,
		"arg_o_prefix : prefix"
	);
}

// case #
void		test_arg_o_prefix_case2(void)
{
	printf(KYEL "test_arg_o_prefix_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];
	size_t			length;

	ft_bzero(prefix, 2);
	tags.mask = 0;
	data.i = 123;
	length = 3;
	tags.mask |= FP_MASK_FLAG_SHARP;

	fp_arg_o_prefix(&data, &tags, length, prefix);

	test(
		ft_strcmp(prefix, "0") == 0,
		"arg_o_prefix : prefix"
	);
}

// case # data = 0, length = 0
void		test_arg_o_prefix_case3(void)
{
	printf(KYEL "test_arg_o_prefix_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;
	char			prefix[2];
	size_t			length;

	ft_bzero(prefix, 2);
	tags.mask = 0;
	tags.precision = 0;
	data.i = 0;
	length = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	tags.mask |= FP_MASK_PRECISION;

	fp_arg_o_prefix(&data, &tags, length, prefix);

	test(
		ft_strcmp(prefix, "0") == 0,
		"arg_o_prefix : prefix"
	);
}
