#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_d(ap, tags, arg);
	va_end(ap);
}

// d
void		test_parse_d_case1(void)
{
	printf(KYEL "test_parse_d_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_d (12345) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_d_length,
		"fp_parse_d (12345) : arg.length"
	);

	test(
		arg.sign == &fp_arg_d_sign,
		"fp_parse_d (12345) : arg.sign"
	);

	test(
		arg.write == &fp_arg_d_write,
		"fp_parse_d (12345) : arg.write"
	);
}

// parse hd
// parse hhd
// parse ld
// parse lld
