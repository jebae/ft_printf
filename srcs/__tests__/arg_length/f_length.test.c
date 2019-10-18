#include "ft_printf.test.h"

void		test_arg_f_length_case1(void)
{
	printf(KYEL "test_arg_f_length_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f = 3.141592;
	tags.precision = 3;

	test(
		fp_arg_f_length(&data, &tags) == 5,
		"arg_f_length (3.141592 (precision : 3)) : return value"
	);
}

void		test_arg_f_length_case2(void)
{
	printf(KYEL "test_arg_f_length_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f = 13.141592;
	tags.precision = 3;

	test(
		fp_arg_f_length(&data, &tags) == 6,
		"arg_f_length (13.141592 (precision : 3)) : return value"
	);
}

void		test_arg_f_length_case3(void)
{
	printf(KYEL "test_arg_f_length_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f = -13.141592;
	tags.precision = 3;

	test(
		fp_arg_f_length(&data, &tags) == 6,
		"arg_f_length (-13.141592 (precision : 3)) : return value"
	);
}

void		test_arg_f_length_case4(void)
{
	printf(KYEL "test_arg_f_length_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f = -13.141592;
	tags.precision = 0;

	test(
		fp_arg_f_length(&data, &tags) == 2,
		"arg_f_length (-13.141592 (precision : 0)) : return value"
	);
}

void		test_arg_f_length_case5(void)
{
	printf(KYEL "test_arg_f_length_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f = -2000000000000000000000000000000000000000000000000.2342344;
	tags.precision = 4;

	test(
		fp_arg_f_length(&data, &tags) == 54,
		"arg_f_length (-2000000000000000000000000000000000000000000000000.2342344 (precision : 4)) : return value"
	);
}

// case inf
void		test_arg_f_length_case6(void)
{
	printf(KYEL "test_arg_f_length_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f = INFINITY;
	tags.precision = 4;

	test(
		fp_arg_f_length(&data, &tags) == 3,
		"arg_f_length (inf) : return value"
	);
}

// case nan
void		test_arg_f_length_case7(void)
{
	printf(KYEL "test_arg_f_length_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f = NAN;
	tags.precision = 4;

	test(
		fp_arg_f_length(&data, &tags) == 3,
		"arg_f_length (nan) : return value"
	);
}

void		test_arg_lf_length_case1(void)
{
	printf(KYEL "test_arg_lf_length_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.lf = (long double)3.141592;
	tags.precision = 3;

	test(
		fp_arg_lf_length(&data, &tags) == 5,
		"arg_lf_length (3.141592 (precision : 3)) : return value"
	);
}

void		test_arg_lf_length_case2(void)
{
	printf(KYEL "test_arg_lf_length_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.lf = (long double)13.141592;
	tags.precision = 3;

	test(
		fp_arg_lf_length(&data, &tags) == 6,
		"arg_lf_length (13.141592 (precision : 3)) : return value"
	);
}

void		test_arg_lf_length_case3(void)
{
	printf(KYEL "test_arg_lf_length_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.lf = (long double)-13.141592;
	tags.precision = 3;

	test(
		fp_arg_lf_length(&data, &tags) == 6,
		"arg_lf_length (-13.141592 (precision : 3)) : return value"
	);
}

void		test_arg_lf_length_case4(void)
{
	printf(KYEL "test_arg_lf_length_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.lf = (long double)-13.141592;
	tags.precision = 0;

	test(
		fp_arg_lf_length(&data, &tags) == 2,
		"arg_lf_length (-13.141592 (precision : 0)) : return value"
	);
}

void		test_arg_lf_length_case5(void)
{
	printf(KYEL "test_arg_lf_length_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.lf = (long double)-2000000000000000000000000000000000000000000000000.2342344;
	tags.precision = 4;

	test(
		fp_arg_lf_length(&data, &tags) == 54,
		"arg_lf_length (-2000000000000000000000000000000000000000000000000.2342344 (precision : 4)) : return value"
	);
}
