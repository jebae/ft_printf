#include "ft_printf.test.h"

void		test_int_length_case1(void)
{
	printf(KYEL "test_int_length_case1\n" KNRM);
	int		d = 123;

	test(
		fp_int_length(d, 10) == 3,
		"int_length (func(123)) : return value"
	);
}

void		test_int_length_case2(void)
{
	printf(KYEL "test_int_length_case2\n" KNRM);
	int		d = -123;

	test(
		fp_int_length(d, 10) == 3,
		"int_length (func(-123)) : return value"
	);
}

void		test_int_length_case3(void)
{
	printf(KYEL "test_int_length_case3\n" KNRM);
	int		d = 0;

	test(
		fp_int_length(d, 10) == 1,
		"int_length (func(0)) : return value"
	);
}

void		test_int_length_case4(void)
{
	printf(KYEL "test_int_length_case4\n" KNRM);
	int		d = 10;

	test(
		fp_int_length(d, 10) == 2,
		"int_length (func(10)) : return value"
	);
}

void		test_int_length_case5(void)
{
	printf(KYEL "test_int_length_case5\n" KNRM);
	int		d = -10;

	test(
		fp_int_length(d, 10) == 2,
		"int_length (func(-10)) : return value"
	);
}

void		test_int_length_case6(void)
{
	printf(KYEL "test_int_length_case6\n" KNRM);
	int		d = -1;

	test(
		fp_int_length(d, 10) == 1,
		"int_length (func(-1)) : return value"
	);
}

void		test_int_length_case7(void)
{
	printf(KYEL "test_int_length_case7\n" KNRM);
	int		d = 1;

	test(
		fp_int_length(d, 10) == 1,
		"int_length (func(1)) : return value"
	);
}

// This test check if argument is typed to long long
void		test_int_length_case8(void)
{
	printf(KYEL "test_int_length_case8\n" KNRM);
	long		d = 2147483648;

	test(
		fp_int_length(d, 10) == 10,
		"int_length (func(2147483648)) : return value"
	);
}

void		test_int_length_case9(void)
{
	printf(KYEL "test_int_length_case9\n" KNRM);
	unsigned int	d = 0x2ffe;

	test(
		fp_int_length(d, 16) == 4,
		"int_length (hex) : return value"
	);
}

void		test_int_length_case10(void)
{
	printf(KYEL "test_int_length_case10\n" KNRM);
	unsigned int	d = 0xf1af0ffe;

	test(
		fp_int_length(d, 16) == 8,
		"int_length (hex) : return value"
	);
}
