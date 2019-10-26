#include "ft_printf.test.h"

void		test_arg_f_length_case1(void)
{
	printf(KYEL "test_arg_f_length_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = 3.141592;
	fp_init_tags(&tags);
	tags.precision = 3;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 5,
		"arg_f_length (3.141592 (precision : 3)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_f_length_case2(void)
{
	printf(KYEL "test_arg_f_length_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = 13.141592;
	fp_init_tags(&tags);
	tags.precision = 3;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 6,
		"arg_f_length (13.141592 (precision : 3)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_f_length_case3(void)
{
	printf(KYEL "test_arg_f_length_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = -13.141592;
	fp_init_tags(&tags);
	tags.precision = 3;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 6,
		"arg_f_length (-13.141592 (precision : 3)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_f_length_case4(void)
{
	printf(KYEL "test_arg_f_length_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = -13.141592;
	fp_init_tags(&tags);
	tags.precision = 0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 2,
		"arg_f_length (-13.141592 (precision : 0)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_f_length_case5(void)
{
	printf(KYEL "test_arg_f_length_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = -2000000000000000000000000000000000000000000000000.2342344;
	fp_init_tags(&tags);
	tags.precision = 4;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 54,
		"arg_f_length (-2000000000000000000000000000000000000000000000000.2342344 (precision : 4)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case inf
void		test_arg_f_length_case6(void)
{
	printf(KYEL "test_arg_f_length_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = INFINITY;
	fp_init_tags(&tags);
	tags.precision = 4;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 3,
		"arg_f_length (inf) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case nan
void		test_arg_f_length_case7(void)
{
	printf(KYEL "test_arg_f_length_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	data.f.float64 = NAN;
	fp_init_tags(&tags);
	tags.precision = 4;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 3,
		"arg_f_length (nan) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case #
void		test_arg_f_length_case8(void)
{
	printf(KYEL "test_arg_f_length_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = 123.14;
	fp_init_tags(&tags);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 4,
		"arg_f_length (#) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 99.999, precision 2
void		test_arg_f_length_case9(void)
{
	printf(KYEL "test_arg_f_length_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float64 = 99.999;
	fp_init_tags(&tags);
	tags.precision = 2;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_double_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_f_length(&data, &tags) == 6,
		"arg_f_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_lf_length_case1(void)
{
	printf(KYEL "test_arg_lf_length_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

   	data.f.float128	= 3.141592L;
	fp_init_tags(&tags);
	tags.precision = 3;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 5,
		"arg_lf_length (3.141592 (precision : 3)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_lf_length_case2(void)
{
	printf(KYEL "test_arg_lf_length_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

   	data.f.float128	= 13.141592L;
	fp_init_tags(&tags);
	tags.precision = 3;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 6,
		"arg_lf_length (13.141592 (precision : 3)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_lf_length_case3(void)
{
	printf(KYEL "test_arg_lf_length_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

   	data.f.float128	= -13.141592L;
	fp_init_tags(&tags);
	tags.precision = 3;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 6,
		"arg_lf_length (-13.141592 (precision : 3)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_lf_length_case4(void)
{
	printf(KYEL "test_arg_lf_length_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

   	data.f.float128	= -13.141592L;
	fp_init_tags(&tags);
	tags.precision = 0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 2,
		"arg_lf_length (-13.141592 (precision : 0)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

void		test_arg_lf_length_case5(void)
{
	printf(KYEL "test_arg_lf_length_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

   	data.f.float128	= -2000000000000000000000000000000000000000000000000.2342344L;
	fp_init_tags(&tags);
	tags.precision = 4;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 54,
		"arg_lf_length (-2000000000000000000000000000000000000000000000000.2342344 (precision : 4)) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case inf
void		test_arg_lf_length_case6(void)
{
	printf(KYEL "test_arg_lf_length_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

   	data.f.float128	= HUGE_VALL;
	fp_init_tags(&tags);
	tags.precision = 4;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 3,
		"arg_lf_length (inf) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case nan
void		test_arg_lf_length_case7(void)
{
	printf(KYEL "test_arg_lf_length_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

   	data.f.float128	= (long double)NAN;
	fp_init_tags(&tags);
	tags.precision = 4;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 3,
		"arg_lf_length (nan) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}


// case #
void		test_arg_lf_length_case8(void)
{
	printf(KYEL "test_arg_lf_length_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float128 = 123.14L;
	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_SHARP;
	tags.precision = 0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 4,
		"arg_lf_length (#) : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 99.999, precision 2
void		test_arg_lf_length_case9(void)
{
	printf(KYEL "test_arg_lf_length_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	data.f.float128 = 99.999L;
	fp_init_tags(&tags);
	tags.precision = 0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_set_ldouble_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_lf_length(&data, &tags) == 3,
		"arg_lf_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}
