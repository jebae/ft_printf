#include "ft_printf.test.h"

void		test_parse_width_case1(void)
{
	printf(KYEL "test_parse_width_case1\n" KNRM);
	const char	*format = "23foo";
	t_fp_tags	tags;

	tags.width = 0;

	test(
		fp_parse_width(format, &tags) == 2,
		"width (23foo) : return value"
	);

	test(
		tags.width == 23,
		"width (23foo) : tags.width"
	);
}

void		test_parse_width_case2(void)
{
	printf(KYEL "test_parse_width_case2\n" KNRM);
	const char	*format = "foo";
	t_fp_tags	tags;

	tags.width = 0;

	test(
		fp_parse_width(format, &tags) == 0,
		"width (foo) : return value"
	);

	test(
		tags.width == 0,
		"width (foo) : tags.width"
	);
}
