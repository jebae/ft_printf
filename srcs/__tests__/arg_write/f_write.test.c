#include "ft_printf.test.h"

// case 3.14
void		test_arg_f_write_case1(void)
{
	printf(KYEL "test_arg_f_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = 3.14;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", data.f.float64);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case negative
void		test_arg_f_write_case2(void)
{
	printf(KYEL "test_arg_f_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float64 = -3.14;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %f\n", data.f.float64);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case precision = 50
void		test_arg_f_write_case3(void)
{
	printf(KYEL "test_arg_f_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float64 = 9.87654321;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f.float64);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case precision = 0
void		test_arg_f_write_case4(void)
{
	printf(KYEL "test_arg_f_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	data.f.float64 = 9.87654321;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", data.f.float64);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0
void		test_arg_f_write_case5(void)
{
	printf(KYEL "test_arg_f_write_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float64 = 0.0;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f.float64);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case inf
void		test_arg_f_write_case6(void)
{
	printf(KYEL "test_arg_f_write_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float64 = INFINITY;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f.float64);
}

// case -inf
void		test_arg_f_write_case7(void)
{
	printf(KYEL "test_arg_f_write_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float64 = -INFINITY;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %.50f\n", data.f.float64);
}

// case nan
void		test_arg_f_write_case8(void)
{
	printf(KYEL "test_arg_f_write_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float64 = NAN;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f.float64);
}

// case #
void		test_arg_f_write_case9(void)
{
	printf(KYEL "test_arg_f_write_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float64 = 3.14;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %#.f\n", data.f.float64);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case # (nan)
void		test_arg_f_write_case10(void)
{
	printf(KYEL "test_arg_f_write_case10\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float64 = NAN;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %#.f\n", data.f.float64);
}

// case # (inf)
void		test_arg_f_write_case11(void)
{
	printf(KYEL "test_arg_f_write_case11\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float64 = INFINITY;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %#.f\n", data.f.float64);
}

// case carry
void		test_arg_f_write_case12(void)
{
	printf(KYEL "test_arg_f_write_case12\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float64 = 99.997;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_double_get_parts(data.f.float64, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.2f\n", data.f.float64);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 3.14
void		test_arg_lf_write_case1(void)
{
	printf(KYEL "test_arg_lf_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = 3.14L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %Lf\n", data.f.float128);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case negative
void		test_arg_lf_write_case2(void)
{
	printf(KYEL "test_arg_lf_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f.float128 = -3.14L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %Lf\n", data.f.float128);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case precision = 50
void		test_arg_lf_write_case3(void)
{
	printf(KYEL "test_arg_lf_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float128 = 9.87654321L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", data.f.float128);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case precision = 0
void		test_arg_lf_write_case4(void)
{
	printf(KYEL "test_arg_lf_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 0;
	data.f.float128 = 9.87654321L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0Lf\n", data.f.float128);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case 0
void		test_arg_lf_write_case5(void)
{
	printf(KYEL "test_arg_lf_write_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float128 = 0.0L;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", data.f.float128);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case inf
void		test_arg_lf_write_case6(void)
{
	printf(KYEL "test_arg_lf_write_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float128 = HUGE_VALL;
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", data.f.float128);
}

// case -inf
void		test_arg_lf_write_case7(void)
{
	printf(KYEL "test_arg_lf_write_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float128 = -HUGE_VALL;
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %.50Lf\n", data.f.float128);
}

// case nan
void		test_arg_lf_write_case8(void)
{
	printf(KYEL "test_arg_lf_write_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f.float128 = (long double)NAN;
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", data.f.float128);
}

// case #
void		test_arg_lf_write_case9(void)
{
	printf(KYEL "test_arg_lf_write_case9\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float128 = 3.14;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %#.Lf\n", data.f.float128);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}

// case # (nan)
void		test_arg_lf_write_case10(void)
{
	printf(KYEL "test_arg_lf_write_case10\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float128 = (long double)NAN;
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %#.Lf\n", data.f.float128);
}

// case # (inf)
void		test_arg_lf_write_case11(void)
{
	printf(KYEL "test_arg_lf_write_case11\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 0;
	tags.mask |= FP_MASK_FLAG_SHARP;
	data.f.float128 = HUGE_VALL;
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %#.Lf\n", data.f.float128);
}

// case carry
void		test_arg_lf_write_case12(void)
{
	printf(KYEL "test_arg_lf_write_case12\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	tags.precision = 2;
	data.f.float128 = 999.995;
	fxp_init(&data.f.int_part);
	fxp_init(&data.f.fraction_part);
	fp_ldouble_get_parts(data.f.float128, tags.precision,
		&data.f.int_part, &data.f.fraction_part);
	fp_arg_lf_write(&data, &tags, fp_arg_lf_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.2Lf\n", data.f.float128);

	fxp_del(&data.f.int_part);
	fxp_del(&data.f.fraction_part);
}
