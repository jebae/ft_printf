#include "ft_printf.test.h"

// case 3.14
void		test_double_write_int_part_case1(void)
{
	printf(KYEL "test_double_write_int_part_case1\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	double				num = 3.14;
	size_t				precision = 6;

	fxp_init(&int_part);
	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	fp_double_get_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_int_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", num);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case 12345.6789 with carry
void		test_double_write_int_part_case2(void)
{
	printf(KYEL "test_double_write_int_part_case2\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	double				num = 12345.6789;
	size_t				precision = 0;

	fxp_init(&int_part);
	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	fp_double_get_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_int_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", num);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case 123000.6789 with carry
void		test_double_write_int_part_case3(void)
{
	printf(KYEL "test_double_write_int_part_case3\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	double				num = 123000.6789;
	size_t				precision = 0;

	fxp_init(&int_part);
	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	fp_double_get_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_int_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", num);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case 0
void		test_double_write_int_part_case4(void)
{
	printf(KYEL "test_double_write_int_part_case4\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	double				num = 0.0;
	size_t				precision = 6;

	fxp_init(&int_part);
	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	fp_double_get_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_int_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", num);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case big 1234512345123451234512345.12345
void		test_double_write_int_part_case5(void)
{
	printf(KYEL "test_double_write_int_part_case5\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	double				num = 1234512345123451234512345.12345;
	size_t				precision = 6;

	fxp_init(&int_part);
	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	fp_double_get_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_int_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", num);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case 12345000000.123
void		test_double_write_int_part_case6(void)
{
	printf(KYEL "test_double_write_int_part_case6\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	double				num = 12345000000.123;
	size_t				precision = 6;

	fxp_init(&int_part);
	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	fp_double_get_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_int_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", num);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case 9999.999
void		test_double_write_int_part_case7(void)
{
	printf(KYEL "test_double_write_int_part_case7\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;
	double				num = 9999.999;
	size_t				precision = 0;

	fxp_init(&int_part);
	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
			
	fp_double_get_parts(num, precision, &int_part, &fraction_part);

	fp_double_write_int_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", num);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

