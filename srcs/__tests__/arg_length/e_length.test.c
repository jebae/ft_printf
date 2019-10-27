#include "ft_printf.test.h"

// case 3.14e0
void		test_arg_e_length_case1(void)
{
	printf(KYEL "test_arg_e_length_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 3;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 3.14e0;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 9, // 3.140e+00
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 1.23456789e4
void		test_arg_e_length_case2(void)
{
	printf(KYEL "test_arg_e_length_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 6;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 1.23456789e4;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 12, // 1.234568e+04
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e5
void		test_arg_e_length_case3(void)
{
	printf(KYEL "test_arg_e_length_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 6;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.9999999999999999e5;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 12, // 1.000000e+06
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e-100
void		test_arg_e_length_case4(void)
{
	printf(KYEL "test_arg_e_length_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 6;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.9999999999999999e-100;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 12, // 1.000000e-99
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e-101
void		test_arg_e_length_case5(void)
{
	printf(KYEL "test_arg_e_length_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 6;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.9999999999999999e-101;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 13, // 1.000000e-100
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 1.234512345e-100
void		test_arg_e_length_case6(void)
{
	printf(KYEL "test_arg_e_length_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 100;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 1.234512345e-100;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 107, // 1.2345123450000000234149409756715821468948406585957017898832694458312562692216847109422605739139955382e-100
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0
void		test_arg_e_length_case7(void)
{
	printf(KYEL "test_arg_e_length_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 5;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 0.0;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 11, // 0.00000e+00
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e99, precision 0
void		test_arg_e_length_case8(void)
{
	printf(KYEL "test_arg_e_length_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 0;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.999e99;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 6, // 1e+100
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e-100, precision 0
void		test_arg_e_length_case9(void)
{
	printf(KYEL "test_arg_e_length_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 0;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.999e-100;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 5, // 1e-99
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e-100, precision 0, #
void		test_arg_e_length_case10(void)
{
	printf(KYEL "test_arg_e_length_case10\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.999e-100;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 6, // 1.e-99
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0, precision 0, #
void		test_arg_e_length_case11(void)
{
	printf(KYEL "test_arg_e_length_case11\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 0.0;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 6, // 0.e+00
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e100
void		test_arg_e_length_case12(void)
{
	printf(KYEL "test_arg_e_length_case12\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 6;

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.999e100;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 13, // 9.999000e+100
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e100
void		test_arg_e_length_case13(void)
{
	printf(KYEL "test_arg_e_length_case13\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 2;
	tags.mask |= FP_MASK_FLAG_SHARP; // trick !!

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.999e100;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 9, // 1.00e+101
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e99
void		test_arg_e_length_case14(void)
{
	printf(KYEL "test_arg_e_length_case14\n" KNRM);
	t_fp_arg_data	data;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	tags.precision = 2;
	tags.mask |= FP_MASK_FLAG_SHARP; // trick !!

	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	data.f.float64 = 9.999e99;

	fp_get_double_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	test(
		fp_arg_e_length(&data, &tags) == 9, // 1.00e+100
		"arg_e_length : return value"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}
