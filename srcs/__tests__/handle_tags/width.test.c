#include "ft_printf.test.h"

void		test_handle_width_case1(void)
{
	const char	*format = "345.234234";
	t_tags		tags;

	printf(KYEL "test_handle_width_case1\n" KNRM);

	test(
		handle_width(format, &tags) == 3,
		"handle width : return value of handle_width"
	);
	test(
		tags.width == 345,
		"handle width : tags.width"
	);
	test(
		(tags.bit_mask & PRTF_BIT_MASK_WIDTH) != 0,
		"handle width : tags.bit_mask"
	);
}

void		test_handle_width_case1(void)
{
	const char	*format = "0.234234";
	t_tags		tags;

	printf(KYEL "test_handle_width_case1\n" KNRM);

	test(
		handle_width(format, &tags) == 3,
		"handle width : return value of handle_width"
	);
	test(
		tags.width == 345,
		"handle width : tags.width"
	);
	test(
		(tags.bit_mask & PRTF_BIT_MASK_WIDTH) != 0,
		"handle width : tags.bit_mask"
	);
}
