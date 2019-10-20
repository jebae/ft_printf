#include "ft_printf.test.h"

static void	parse(
	const char *format,
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_specifier(format, ap, tags, arg);
	va_end(ap);
}

// d
void		test_parse_specifier_case1(void)
{
	printf(KYEL "test_parse_specifier_case1\n" KNRM);
	const char	*format = "d";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 12345);

	test(
		arg.data.i== 12345,
		"fp_parse_specifier (d) : arg.data.i"
	);

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

// u
void		test_parse_specifier_case2(void)
{
	printf(KYEL "test_parse_specifier_case2\n" KNRM);
	const char	*format = "u";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 12345);

	test(
		arg.data.i== 12345,
		"fp_parse_specifier (u) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_u_length,
		"fp_parse_specifier (u) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_specifier (u) : arg.sign"
	);

	test(
		arg.write == &fp_arg_u_write,
		"fp_parse_specifier (u) : arg.write"
	);
}

// i
void		test_parse_specifier_case3(void)
{
	printf(KYEL "test_parse_specifier_case3\n" KNRM);
	const char	*format = "i";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 12345);

	test(
		arg.data.i== 12345,
		"fp_parse_specifier (i) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_d_length,
		"fp_parse_specifier (i) : arg.length"
	);

	test(
		arg.sign == &fp_arg_d_sign,
		"fp_parse_specifier (i) : arg.sign"
	);

	test(
		arg.write == &fp_arg_d_write,
		"fp_parse_specifier (i) : arg.write"
	);
}

// f
void		test_parse_specifier_case4(void)
{
	printf(KYEL "test_parse_specifier_case4\n" KNRM);
	const char	*format = "f";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 3.14);

	test(
		arg.data.f== 3.14,
		"fp_parse_specifier (f) : arg.data.f"
	);

	test(
		arg.length == &fp_arg_f_length,
		"fp_parse_specifier (f) : arg.length"
	);

	test(
		arg.sign == &fp_arg_f_sign,
		"fp_parse_specifier (f) : arg.sign"
	);

	test(
		arg.write == &fp_arg_f_write,
		"fp_parse_specifier (f) : arg.write"
	);
}

// x
void		test_parse_specifier_case5(void)
{
	printf(KYEL "test_parse_specifier_case5\n" KNRM);
	const char	*format = "x";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 0x1234);

	test(
		arg.data.i == 0x1234,
		"fp_parse_specifier (x) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_x_length,
		"fp_parse_specifier (x) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_specifier (x) : arg.sign"
	);

	test(
		arg.write == &fp_arg_x_write,
		"fp_parse_specifier (x) : arg.write"
	);
}

// o
void		test_parse_specifier_case6(void)
{
	printf(KYEL "test_parse_specifier_case6\n" KNRM);
	const char	*format = "o";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 037723);

	test(
		arg.data.i == 037723,
		"fp_parse_specifier (o) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_o_length,
		"fp_parse_specifier (o) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_specifier (o) : arg.sign"
	);

	test(
		arg.write == &fp_arg_o_write,
		"fp_parse_specifier (o) : arg.write"
	);
}

// s
void		test_parse_specifier_case7(void)
{
	printf(KYEL "test_parse_specifier_case7\n" KNRM);
	const char	*format = "s";
	t_fp_arg	arg;
	t_fp_tags	tags;
	char		*ptr = "hello world";

	fp_init_tags(&tags);
	parse(format, &tags, &arg, ptr);

	test(
		arg.data.ptr == (void *)ptr,
		"fp_parse_specifier (s) : arg.data.ptr"
	);

	test(
		arg.length == &fp_arg_s_length,
		"fp_parse_specifier (s) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_specifier (s) : arg.sign"
	);

	test(
		arg.write == &fp_arg_s_write,
		"fp_parse_specifier (s) : arg.write"
	);
}

// c
void		test_parse_specifier_case8(void)
{
	printf(KYEL "test_parse_specifier_case8\n" KNRM);
	const char	*format = "c";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 'h');

	test(
		arg.data.i == 'h',
		"fp_parse_specifier (c) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_c_length,
		"fp_parse_specifier (c) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_specifier (c) : arg.sign"
	);

	test(
		arg.write == &fp_arg_c_write,
		"fp_parse_specifier (c) : arg.write"
	);
}

// X
void		test_parse_specifier_case9(void)
{
	printf(KYEL "test_parse_specifier_case9\n" KNRM);
	const char	*format = "X";
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(format, &tags, &arg, 0x1234);

	test(
		arg.data.i == 0x1234,
		"fp_parse_specifier (X) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_x_length,
		"fp_parse_specifier (X) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_specifier (X) : arg.sign"
	);

	test(
		arg.write == &fp_arg_upper_x_write,
		"fp_parse_specifier (X) : arg.write"
	);
}
