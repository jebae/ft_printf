#include "ft_printf.test.h"

void		test_init_tags_case1(void)
{
	printf(KYEL "test_init_tags1\n" KNRM);
	t_fp_tags	tags;

	fp_init_tags(&tags);

	test(
		tags.width == 0,
		"init_tags : tags.width"
	);
	
	test(
		tags.precision == 6,
		"init_tags : tags.width"
	);

	test(
		tags.mask == 0,
		"init_tags : tags.width"
	);
}
