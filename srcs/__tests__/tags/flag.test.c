#include "ft_printf.test.h"

void		test_parse_flag_case1(void)
{
	printf(KYEL "test_parse_flag_case1\n" KNRM);
	const char	*format = "-foo";
	t_fp_tags	tags;

	tags.mask = 0;

	test(
		fp_parse_flag(format, &tags) == 1,
		"flag (-foo) : return value"
	);

	test(
		tags.mask == FP_MASK_FLAG_MINUS,
		"flag (-foo) : mask minus"
	);
}

void		test_parse_flag_case2(void)
{
	printf(KYEL "test_parse_flag_case2\n" KNRM);
	const char	*format = "+foo";
	t_fp_tags	tags;

	tags.mask = 0;

	test(
		fp_parse_flag(format, &tags) == 1,
		"flag (+foo) : return value"
	);

	test(
		tags.mask == FP_MASK_FLAG_PLUS,
		"flag (+foo) : mask plus"
	);
}

void		test_parse_flag_case3(void)
{
	printf(KYEL "test_parse_flag_case3\n" KNRM);
	const char	*format = " foo";
	t_fp_tags	tags;

	tags.mask = 0;

	test(
		fp_parse_flag(format, &tags) == 1,
		"flag ( foo) : return value"
	);

	test(
		tags.mask == FP_MASK_FLAG_SPACE,
		"flag ( foo) : mask space"
	);
}

void		test_parse_flag_case4(void)
{
	printf(KYEL "test_parse_flag_case4\n" KNRM);
	const char	*format = "0foo";
	t_fp_tags	tags;

	tags.mask = 0;

	test(
		fp_parse_flag(format, &tags) == 1,
		"flag (0foo) : return value"
	);

	test(
		tags.mask == FP_MASK_FLAG_ZERO,
		"flag (0foo) : mask space"
	);
}

void		test_parse_flag_case5(void)
{
	printf(KYEL "test_parse_flag_case5\n" KNRM);
	const char	*format = "foo";
	t_fp_tags	tags;

	tags.mask = 0;
	test(
		fp_parse_flag(format, &tags) == 0,
		"flag (foo) : return value"
	);

	test(
		tags.mask == 0,
		"flag (foo) : mask"
	);
}

// case #
void		test_parse_flag_case6(void)
{
	printf(KYEL "test_parse_flag_case6\n" KNRM);
	const char	*format = "#foo";
	t_fp_tags	tags;

	tags.mask = 0;
	test(
		fp_parse_flag(format, &tags) == 1,
		"flag (#foo) : return value"
	);

	test(
		tags.mask == FP_MASK_FLAG_SHARP,
		"flag (#foo) : mask"
	);
}
