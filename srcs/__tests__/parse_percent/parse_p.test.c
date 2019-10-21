#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_p(ap, tags, arg);
	va_end(ap);
}

// p
void		test_parse_p_case1(void)
{
	printf(KYEL "test_parse_p_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, 0x12345);

	test(
		arg.data.i == 0x12345,
		"fp_parse_p : arg.data.i"
	);

	test(
		arg.length == &fp_arg_llx_length,
		"fp_parse_p : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_p : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_p_prefix,
		"fp_parse_p : arg.prefix"
	);

	test(
		arg.write == &fp_arg_llx_write,
		"fp_parse_p : arg.write"
	);
}

// tags->mask & FP_MASK_PRECISION
void		test_parse_p_case2(void)
{
	printf(KYEL "test_parse_p_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, 0x12345);

	test(
		arg.data.i == 0x12345,
		"fp_parse_p : arg.data.i"
	);

	test(
		arg.length == &fp_arg_llx_length,
		"fp_parse_p : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_p : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_p_prefix,
		"fp_parse_p : arg.prefix"
	);

	test(
		arg.write == &fp_arg_llx_write,
		"fp_parse_p : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_p : tags.mask & FP_MASK_FLAG_ZERO"
	);
}
