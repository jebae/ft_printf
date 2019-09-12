#include <stdio.h>

int		main(void)
{
	/*
	// handle_tags
	test_handle_flag_case1();
	test_handle_flag_case2();
	test_handle_flag_case3();
	test_handle_flag_case4();
	test_handle_flag_case5();
	*/

	int		res;

	res = printf("%-+10d$\n", 123);
	printf("res : %d\n", res);
	res = printf("%+-10d$\n", 123);
	printf("res : %d\n", res);
	res = printf("%--10d$\n", 123);
	printf("res : %d\n", res);
	res = printf("% 10d$\n", -123);
	printf("res : %d\n", res);
	return (0);
}
