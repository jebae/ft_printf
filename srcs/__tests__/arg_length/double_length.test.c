#include "ft_printf.test.h"

void		test_double_int_part_length_case1(void)
{
	printf(KYEL "test_double_int_part_length_case1\n" KNRM);
	double		d = 3.14;

	test(
		fp_double_int_part_length(d) == 1,
		"double_int_part_length (3.14) : return value"
	);
}

void		test_double_int_part_length_case2(void)
{
	printf(KYEL "test_double_int_part_length_case2\n" KNRM);
	double		d = -3.14;

	test(
		fp_double_int_part_length(d) == 1,
		"double_int_part_length (-3.14) : return value"
	);
}

void		test_double_int_part_length_case3(void)
{
	printf(KYEL "test_double_int_part_length_case3\n" KNRM);
	double		d = 0.1231231;

	test(
		fp_double_int_part_length(d) == 1,
		"double_int_part_length (0.1231231) : return value"
	);
}

void		test_double_int_part_length_case4(void)
{
	printf(KYEL "test_double_int_part_length_case4\n" KNRM);
	double		d = -0.1231231;

	test(
		fp_double_int_part_length(d) == 1,
		"double_int_part_length (-0.1231231) : return value"
	);
}

void		test_double_int_part_length_case5(void)
{
	printf(KYEL "test_double_int_part_length_case5\n" KNRM);
	double		d = -0.00231231;

	test(
		fp_double_int_part_length(d) == 1,
		"double_int_part_length (-0.00231231) : return value"
	);
}

void		test_double_int_part_length_case6(void)
{
	printf(KYEL "test_double_int_part_length_case6\n" KNRM);
	double		d = -2000000000000000000000000000000000000000000000000.0;

	test(
		fp_double_int_part_length(d) == 49,
		"double_int_part_length (-2000000000000000000000000000000000000000000000000.0) : return value"
	);
}

void		test_ldouble_int_part_length_case1(void)
{
	printf(KYEL "test_ldouble_int_part_length_case1\n" KNRM);
	long double	d = 3.14;

	test(
		fp_ldouble_int_part_length(d) == 1,
		"double_int_part_length (3.14) : return value"
	);
}

void		test_ldouble_int_part_length_case2(void)
{
	printf(KYEL "test_ldouble_int_part_length_case2\n" KNRM);
	long double	d = -3.14;

	test(
		fp_ldouble_int_part_length(d) == 1,
		"double_int_part_length (-3.14) : return value"
	);
}

void		test_ldouble_int_part_length_case3(void)
{
	printf(KYEL "test_ldouble_int_part_length_case3\n" KNRM);
	long double	d = 0.1231231;

	test(
		fp_ldouble_int_part_length(d) == 1,
		"double_int_part_length (0.1231231) : return value"
	);
}

void		test_ldouble_int_part_length_case4(void)
{
	printf(KYEL "test_ldouble_int_part_length_case4\n" KNRM);
	long double	d = -0.1231231;

	test(
		fp_ldouble_int_part_length(d) == 1,
		"double_int_part_length (-0.1231231) : return value"
	);
}

void		test_ldouble_int_part_length_case5(void)
{
	printf(KYEL "test_ldouble_int_part_length_case5\n" KNRM);
	long double	d = -0.00231231;

	test(
		fp_ldouble_int_part_length(d) == 1,
		"double_int_part_length (-0.00231231) : return value"
	);
}

void		test_ldouble_int_part_length_case6(void)
{
	printf(KYEL "test_ldouble_int_part_length_case6\n" KNRM);
	long double	d = -2000000000000000000000000000000000000000000000000.0;

	test(
		fp_ldouble_int_part_length(d) == 49,
		"double_int_part_length (-2000000000000000000000000000000000000000000000000.0) : return value"
	);
}
