#include "ft_printf.test.h"

// d
void		test_parse_specifier_case1(void)
{
	printf(KYEL "test_parse_specifier_case1\n" KNRM);
	const char	*str = "d";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_parse_specifier(str, &tags, &arg);

	test(
		arg.length == &fp_arg_d_length,
		"fp_parse_specifier (d) : arg.length"
	);

	test(
		arg.sign == &fp_arg_d_sign,
		"fp_parse_specifier (d) : arg.sign"
	);

	test(
		arg.write == &fp_arg_d_write,
		"fp_parse_specifier (d) : arg.write"
	);
}

/*
 *
 *
 *
 *  here you are
 *
 *
 *
// hd
void		test_parse_specifier_case2(void)
{
	printf(KYEL "test_parse_specifier_case2\n" KNRM);
	const char	*str = "hd";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_parse_specifier(str, &tags, &arg);

	test(
		arg.length == &fp_arg_d_length,
		"fp_parse_specifier (hd) : arg.length"
	);

	test(
		arg.sign == &fp_arg_d_sign,
		"fp_parse_specifier (hd) : arg.sign"
	);

	test(
		arg.write == &fp_arg_d_write,
		"fp_parse_specifier (hd) : arg.write"
	);
}
*/
