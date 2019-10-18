#include "ft_printf.test.h"

// 3.14
void		test_double_integer_part_case1(void)
{
	printf(KYEL "test_double_integer_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 1;
	mantissa = 0x191eb851eb851f;

	fp_double_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_double_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 1,
		"fp_double_integer_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x03,
		"fp_double_integer_part : int_part.num.data[0]"
	);

	fxp_del(&int_part);
}

// case 12345.6789
void		test_double_integer_part_case2(void)
{
	printf(KYEL "test_double_integer_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 13;
	mantissa = 0x181cd6e631f8a1;

	fp_double_integer_part(exponent, mantissa, &int_part);
	
	test(
		int_part.e == 0,
		"fp_double_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 2,
		"fp_double_integer_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x39,
		"fp_double_integer_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0x30,
		"fp_double_integer_part : int_part.num.data[1]"
	);

	fxp_del(&int_part);
}

// case compact 123000.6789
void		test_double_integer_part_case3(void)
{
	printf(KYEL "test_double_integer_part_case3\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;

	fp_double_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 3,
		"fp_double_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 1,
		"fp_double_integer_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x7b,
		"fp_double_integer_part : int_part.num.data[0]"
	);

	fxp_del(&int_part);
}

// case 0
void		test_double_integer_part_case4(void)
{
	printf(KYEL "test_double_integer_part_case4\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -4;
	mantissa = 0x1f9add37c1215e;

	fp_double_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_double_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fp_double_integer_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}

// case big 1234512345123451234512345.12345
void		test_double_integer_part_case5(void)
{
	printf(KYEL "test_double_integer_part_case5\n" KNRM);
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
	mantissa = 0x1056b0c5f2b0d3;

	fp_double_integer_part(exponent, mantissa, &int_part);

	test(
		int_part.e == 0,
		"fp_double_integer_part : int_part.e"
	);

	test(
		int_part.num.occupied == 11,
		"fp_double_integer_part : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == expected[i],
			"fp_double_integer_part : int_part.num.data[i]"
		);

	fxp_del(&int_part);
}

// case 3.14
void		test_double_fraction_part_case1(void)
{
	printf(KYEL "test_double_fraction_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 1;
	mantissa = 0x191eb851eb851f;
	precision = 60;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60f\n", 3.14);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 12345.6789
void		test_double_fraction_part_case2(void)
{
	printf(KYEL "test_double_fraction_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 13;
	mantissa = 0x181cd6e631f8a1;
	precision = 60;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60f\n", 12345.6789);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 123000.6789
void		test_double_fraction_part_case3(void)
{
	printf(KYEL "test_double_fraction_part_case3\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;
	precision = 60;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60f\n", 123000.6789);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 12345.0
void		test_double_fraction_part_case4(void)
{
	printf(KYEL "test_double_fraction_part_case4\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = 13;
	mantissa = 0x181c8000000000;
	precision = 60;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

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
	printf("expect : %.60f\n", 12345.0);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.123451234512345123451234512345
void		test_double_fraction_part_case5(void)
{
	printf(KYEL "test_double_fraction_part_case5\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -4;
	mantissa = 0x1f9a8006e1a013;
	precision = 60;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.60f\n", 0.123451234512345123451234512345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.00000000000000000000000000000012345
void		test_double_fraction_part_case6(void)
{
	printf(KYEL "test_double_fraction_part_case6\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -103;
	mantissa = 0x1407e9919234d8;
	precision = 160;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.160f\n", 0.00000000000000000000000000000012345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.123451234512345123451234512345, precision 4
void		test_double_fraction_part_case7(void)
{
	printf(KYEL "test_double_fraction_part_case7\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -4;
	mantissa = 0x1f9a8006e1a013;
	precision = 4;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.4f\n", 0.123451234512345123451234512345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// case 0.00000000000000000000000000000012345, precision 34
void		test_double_fraction_part_case8(void)
{
	printf(KYEL "test_double_fraction_part_case8\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	size_t				precision;
	t_fixedpoint		fraction_part;
	t_bigint			bcd;

	fxp_init(&fraction_part);
	bi_init(&bcd);
	exponent = -103;
	mantissa = 0x1407e9919234d8;
	precision = 34;

	fp_double_fraction_part(exponent, mantissa, precision, &fraction_part);

	printf("fraction_part.e : %lld\n", fraction_part.e);

	bi_double_dabble(&(fraction_part.num), &bcd);
	printf("result : ");
	for (size_t i=bcd.occupied; i > 0; i--)
	{
		printf("%c", (bcd.data[i - 1] >> 4) + '0');
		printf("%c", (bcd.data[i - 1] & 0x0f) + '0');
	}
	printf("\n");
	printf("expect : %.34f\n", 0.00000000000000000000000000000012345);

	fxp_del(&fraction_part);
	bi_del(&bcd);
}

// // case 3.14
// void		test_double_write_case1(void)
// {
// 	printf(KYEL "test_double_write_case1\n" KNRM);
// 	double			f;
// 	size_t			precision;
// 	t_fp_buffer		buf;

// 	f = 3.14;
// 	precision = 6;
// 	fp_init_buffer(&buf);

// 	fp_double_write(f, precision, &buf);
// 	printf("result : %s\n", buf.data);
// 	printf("expect : %f\n", f);
// }

// // case precision < 6
// void		test_double_write_case2(void)
// {
// 	printf(KYEL "test_double_write_case2\n" KNRM);
// 	double			f;
// 	size_t			precision;
// 	t_fp_buffer		buf;

// 	f = 3.14;
// 	precision = 2;
// 	fp_init_buffer(&buf);

// 	fp_double_write(f, precision, &buf);
// 	printf("result : %s\n", buf.data);
// 	printf("expect : %.2f\n", f);
// }

// // case precision > 6
// void		test_double_write_case3(void)
// {
// 	printf(KYEL "test_double_write_case3\n" KNRM);
// 	double			f;
// 	size_t			precision;
// 	t_fp_buffer		buf;

// 	f = 3.14;
// 	precision = 10;
// 	fp_init_buffer(&buf);

// 	fp_double_write(f, precision, &buf);
// 	printf("result : %s\n", buf.data);
// 	printf("expect : %.10f\n", f);
// }

// // case big integer part
// void		test_double_write_case4(void)
// {
// 	printf(KYEL "test_double_write_case4\n" KNRM);
// 	double			f;
// 	size_t			precision;
// 	t_fp_buffer		buf;

// 	f = 123451234512345123451234512345123451234512345.0;
// 	precision = 6;
// 	fp_init_buffer(&buf);

// 	fp_double_write(f, precision, &buf);
// 	printf("result : %s\n", buf.data);
// 	printf("expect : %f\n", f);
// }

// // case big integer part
// void		test_double_write_case5(void)
// {
// 	printf(KYEL "test_double_write_case5\n" KNRM);
// 	double			f;
// 	size_t			precision;
// 	t_fp_buffer		buf;

// 	f = 123451234512345123451234512345123451234512345.12345;
// 	precision = 6;
// 	fp_init_buffer(&buf);

// 	fp_double_write(f, precision, &buf);
// 	printf("result : %s\n", buf.data);
// 	printf("expect : %f\n", f);
// }

// // case big fraction part
// void		test_double_write_case6(void)
// {
// 	printf(KYEL "test_double_write_case6\n" KNRM);
// 	double			f;
// 	size_t			precision;
// 	t_fp_buffer		buf;

// 	f = 1.12345123451234512345123451234512345123451234512345;
// 	precision = 60;
// 	fp_init_buffer(&buf);

// 	fp_double_write(f, precision, &buf);
// 	printf("result : %s\n", buf.data);
// 	printf("expect : %.60f\n", f);
// }

// // case small fraction part
// void		test_double_write_case6(void)
// {
// 	printf(KYEL "test_double_write_case6\n" KNRM);
// 	double			f;
// 	size_t			precision;
// 	t_fp_buffer		buf;

// 	f = 1.00000000000000000000000000000000000000000000012345;
// 	precision = 60;
// 	fp_init_buffer(&buf);

// 	fp_double_write(f, precision, &buf);
// 	printf("result : %s\n", buf.data);
// 	printf("expect : %.60f\n", f);
// }

// // case 0
// // case inf

// case 3.14
void		test_double_write_integer_part_case1(void)
{
	printf(KYEL "test_double_write_integer_part_case1\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 1;
	df.mantissa = 0x191eb851eb851f;

	fp_double_write_integer_part(&df, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 3.14);

	bi_del(&bcd);
}

// case 12345.6789
void		test_double_write_integer_part_case2(void)
{
	printf(KYEL "test_double_write_integer_part_case2\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 13;
	df.mantissa = 0x181cd6e631f8a1;

	fp_double_write_integer_part(&df, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 12345.6789);

	bi_del(&bcd);
}

// case compact 123000.6789
void		test_double_write_integer_part_case3(void)
{
	printf(KYEL "test_double_write_integer_part_case3\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 16;
	df.mantissa = 0x1e078adcc63f14;

	fp_double_write_integer_part(&df, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 123000.6789);

	bi_del(&bcd);
}

// case 0
void		test_double_write_integer_part_case4(void)
{
	printf(KYEL "test_double_write_integer_part_case4\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = -4;
	df.mantissa = 0x1f972474538ef3;

	fp_double_write_integer_part(&df, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 0.1234);

	bi_del(&bcd);
}

// case big 1234512345123451234512345.12345
void		test_double_write_integer_part_case5(void)
{
	printf(KYEL "test_double_write_integer_part_case5\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 80;
	df.mantissa = 0x1056b0c5f2b0d3;

	fp_double_write_integer_part(&df, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 1234512345123451234512345.12345);

	bi_del(&bcd);
}

// case 12345000000.123
void		test_double_write_integer_part_case6(void)
{
	printf(KYEL "test_double_write_integer_part_case6\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 33;
	df.mantissa = 0x1056b0c5f2b0d3;
	df.mantissa = 0x16fe8e0200fbe7;

	fp_double_write_integer_part(&df, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", 12345000000.123);

	bi_del(&bcd);
}

/*
// case 3.14
void		test_double_write_fraction_part_case1(void)
{
	printf(KYEL "test_double_write_fraction_part_case1\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;
	size_t				precision;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 1;
	df.mantissa = 0x191eb851eb851f;
	precision = 30;

	fp_double_write_fraction_part(&df, precision, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 3.14);

	bi_del(&bcd);
}

// case 12345.6789
void		test_double_write_fraction_part_case2(void)
{
	printf(KYEL "test_double_write_fraction_part_case2\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;
	size_t				precision;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 13;
	df.mantissa = 0x181cd6e631f8a1;
	precision = 30;

	fp_double_write_fraction_part(&df, precision, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 12345.6789);

	bi_del(&bcd);
}

// case 123000.6789
void		test_double_write_fraction_part_case3(void)
{
	printf(KYEL "test_double_write_fraction_part_case3\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;
	size_t				precision;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 16;
	df.mantissa = 0x1e078adcc63f14;
	precision = 30;

	fp_double_write_fraction_part(&df, precision, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 123000.6789);

	bi_del(&bcd);
}

// case 12345.0
void		test_double_write_fraction_part_case4(void)
{
	printf(KYEL "test_double_write_fraction_part_case4\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;
	size_t				precision;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = 13;
	df.mantissa = 0x181c8000000000;
	precision = 30;

	fp_double_write_fraction_part(&df, precision, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 12345.0);

	bi_del(&bcd);
}

// case 0.123451234512345123451234512345
void		test_double_write_fraction_part_case5(void)
{
	printf(KYEL "test_double_write_fraction_part_case5\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;
	size_t				precision;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = -4;
	df.mantissa = 0x1f9a8006e1a013;
	precision = 30;

	fp_double_write_fraction_part(&df, precision, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.30f\n", 12345.0);

	bi_del(&bcd);
}

// case 0.00000000000000000000000000000012345
void		test_double_write_fraction_part_case6(void)
{
	printf(KYEL "test_double_write_fraction_part_case6\n" KNRM);
	t_fp_double_fields	df;
	t_bigint			bcd;
	t_fp_buffer			buf;
	size_t				precision;

	fp_init_buffer(&buf);
	bi_init(&bcd);
	df.exponent = -103;
	df.mantissa = 0x1407e9919234d8;
	precision = 60;

	fp_double_write_fraction_part(&df, precision, &bcd, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.60f\n", 12345.0);

	bi_del(&bcd);
}
*/
