#include "ft_printf.test.h"

// case 3.14
void		test_arg_e_write_case1(void)
{
	printf(KYEL "test_arg_e_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = 3.14e0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "3.140000e+00") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 1.23456789e4
void		test_arg_e_write_case2(void)
{
	printf(KYEL "test_arg_e_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = 1.23456789e4;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.234568e+04") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e5
void		test_arg_e_write_case3(void)
{
	printf(KYEL "test_arg_e_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = 9.9999999999999999e5;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.000000e+06") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e-100
void		test_arg_e_write_case4(void)
{
	printf(KYEL "test_arg_e_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = 9.9999999999999999e-100;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.000000e-99") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e-101
void		test_arg_e_write_case5(void)
{
	printf(KYEL "test_arg_e_write_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = 9.9999999999999999e-101;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.000000e-100") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 1.234512345e-100
void		test_arg_e_write_case6(void)
{
	printf(KYEL "test_arg_e_write_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float64 = 1.234512345e-100;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.23451234500000002341494097567158214689484065859570e-100") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0
void		test_arg_e_write_case7(void)
{
	printf(KYEL "test_arg_e_write_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 5;
	data.f.float64 = 0.0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "0.00000e+00") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e99, precision 0
void		test_arg_e_write_case8(void)
{
	printf(KYEL "test_arg_e_write_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	data.f.float64 = 9.999e99;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1e+100") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e-100, precision 0
void		test_arg_e_write_case9(void)
{
	printf(KYEL "test_arg_e_write_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	data.f.float64 = 9.999e-100;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1e-99") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e-100, precision 0, #
void		test_arg_e_write_case10(void)
{
	printf(KYEL "test_arg_e_write_case10\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float64 = 9.999e-100;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.e-99") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0, precision 0, #
void		test_arg_e_write_case11(void)
{
	printf(KYEL "test_arg_e_write_case11\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float64 = 0.0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "0.e+00") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e100
void		test_arg_e_write_case12(void)
{
	printf(KYEL "test_arg_e_write_case12\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = 9.999e100;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "9.999000e+100") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e100
void		test_arg_e_write_case13(void)
{
	printf(KYEL "test_arg_e_write_case13\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float64 = 9.999e100;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.00e+101") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e99
void		test_arg_e_write_case14(void)
{
	printf(KYEL "test_arg_e_write_case14\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float64 = 9.999e99;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.00e+100") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case nan
void		test_arg_e_write_case15(void)
{
	printf(KYEL "test_arg_e_write_case15\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float64 = NAN;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "nan") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case inf
void		test_arg_e_write_case16(void)
{
	printf(KYEL "test_arg_e_write_case16\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float64 = INFINITY;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_scientific_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_e_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "inf") == 0,
		"arg_e_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 3.14
void		test_arg_le_write_case1(void)
{
	printf(KYEL "test_arg_le_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = 3.14e0L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "3.140000e+00") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 1.23456789e4
void		test_arg_le_write_case2(void)
{
	printf(KYEL "test_arg_le_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = 1.23456789e4L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.234568e+04") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e5
void		test_arg_le_write_case3(void)
{
	printf(KYEL "test_arg_le_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = 9.9999999999999999e5L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.000000e+06") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e-100
void		test_arg_le_write_case4(void)
{
	printf(KYEL "test_arg_le_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = 9.9999999999999999e-100L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.000000e-99") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.9999999999999999e-101
void		test_arg_le_write_case5(void)
{
	printf(KYEL "test_arg_le_write_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = 9.9999999999999999e-101L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.000000e-100") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 1.234512345e-100
void		test_arg_le_write_case6(void)
{
	printf(KYEL "test_arg_le_write_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float128 = 1.234512345e-100L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.23451234499999999999350507466290523289139138847985e-100") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0
void		test_arg_le_write_case7(void)
{
	printf(KYEL "test_arg_le_write_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 5;
	data.f.float128 = 0.0L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "0.00000e+00") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e99, precision 0
void		test_arg_le_write_case8(void)
{
	printf(KYEL "test_arg_le_write_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	data.f.float128 = 9.999e99L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1e+100") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e-100, precision 0
void		test_arg_le_write_case9(void)
{
	printf(KYEL "test_arg_le_write_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	data.f.float128 = 9.999e-100L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1e-99") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e-100, precision 0, #
void		test_arg_le_write_case10(void)
{
	printf(KYEL "test_arg_le_write_case10\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float128 = 9.999e-100L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.e-99") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0, precision 0, #
void		test_arg_le_write_case11(void)
{
	printf(KYEL "test_arg_le_write_case11\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float128 = 0.0L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "0.e+00") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e100
void		test_arg_le_write_case12(void)
{
	printf(KYEL "test_arg_le_write_case12\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = 9.999e100L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "9.999000e+100") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e100
void		test_arg_le_write_case13(void)
{
	printf(KYEL "test_arg_le_write_case13\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float128 = 9.999e100L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.00e+101") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 9.999e99
void		test_arg_le_write_case14(void)
{
	printf(KYEL "test_arg_le_write_case14\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float128 = 9.999e99L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "1.00e+100") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case nan
void		test_arg_le_write_case15(void)
{
	printf(KYEL "test_arg_le_write_case15\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float128 = (long double)NAN;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "nan") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case inf
void		test_arg_le_write_case16(void)
{
	printf(KYEL "test_arg_le_write_case16\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float128 = HUGE_VALL;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_scientific_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);

	fp_arg_le_write(&data, &tags, 0, &buf);

	test(
		ft_strcmp(buf.data, "inf") == 0,
		"arg_le_write : buf.data"
	);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}
