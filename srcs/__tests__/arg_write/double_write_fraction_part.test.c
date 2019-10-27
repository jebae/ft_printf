#include "ft_printf.test.h"

// case 3.14 with trailing zero
void		test_double_write_fraction_part_case1(void)
{
	printf(KYEL "test_double_write_fraction_part_case1\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 3.14;
	size_t				precision = 30;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 12345.6789 with trailing zero
void		test_double_write_fraction_part_case2(void)
{
	printf(KYEL "test_double_write_fraction_part_case2\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 12345.6789;
	size_t				precision = 30;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.6789 with trailing zero
void		test_double_write_fraction_part_case3(void)
{
	printf(KYEL "test_double_write_fraction_part_case3\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.6789;
	size_t				precision = 30;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 12345.0 with trailing zero
void		test_double_write_fraction_part_case4(void)
{
	printf(KYEL "test_double_write_fraction_part_case4\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 12345.0;
	size_t				precision = 30;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 0.123451234512345123451234512345 with trailing zero
void		test_double_write_fraction_part_case5(void)
{
	printf(KYEL "test_double_write_fraction_part_case5\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 0.123451234512345123451234512345;
	size_t				precision = 50;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 0.00000000000000000000000000000012345
void		test_double_write_fraction_part_case6(void)
{
	printf(KYEL "test_double_write_fraction_part_case6\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 0.00000000000000000000000000000012345;
	size_t				precision = 60;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.60f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case7(void)
{
	printf(KYEL "test_double_write_fraction_part_case7\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.6789;
	size_t				precision = 1;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.1f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case8(void)
{
	printf(KYEL "test_double_write_fraction_part_case8\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.6789;
	size_t				precision = 2;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.2f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case9(void)
{
	printf(KYEL "test_double_write_fraction_part_case9\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.6789;
	size_t				precision = 3;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.3f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case10(void)
{
	printf(KYEL "test_double_write_fraction_part_case10\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.6789;
	size_t				precision = 4;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.4f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case11(void)
{
	printf(KYEL "test_double_write_fraction_part_case11\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.6789;
	size_t				precision = 0;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case12(void)
{
	printf(KYEL "test_double_write_fraction_part_case12\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.000052345;
	size_t				precision = 1;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.1f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case13(void)
{
	printf(KYEL "test_double_write_fraction_part_case13\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.000052345;
	size_t				precision = 2;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.2f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case14(void)
{
	printf(KYEL "test_double_write_fraction_part_case14\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.000052345;
	size_t				precision = 3;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.3f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case15(void)
{
	printf(KYEL "test_double_write_fraction_part_case15\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.000052345;
	size_t				precision = 4;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.4f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case16(void)
{
	printf(KYEL "test_double_write_fraction_part_case16\n" KNRM);
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	double				num = 123000.000052345;
	size_t				precision = 5;

	fxp_init(&fraction_part);
	fxp_init(&int_part);
	fp_init_buffer(&buf);
	fp_get_double_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.5f\n", num);

	fxp_del(&fraction_part);
	fxp_del(&int_part);
}
