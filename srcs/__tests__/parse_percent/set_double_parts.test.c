#include "ft_printf.test.h"

// case len(int part) - 1 > precision
void		test_set_scientific_double_parts_case1(void)
{
	printf(KYEL "test_set_scientific_double_parts_case1\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 12345.00678;
	size_t			precision = 2;
	int				res;
	unsigned char	int_expected[3] = {0x00, 0x23, 0x01};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		fraction_part.num.data == NULL,
		"fp_set_scientific_double_parts : fraction_part.num.data"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case len(int part) - 1 > precision, round need
void		test_set_scientific_double_parts_case2(void)
{
	printf(KYEL "test_set_scientific_double_parts_case2\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 12345.00678;
	size_t			precision = 3;
	int				res;
	unsigned char	int_expected[3] = {0x50, 0x23, 0x01};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		fraction_part.num.data == NULL,
		"fp_set_scientific_double_parts : fraction_part.num.data"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case len(int part) - 1 > precision, precision = 0
void		test_set_scientific_double_parts_case3(void)
{
	printf(KYEL "test_set_scientific_double_parts_case3\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 12345.00678;
	size_t			precision = 0;
	int				res;
	unsigned char	int_expected[3] = {0x00, 0x00, 0x01};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		fraction_part.num.data == NULL,
		"fp_set_scientific_double_parts : fraction_part.num.data"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case len(int part) - 1 = precision
void		test_set_scientific_double_parts_case4(void)
{
	printf(KYEL "test_set_scientific_double_parts_case4\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 12345.00678;
	size_t			precision = 4;
	int				res;
	unsigned char	int_expected[3] = {0x45, 0x23, 0x01};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	test(
		fraction_part.num.occupied == 0,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case len(int part) - 1 < precision, round needed
void		test_set_scientific_double_parts_case5(void)
{
	printf(KYEL "test_set_scientific_double_parts_case5\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 12345.00678;
	size_t			precision = 7;
	int				res;
	unsigned char	int_expected[3] = {0x45, 0x23, 0x01};
	unsigned char	fraction_expected[1] = {0x07};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	test(
		fraction_part.e == -3,
		"fp_set_scientific_double_parts : fraction_part.e"
	);

	test(
		fraction_part.num.occupied == 1,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case len(int part) - 1 < precision
void		test_set_scientific_double_parts_case6(void)
{
	printf(KYEL "test_set_scientific_double_parts_case6\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 12345.00678;
	size_t			precision = 9;
	int				res;
	unsigned char	int_expected[3] = {0x45, 0x23, 0x01};
	unsigned char	fraction_expected[2] = {0x78, 0x06};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	test(
		fraction_part.e == -5,
		"fp_set_scientific_double_parts : fraction_part.e"
	);

	test(
		fraction_part.num.occupied == 2,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case len(int part) - 1 < precision, precision bigger than fraction part len
void		test_set_scientific_double_parts_case7(void)
{
	printf(KYEL "test_set_scientific_double_parts_case7\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 12345.00678;
	size_t			precision = 12;
	int				res;
	unsigned char	int_expected[3] = {0x45, 0x23, 0x01};
	unsigned char	fraction_expected[2] = {0x78, 0x06};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	test(
		fraction_part.e == -5,
		"fp_set_scientific_double_parts : fraction_part.e"
	);

	test(
		fraction_part.num.occupied == 2,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case int part is 0
void		test_set_scientific_double_parts_case8(void)
{
	printf(KYEL "test_set_scientific_double_parts_case8\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 0.0000987654;
	size_t			precision = 4;
	int				res;
	unsigned char	fraction_expected[3] = {0x65, 0x87, 0x09};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 0,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	test(
		fraction_part.e == -9,
		"fp_set_scientific_double_parts : fraction_part.e"
	);

	test(
		fraction_part.num.occupied == 3,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case int part is 0, need round
void		test_set_scientific_double_parts_case9(void)
{
	printf(KYEL "test_set_scientific_double_parts_case9\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 0.0000987654;
	size_t			precision = 2;
	int				res;
	unsigned char	fraction_expected[2] = {0x88, 0x09};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 0,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	test(
		fraction_part.e == -7,
		"fp_set_scientific_double_parts : fraction_part.e"
	);

	test(
		fraction_part.num.occupied == 2,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case int part is 0, precision = fraction part num length - 1
void		test_set_scientific_double_parts_case10(void)
{
	printf(KYEL "test_set_scientific_double_parts_case10\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 0.0000987654;
	size_t			precision = 5;
	int				res;
	unsigned char	fraction_expected[3] = {0x54, 0x76, 0x98};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 0,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	test(
		fraction_part.e == -10,
		"fp_set_scientific_double_parts : fraction_part.e"
	);

	test(
		fraction_part.num.occupied == 3,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case int part is 0, precision > fraction part num length - 1
void		test_set_scientific_double_parts_case11(void)
{
	printf(KYEL "test_set_scientific_double_parts_case11\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 0.0000987654;
	size_t			precision = 6;
	int				res;
	unsigned char	fraction_expected[3] = {0x54, 0x76, 0x98};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 0,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	test(
		fraction_part.e == -10,
		"fp_set_scientific_double_parts : fraction_part.e"
	);

	test(
		fraction_part.num.occupied == 3,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case carry from fraction
void		test_set_scientific_double_parts_case12(void)
{
	printf(KYEL "test_set_scientific_double_parts_case12\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 99999.9999;
	size_t			precision = 4;
	int				res;
	unsigned char	int_expected[3] = {0x00, 0x00, 0x10};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		fraction_part.num.occupied == 0,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case round in int
void		test_set_scientific_double_parts_case13(void)
{
	printf(KYEL "test_set_scientific_double_parts_case13\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 99999.9999;
	size_t			precision = 3;
	int				res;
	unsigned char	int_expected[3] = {0x00, 0x00, 0x10};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		fraction_part.num.data == NULL,
		"fp_set_scientific_double_parts : fraction_part.num.data"
	);

	test(
		int_part.num.occupied == 3,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case carry from fraction
void		test_set_scientific_double_parts_case14(void)
{
	printf(KYEL "test_set_scientific_double_parts_case14\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 0.9999;
	size_t			precision = 2;
	int				res;
	unsigned char	int_expected[1] = {0x01};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		fraction_part.num.occupied == 0,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	test(
		int_part.num.occupied == 1,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	for (size_t i=0; i < int_part.num.occupied; i++)
		test(
			int_part.num.data[i] == int_expected[i],
			"fp_set_scientific_double_parts : int_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}

// case no carry from fraction
void		test_set_scientific_double_parts_case15(void)
{
	printf(KYEL "test_set_scientific_double_parts_case15\n" KNRM);
	t_fixedpoint	int_part;
	t_fixedpoint	fraction_part;
	double			num = 0.9999;
	size_t			precision = 3;
	int				res;
	unsigned char	fraction_expected[2] = {0x99, 0x99};

	fxp_init(&int_part);
	fxp_init(&fraction_part);

	res = fp_set_scientific_double_parts(num, precision, &int_part, &fraction_part);

	test(
		res == FP_SUCCESS,
		"fp_set_scientific_double_parts : return value"
	);

	test(
		int_part.num.occupied == 0,
		"fp_set_scientific_double_parts : int_part.num.occupied"
	);

	test(
		fraction_part.num.occupied == 2,
		"fp_set_scientific_double_parts : fraction_part.num.occupied"
	);

	for (size_t i=0; i < fraction_part.num.occupied; i++)
		test(
			fraction_part.num.data[i] == fraction_expected[i],
			"fp_set_scientific_double_parts : fraction_part.num.data[i]"
		);

	fxp_del(&int_part);
	fxp_del(&fraction_part);
}
