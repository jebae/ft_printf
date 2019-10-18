#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_f(ap, tags, arg);
	va_end(ap);
}

// f
void		test_parse_f_case1(void)
{
	printf(KYEL "test_parse_f_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, 3.14);

	test(
		arg.data.f == 3.14,
		"fp_parse_f (f) : arg.data.f"
	);

	test(
		arg.length == &fp_arg_f_length,
		"fp_parse_f (f) : arg.length"
	);

	test(
		arg.sign == &fp_arg_f_sign,
		"fp_parse_f (f) : arg.sign"
	);

	test(
		arg.write == &fp_arg_f_write,
		"fp_parse_f (f) : arg.write"
	);
}
