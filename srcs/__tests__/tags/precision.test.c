#include "ft_printf.test.h"

static void	parse(
	const char *format,
	t_fp_tags *tags,
	size_t *res,
	...
)
{
	va_list		ap;

	va_start(ap, res);
	*res = fp_parse_precision(format, ap, tags);
	va_end(ap);
}

void	test_parse_precision_case1(void)
{
	printf(KYEL "test_parse_precision_case1\n" KNRM);

	const char	*format = ".34foo";
	t_fp_tags	tags;
	size_t		res;

	tags.precision = 6;
	parse(format, &tags, &res, 0);

	test(
		res == 3,
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
	size_t		res;

	tags.precision = 6;
	parse(format, &tags, &res, 0);
	
	test(
		res == 1,
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
	size_t		res;

	tags.precision = 6;
	parse(format, &tags, &res, 0);
	
	test(
		res == 0,
		"precision (foo) : return value"
	);

	test(
		tags.precision == 6,
		"precision (foo) : tags.precision"
	);
}

void	test_parse_precision_case4(void)
{
	printf(KYEL "test_parse_precision_case4\n" KNRM);

	const char	*format = ".*foo";
	t_fp_tags	tags;
	size_t		res;

	tags.precision = 6;
	parse(format, &tags, &res, 10);
	
	test(
		res == 2,
		"precision (.*foo) : return value"
	);

	test(
		tags.precision == 10,
		"precision (.*foo) : tags.precision"
	);
}
