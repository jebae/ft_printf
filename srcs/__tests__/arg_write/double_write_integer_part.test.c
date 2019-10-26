#include "ft_printf.test.h"

// case 3.14
void		test_double_write_integer_part_case1(void)
{
	printf(KYEL "test_double_write_integer_part_case1\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	short				exponent;
	unsigned long long	mantissa;

	fxp_init(&int_part);
	fp_init_buffer(&buf);
	exponent = 1;
	mantissa = 0x191eb851eb851f;
	fp_double_get_integer_part(exponent, mantissa, 0, &int_part);

	fp_double_write_integer_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 3.14);

	fxp_del(&int_part);
}

// case 12345.6789 with carry
void		test_double_write_integer_part_case2(void)
{
	printf(KYEL "test_double_write_integer_part_case2\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	short				exponent;
	unsigned long long	mantissa;

	fxp_init(&int_part);
	fp_init_buffer(&buf);
	exponent = 13;
	mantissa = 0x181cd6e631f8a1;
	fp_double_get_integer_part(exponent, mantissa, 1, &int_part);

	fp_double_write_integer_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", 12345.6789);

	fxp_del(&int_part);
}

// case 123000.6789 with carry
void		test_double_write_integer_part_case3(void)
{
	printf(KYEL "test_double_write_integer_part_case3\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	short				exponent;
	unsigned long long	mantissa;

	fxp_init(&int_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	fp_double_get_integer_part(exponent, mantissa, 1, &int_part);

	fp_double_write_integer_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", 123000.6789);

	fxp_del(&int_part);
}

// case 0
void		test_double_write_integer_part_case4(void)
{
	printf(KYEL "test_double_write_integer_part_case4\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	short				exponent;
	unsigned long long	mantissa;

	fxp_init(&int_part);
	fp_init_buffer(&buf);
	exponent = -4;
	mantissa = 0x1f972474538ef3;
	fp_double_get_integer_part(exponent, mantissa, 0, &int_part);

	fp_double_write_integer_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 0.1234);

	fxp_del(&int_part);
}

// case big 1234512345123451234512345.12345
void		test_double_write_integer_part_case5(void)
{
	printf(KYEL "test_double_write_integer_part_case5\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	short				exponent;
	unsigned long long	mantissa;

	fxp_init(&int_part);
	fp_init_buffer(&buf);
	exponent = 80;
	mantissa = 0x1056b0c5f2b0d3;
	fp_double_get_integer_part(exponent, mantissa, 0, &int_part);

	fp_double_write_integer_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 1234512345123451234512345.12345);

	fxp_del(&int_part);
}

// case 12345000000.123
void		test_double_write_integer_part_case6(void)
{
	printf(KYEL "test_double_write_integer_part_case6\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	short				exponent;
	unsigned long long	mantissa;

	fxp_init(&int_part);
	fp_init_buffer(&buf);
	exponent = 33;
	mantissa = 0x16fe8e0200fbe7;
	fp_double_get_integer_part(exponent, mantissa, 0, &int_part);

	fp_double_write_integer_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 12345000000.123);

	fxp_del(&int_part);
}

// case 9999.999
void		test_double_write_integer_part_case7(void)
{
	printf(KYEL "test_double_write_integer_part_case7\n" KNRM);
	t_fp_buffer			buf;
	t_fixedpoint		int_part;
	short				exponent;
	unsigned long long	mantissa;

	fxp_init(&int_part);
	fp_init_buffer(&buf);
	exponent = 13;
	mantissa = 0x1387ffdf3b645a;
			
	fp_double_get_integer_part(exponent, mantissa, 1, &int_part);

	fp_double_write_integer_part(&int_part, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", 9999.999);

	fxp_del(&int_part);
}

