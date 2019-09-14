#include "ft_printf.test.h"

int		main(void)
{
	// tags
	test_init_tags_case1();

	test_parse_flag_case1();
	test_parse_flag_case2();
	test_parse_flag_case3();
	test_parse_flag_case4();
	test_parse_flag_case5();

	test_parse_width_case1();
	test_parse_width_case2();

	test_parse_precision_case1();
	test_parse_precision_case2();
	test_parse_precision_case3();

	test_parse_length_case1();
	test_parse_length_case2();
	test_parse_length_case3();
	test_parse_length_case4();
	test_parse_length_case5();
	test_parse_length_case6();
	return (0);
}
