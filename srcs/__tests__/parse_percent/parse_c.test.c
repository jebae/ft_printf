#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_c(ap, tags, arg);
	va_end(ap);
}

void		test_parse_c_case1(void)
{
	printf(KYEL "test_parse_c_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, 'h');

	test(
		arg.data.i == 'h',
		"fp_parse_c : arg.data.i"
	);

	test(
		arg.length == &fp_arg_c_length,
		"fp_parse_c : arg.length"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_c : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_c : arg.leading_zero"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_c : arg.sign"
	);

	test(
		arg.write == &fp_arg_c_write,
		"fp_parse_c : arg.write"
	);
}
