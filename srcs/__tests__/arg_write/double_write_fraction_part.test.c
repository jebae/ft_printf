#include "ft_printf.test.h"

// case 3.14 with trailing zero
void		test_double_write_fraction_part_case1(void)
{
	printf(KYEL "test_double_write_fraction_part_case1\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 1;
	mantissa = 0x191eb851eb851f;
	precision = 30;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 3.14);

	fxp_del(&fraction_part);
}

// case 12345.6789 with trailing zero
void		test_double_write_fraction_part_case2(void)
{
	printf(KYEL "test_double_write_fraction_part_case2\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 13;
	mantissa = 0x181cd6e631f8a1;
	precision = 30;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 12345.6789);

	fxp_del(&fraction_part);
}

// case 123000.6789 with trailing zero
void		test_double_write_fraction_part_case3(void)
{
	printf(KYEL "test_double_write_fraction_part_case3\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	precision = 30;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 123000.6789);

	fxp_del(&fraction_part);
}

// case 12345.0 with trailing zero
void		test_double_write_fraction_part_case4(void)
{
	printf(KYEL "test_double_write_fraction_part_case4\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 13;
	mantissa = 0x181c8000000000;
	precision = 30;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 12345.0);

	fxp_del(&fraction_part);
}

// case 0.123451234512345123451234512345 with trailing zero
void		test_double_write_fraction_part_case5(void)
{
	printf(KYEL "test_double_write_fraction_part_case5\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = -4;
	mantissa = 0x1f9a8006e1a013;
	precision = 50;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", 0.123451234512345123451234512345);

	fxp_del(&fraction_part);
}

// case 0.00000000000000000000000000000012345
void		test_double_write_fraction_part_case6(void)
{
	printf(KYEL "test_double_write_fraction_part_case6\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = -103;
	mantissa = 0x1407e9919234d8;
	precision = 60;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.60f\n", 0.00000000000000000000000000000012345);

	fxp_del(&fraction_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case7(void)
{
	printf(KYEL "test_double_write_fraction_part_case7\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	precision = 1;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.1f\n", 123000.6789);

	fxp_del(&fraction_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case8(void)
{
	printf(KYEL "test_double_write_fraction_part_case8\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	precision = 2;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.2f\n", 123000.6789);

	fxp_del(&fraction_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case9(void)
{
	printf(KYEL "test_double_write_fraction_part_case9\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	precision = 3;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.3f\n", 123000.6789);

	fxp_del(&fraction_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case10(void)
{
	printf(KYEL "test_double_write_fraction_part_case10\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	precision = 4;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.4f\n", 123000.6789);

	fxp_del(&fraction_part);
}

// case 123000.6789 with rounding data
void		test_double_write_fraction_part_case11(void)
{
	printf(KYEL "test_double_write_fraction_part_case11\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	precision = 0;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", 123000.6789);

	fxp_del(&fraction_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case12(void)
{
	printf(KYEL "test_double_write_fraction_part_case12\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e07800036e341;
	precision = 1;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.1f\n", 123000.000052345);

	fxp_del(&fraction_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case13(void)
{
	printf(KYEL "test_double_write_fraction_part_case13\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e07800036e341;
	precision = 2;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.2f\n", 123000.000052345);

	fxp_del(&fraction_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case14(void)
{
	printf(KYEL "test_double_write_fraction_part_case14\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e07800036e341;
	precision = 3;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.3f\n", 123000.000052345);

	fxp_del(&fraction_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case15(void)
{
	printf(KYEL "test_double_write_fraction_part_case15\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e07800036e341;
	precision = 4;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.4f\n", 123000.000052345);

	fxp_del(&fraction_part);
}

// case 123000.000052345 with leading zero
void		test_double_write_fraction_part_case16(void)
{
	printf(KYEL "test_double_write_fraction_part_case16\n" KNRM);
	t_fixedpoint		fraction_part;
	t_fp_buffer			buf;
	short				exponent;
	size_t				precision;
	unsigned long long	mantissa;

	fxp_init(&fraction_part);
	fp_init_buffer(&buf);
	exponent = 16;
	mantissa = 0x1e07800036e341;
	precision = 5;
	fp_double_get_fraction_part(exponent, mantissa, &fraction_part);
	fp_round_fraction_part(&fraction_part, precision);

	fp_double_write_fraction_part(&fraction_part, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.5f\n", 123000.000052345);

	fxp_del(&fraction_part);
}
