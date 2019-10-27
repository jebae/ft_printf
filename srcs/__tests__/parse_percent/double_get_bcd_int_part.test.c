#include "ft_printf.test.h"

// case 3.14
void		test_double_get_bcd_int_part_case1(void)
{
	printf(KYEL "test_double_get_bcd_int_part_case1\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 1;
	mantissa = 0x191eb851eb851f;

	fp_double_get_bcd_int_part(exponent, mantissa, &fxp_double_get_int_part, &int_part);

	test(
		int_part.e == 0,
		"fp_double_get_bcd_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 1,
		"fp_double_get_bcd_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x03,
		"fp_double_get_bcd_int_part : int_part.num.data[0]"
	);

	fxp_del(&int_part);
}

// case 12345.6789
void		test_double_get_bcd_int_part_case2(void)
{
	printf(KYEL "test_double_get_bcd_int_part_case2\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 13;
	mantissa = 0x181cd6e631f8a1;

	fp_double_get_bcd_int_part(exponent, mantissa, &fxp_double_get_int_part, &int_part);
	
	test(
		int_part.e == 0,
		"fp_double_get_bcd_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 3,
		"fp_double_get_bcd_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x45,
		"fp_double_get_bcd_int_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0x23,
		"fp_double_get_bcd_int_part : int_part.num.data[1]"
	);

	test(
		int_part.num.data[2] == 0x01,
		"fp_double_get_bcd_int_part : int_part.num.data[2]"
	);

	fxp_del(&int_part);
}

// case 123000.6789
void		test_double_get_bcd_int_part_case3(void)
{
	printf(KYEL "test_double_get_bcd_int_part_case3\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = 16;
	mantissa = 0x1e078adcc63f14;

	fp_double_get_bcd_int_part(exponent, mantissa, &fxp_double_get_int_part, &int_part);

	test(
		int_part.e == 0,
		"fp_double_get_bcd_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 3,
		"fp_double_get_bcd_int_part : int_part.num.occupied"
	);

	test(
		int_part.num.data[0] == 0x00,
		"fp_double_get_bcd_int_part : int_part.num.data[0]"
	);

	test(
		int_part.num.data[1] == 0x30,
		"fp_double_get_bcd_int_part : int_part.num.data[1]"
	);
	test(
		int_part.num.data[2] == 0x12,
		"fp_double_get_bcd_int_part : int_part.num.data[2]"
	);

	fxp_del(&int_part);
}

// case 0
void		test_double_get_bcd_int_part_case4(void)
{
	printf(KYEL "test_double_get_bcd_int_part_case4\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -4;
	mantissa = 0x1f9add37c1215e;

	fp_double_get_bcd_int_part(exponent, mantissa, &fxp_double_get_int_part, &int_part);

	test(
		int_part.e == 0,
		"fp_double_get_bcd_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fp_double_get_bcd_int_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}

// case big 1234512345123451234512345.12345
void		test_double_get_bcd_int_part_case5(void)
{
	printf(KYEL "test_double_get_bcd_int_part_case5\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;
	unsigned char		expected[13] = {
		0x04, 0x07, 0x32, 0x05,
		0x12, 0x45, 0x23, 0x51,
		0x34, 0x12, 0x45, 0x23,
		0x01
	};

	fxp_init(&int_part);
	exponent = 80;
	mantissa = 0x1056b0c5f2b0d3;

	fp_double_get_bcd_int_part(exponent, mantissa, &fxp_double_get_int_part, &int_part);

	test(
		int_part.e == 0,
		"fp_double_get_bcd_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 13,
		"fp_double_get_bcd_int_part : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == expected[i],
			"fp_double_get_bcd_int_part : int_part.num.data[i]"
		);

	fxp_del(&int_part);
}

// case small 0.00000000000000000000000000000000000000000000012345
void		test_double_get_bcd_int_part_case6(void)
{
	printf(KYEL "test_double_get_bcd_int_part_case6\n" KNRM);
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;

	fxp_init(&int_part);
	exponent = -153;
	mantissa = 0x168d841d0a2f8B;

	fp_double_get_bcd_int_part(exponent, mantissa, &fxp_double_get_int_part, &int_part);

	test(
		int_part.e == 0,
		"fp_double_get_bcd_int_part : int_part.e"
	);

	test(
		int_part.num.occupied == 0,
		"fp_double_get_bcd_int_part : int_part.num.occupied"
	);

	fxp_del(&int_part);
}

