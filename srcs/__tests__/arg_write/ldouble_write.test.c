#include "ft_printf.test.h"

// case 3.14
void		test_ldouble_integer_part_case1(void)
{
	printf(KYEL "test_ldouble_integer_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 1;
	mantissa = 0xc8f5c28f5c28f800;

	fp_ldouble_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_ldouble_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 1,
		"fp_ldouble_integer_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x03,
		"fp_ldouble_integer_part : int_part.num.data[0]"
	);

	fxp_del(&int_part);
}

// case 12345.6789
void		test_ldouble_integer_part_case2(void)
{
	printf(KYEL "test_ldouble_integer_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 13;
	mantissa = 0xc0e6b7318fc50800;

	fp_ldouble_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_ldouble_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 2,
		"fp_ldouble_integer_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x39,
		"fp_ldouble_integer_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0x30,
		"fp_ldouble_integer_part : int_part.num.data[1]"
	);

	fxp_del(&int_part);
}

// case compact 123000.6789
void		test_ldouble_integer_part_case3(void)
{
	printf(KYEL "test_ldouble_integer_part_case3\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 16;
	mantissa = 0xf03c56e631f8a000;

	fp_ldouble_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 3,
		"fp_ldouble_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 1,
		"fp_ldouble_integer_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x7b,
		"fp_ldouble_integer_part : int_part.num.data[0]"
	);

	fxp_del(&int_part);
}

