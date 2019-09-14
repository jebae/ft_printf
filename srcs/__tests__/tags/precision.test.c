#include "ft_printf.test.h"

void	test_parse_precision_case1(void)
{
	printf(KYEL "test_parse_precision_case1\n" KNRM);

	const char	*format = ".34foo";
	t_fp_tags	tags;

	tags.precision = 6;
	
	test(
		fp_parse_precision(format, &tags) == 3,
		"precision (.34foo) : return value"
	);

	test(
		tags.precision == 34,
		"precision (.34foo) : tags.precision"
	);
}

void	test_parse_precision_case2(void)
{
	printf(KYEL "test_parse_precision_case2\n" KNRM);

	const char	*format = ".foo";
	t_fp_tags	tags;

	tags.precision = 6;
	
	test(
		fp_parse_precision(format, &tags) == 1,
		"precision (.foo) : return value"
	);

	test(
		tags.precision == 0,
		"precision (.foo) : tags.precision"
	);
}

void	test_parse_precision_case3(void)
{
	printf(KYEL "test_parse_precision_case3\n" KNRM);

	const char	*format = "foo";
	t_fp_tags	tags;

	tags.precision = 6;
	
	test(
		fp_parse_precision(format, &tags) == 0,
		"precision (foo) : return value"
	);

	test(
		tags.precision == 6,
		"precision (foo) : tags.precision"
	);
}
