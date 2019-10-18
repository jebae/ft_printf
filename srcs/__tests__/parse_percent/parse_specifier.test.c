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