// case 0
void		test_ldouble_integer_part_case4(void)
{
	printf(KYEL "test_ldouble_integer_part_case4\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -4;
	mantissa = 0xfcd35a858793e000;

	fp_ldouble_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_ldouble_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fp_ldouble_integer_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}

// case big 1234512345123451234512345.12345
void		test_ldouble_integer_part_case5(void)
{
	printf(KYEL "test_ldouble_integer_part_case5\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;
	unsigned char		expected[11] = {
		0x00, 0x00, 0x00, 0x30,
		0x0d, 0x2b, 0x5f, 0x0c,
		0x6b, 0x05, 0x01
	};

	fxp_init(&int_part);
	exponent = 80;
	mantissa = 0x82b5862f95869800;

	fp_ldouble_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_ldouble_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 11,
		"fp_ldouble_integer_part : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == expected[i],
			"fp_ldouble_integer_part : int_part.num.data[i]"
		);

	fxp_del(&int_part);
}

// case small 0.00000000000000000000000000000000000000000000012345
void		test_ldouble_integer_part_case6(void)
{
	printf(KYEL "test_ldouble_integer_part_case6\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -153;
	mantissa = 0xb46c20e8517c5800;

	fp_ldouble_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_ldouble_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fp_ldouble_integer_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}

// case 3.14
void		test_ldouble_fraction_part_case1(void)
{
	printf(KYEL "test_ldouble_fraction_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 1;
	mantissa = 0xc8f5c28f5c28f800;
	precision = 60;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60Lf\n", 3.14L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 12345.6789
void		test_ldouble_fraction_part_case2(void)
{
	printf(KYEL "test_ldouble_fraction_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 13;
	mantissa = 0xc0e6b7318fc50800;
	precision = 60;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60Lf\n", 12345.6789L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 123000.6789
void		test_ldouble_fraction_part_case3(void)
{
	printf(KYEL "test_ldouble_fraction_part_case3\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 16;
	mantissa = 0xf03c56e631f8a000;
	precision = 60;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60Lf\n", 123000.6789L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 12345.0
void		test_ldouble_fraction_part_case4(void)
{
	printf(KYEL "test_ldouble_fraction_part_case4\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 13;
	mantissa = 0xc0e4000000000000;
	precision = 60;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.num.occupied : %zu\n", fraction_part.num.occupied);
	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60Lf\n", 12345.0L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.123451234512345123451234512345
void		test_ldouble_fraction_part_case5(void)
{
	printf(KYEL "test_ldouble_fraction_part_case5\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -4;
	mantissa = 0xfcd400370d009800;
	precision = 60;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60Lf\n", 0.123451234512345123451234512345L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.00000000000000000000000000000012345
void		test_ldouble_fraction_part_case6(void)
{
	printf(KYEL "test_ldouble_fraction_part_case6\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -103;
	mantissa = 0xa03f4c8c91a6c000;
	precision = 160;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.160Lf\n", 0.00000000000000000000000000000012345L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.123451234512345123451234512345, precision 4
void		test_ldouble_fraction_part_case7(void)
{
	printf(KYEL "test_ldouble_fraction_part_case7\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -4;
	mantissa = 0xfcd400370d009800;
	precision = 4;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.4Lf\n", 0.123451234512345123451234512345L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.00000000000000000000000000000012345, precision 34
void		test_ldouble_fraction_part_case8(void)
{
	printf(KYEL "test_ldouble_fraction_part_case8\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -103;
	mantissa = 0xa03f4c8c91a6c000;
	precision = 34;

	fp_ldouble_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.34Lf\n", 0.00000000000000000000000000000012345L);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 3.14
void		test_ldouble_write_case1(void)
{
	printf(KYEL "test_ldouble_write_case1\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 3.14L;
	precision = 6;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %Lf\n", f);
}

// case precision < 6
void		test_ldouble_write_case2(void)
{
	printf(KYEL "test_ldouble_write_case2\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 3.14L;
	precision = 2;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.2Lf\n", f);
}

// case precision > 6
void		test_ldouble_write_case3(void)
{
	printf(KYEL "test_ldouble_write_case3\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 3.14L;
	precision = 10;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.10Lf\n", f);
}

// case big integer part
void		test_ldouble_write_case4(void)
{
	printf(KYEL "test_ldouble_write_case4\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 987654321987654321987654321987654321987654321.0L;
	precision = 6;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %Lf\n", f);
}

// case big integer part, precision 0
void		test_ldouble_write_case5(void)
{
	printf(KYEL "test_ldouble_write_case5\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 987654321987654321987654321987654321987654321.98765L;
	precision = 0;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0Lf\n", f);
}

// case big fraction part
void		test_ldouble_write_case6(void)
{
	printf(KYEL "test_ldouble_write_case6\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 1.12345123451234512345123451234512345123451234512345L;
	precision = 60;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.60Lf\n", f);
}

// case small fraction part
void		test_ldouble_write_case7(void)
{
	printf(KYEL "test_ldouble_write_case7\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 91.00000000000000000000000000000000000000000000012345L;
	precision = 60;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.60Lf\n", f);
}

// case small fraction part
void		test_ldouble_write_case8(void)
{
	printf(KYEL "test_ldouble_write_case8\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 0.00000000000000000000000000000000000000000000012345L;
	precision = 60;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.60Lf\n", f);
}

// case rounding
void		test_ldouble_write_case9(void)
{
	printf(KYEL "test_ldouble_write_case9\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 99.9999999999999999999999999999999999999999999999999999999999L;
	precision = 50;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", f);
}

// case rounding
void		test_ldouble_write_case10(void)
{
	printf(KYEL "test_ldouble_write_case10\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 9.87654321L;
	precision = 0;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0Lf\n", f);
}

// case 0
void		test_ldouble_write_case11(void)
{
	printf(KYEL "test_ldouble_write_case11\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = 0.0L;
	precision = 50;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", f);
}

// case inf
void		test_ldouble_write_case12(void)
{
	printf(KYEL "test_ldouble_write_case12\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = HUGE_VALL;
	precision = 50;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", f);
}

// case NaN
void		test_ldouble_write_case13(void)
{
	printf(KYEL "test_ldouble_write_case13\n" KNRM);
	long double		f;
	size_t			precision;
	t_fp_buffer		buf;

	f = (long double)NAN;
	precision = 50;
	fp_init_buffer(&buf);

	fp_ldouble_write(f, precision, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50Lf\n", f);
}
