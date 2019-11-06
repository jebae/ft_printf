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
	*res = fp_parse_width(format, ap, tags);
	va_end(ap);
}

void		test_parse_width_case1(void)
{
	printf(KYEL "test_parse_width_case1\n" KNRM);
	const char	*format = "23foo";
	t_fp_tags	tags;
	size_t		res;

	tags.width = 0;
	parse(format, &tags, &res, 0);

	test(
		res == 2,
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
	size_t		res;

	tags.width = 0;
	parse(format, &tags, &res, 0);

	test(
		res == 0,
		"width (foo) : return value"
	);

	test(
		tags.width == 0,
		"width (foo) : tags.width"
	);
}

void		test_parse_width_case3(void)
{
	printf(KYEL "test_parse_width_case3\n" KNRM);
	const char	*format = "*foo";
	t_fp_tags	tags;
	size_t		res;

	tags.width = 0;
	parse(format, &tags, &res, 5);

	test(
		res == 1,
		"width (*foo) : return value"
	);

	test(
		tags.width == 5,
		"width (*foo) : tags.width"
	);
}
