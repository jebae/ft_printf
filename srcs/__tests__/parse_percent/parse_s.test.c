#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_s(ap, tags, arg);
	va_end(ap);
}

void		test_parse_s_case1(void)
{
	printf(KYEL "test_parse_s_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;
	char		*ptr = "hello world";

	fp_init_tags(&tags);
	parse(&tags, &arg, ptr);

	test(
		arg.data.ptr == (void *)ptr,
		"fp_parse_s : arg.data.ptr"
	);

	test(
		arg.length == &fp_arg_s_length,
		"fp_parse_s : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_s : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_s : arg.prefix"
	);

	test(
		arg.write == &fp_arg_s_write,
		"fp_parse_s : arg.write"
	);
}
