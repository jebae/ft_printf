#include "ft_printf.test.h"

void		test_handle_flag_case1(void)
{
	const char	*format = "-dummy";
	t_tags		tags;

	printf(KYEL "test_handle_flag_case1\n" KNRM);

	test(
		handle_flag(format, &tags) == 1,
		"handle flag (-) : return value of handle_flag"
	);
	test(
		tags.flag == PRTF_FLAG_MINUS,
		"handle flag (-) : tags.flag"
	);
	test(
		(tags.bit_mask & PRTF_BIT_MASK_FLAG) != 0,
		"handle flag (-) : tags.bit_mask"
	);
}

void		test_handle_flag_case2(void)
{
	const char	*format = "+dummy";
	t_tags		tags;

	printf(KYEL "test_handle_flag_case2\n" KNRM);

	test(
		handle_flag(format, &tags) == 1,
		"handle flag (+) : return value of handle_flag"
	);
	test(
		tags.flag == PRTF_FLAG_PLUS,
		"handle flag (+) : tags.flag"
	);
	test(
		(tags.bit_mask & PRTF_BIT_MASK_FLAG) != 0,
		"handle flag (+) : tags.bit_mask"
	);
}

void		test_handle_flag_case3(void)
{
	const char	*format = " dummy";
	t_tags		tags;

	printf(KYEL "test_handle_flag_case3\n" KNRM);

	test(
		handle_flag(format, &tags) == 1,
		"handle flag (space) : return value of handle_flag"
	);
	test(
		tags.flag == PRTF_FLAG_SPACE,
		"handle flag (space) : tags.flag"
	);
	test(
		(tags.bit_mask & PRTF_BIT_MASK_FLAG) != 0,
		"handle flag (space) : tags.bit_mask"
	);
}

void		test_handle_flag_case4(void)
{
	const char	*format = "0dummy";
	t_tags		tags;

	printf(KYEL "test_handle_flag_case4\n" KNRM);

	test(
		handle_flag(format, &tags) == 1,
		"handle flag (0) : return value of handle_flag"
	);
	test(
		tags.flag == PRTF_FLAG_ZERO,
		"handle flag (0) : tags.flag"
	);
	test(
		(tags.bit_mask & PRTF_BIT_MASK_FLAG) != 0,
		"handle flag (0) : tags.bit_mask"
	);
}

void		test_handle_flag_case5(void)
{
	const char	*format = "dummy";
	t_tags		tags;

	printf(KYEL "test_handle_flag_case5\n" KNRM);

	test(
		handle_flag(format, &tags) == 0,
		"handle flag (no flag) : return value of handle_flag"
	);
	test(
		(tags.bit_mask & PRTF_BIT_MASK_FLAG) == 0,
		"handle flag (no flag) : tags.bit_mask"
	);
}
