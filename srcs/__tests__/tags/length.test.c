#include "ft_printf.test.h"

void	test_parse_length_case1(void)
{
	printf(KYEL "test_parse_length_case1\n" KNRM);

	const char	*format = "hhd";
	t_fp_tags	tags;

	tags.mask = 0;
	
	test(
		fp_parse_length(format, &tags) == 2,
		"length (hh) : return value"
	);

	test(
		tags.mask == FP_MASK_LENGTH_HH,
		"length (hh) : mask hh"
	);
}

void	test_parse_length_case2(void)
{
	printf(KYEL "test_parse_length_case2\n" KNRM);

	const char	*format = "hd";
	t_fp_tags	tags;

	tags.mask = 0;
	
	test(
		fp_parse_length(format, &tags) == 1,
		"length (h) : return value"
	);

	test(
		tags.mask == FP_MASK_LENGTH_H,
		"length (h) : mask h"
	);
}

void	test_parse_length_case3(void)
{
	printf(KYEL "test_parse_length_case3\n" KNRM);

	const char	*format = "ld";
	t_fp_tags	tags;

	tags.mask = 0;
	
	test(
		fp_parse_length(format, &tags) == 1,
		"length (l) : return value"
	);

	test(
		tags.mask == FP_MASK_LENGTH_L,
		"length (l) : mask l"
	);
}

void	test_parse_length_case4(void)
{
	printf(KYEL "test_parse_length_case4\n" KNRM);

	const char	*format = "lld";
	t_fp_tags	tags;

	tags.mask = 0;
	
	test(
		fp_parse_length(format, &tags) == 2,
		"length (ll) : return value"
	);

	test(
		tags.mask == FP_MASK_LENGTH_LL,
		"length (ll) : mask ll"
	);
}

void	test_parse_length_case5(void)
{
	printf(KYEL "test_parse_length_case5\n" KNRM);

	const char	*format = "Ld";
	t_fp_tags	tags;

	tags.mask = 0;
	
	test(
		fp_parse_length(format, &tags) == 1,
		"length (L) : return value"
	);

	test(
		tags.mask == FP_MASK_LENGTH_FL,
		"length (L) : mask L"
	);
}

void	test_parse_length_case6(void)
{
	printf(KYEL "test_parse_length_case6\n" KNRM);

	const char	*format = "d";
	t_fp_tags	tags;

	tags.mask = 0;
	
	test(
		fp_parse_length(format, &tags) == 0,
		"length (d) : return value"
	);

	test(
		tags.mask == 0,
		"length (d) : return value"
	);
}
