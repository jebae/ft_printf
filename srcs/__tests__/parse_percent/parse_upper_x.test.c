#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_upper_x(ap, tags, arg);
	va_end(ap);
}

// x
void		test_parse_upper_x_case1(void)
{
	printf(KYEL "test_parse_upper_x_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, 0x12345);

	test(
		arg.data.i == 0x12345,
		"fp_parse_upper_x : arg.data.i"
	);

	test(
		arg.length == &fp_arg_x_length,
		"fp_parse_upper_x : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_upper_x : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_upper_x_prefix,
		"fp_parse_x : arg.prefix"
	);

	test(
		arg.write == &fp_arg_upper_x_write,
		"fp_parse_upper_x : arg.write"
	);
}

// hx
void		test_parse_upper_x_case2(void)
{
	printf(KYEL "test_parse_upper_x_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 0x1234);

	test(
		arg.data.i == 0x1234,
		"fp_parse_upper_x : arg.data.i"
	);

	test(
		arg.length == &fp_arg_hx_length,
		"fp_parse_upper_x : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_upper_x : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_upper_x_prefix,
		"fp_parse_x : arg.prefix"
	);

	test(
		arg.write == &fp_arg_h_upper_x_write,
		"fp_parse_upper_x : arg.write"
	);
}

// hhx
void		test_parse_upper_x_case3(void)
{
	printf(KYEL "test_parse_upper_x_case3\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 0x12);

	test(
		arg.data.i == 0x12,
		"fp_parse_upper_x : arg.data.i"
	);

	test(
		arg.length == &fp_arg_hhx_length,
		"fp_parse_upper_x : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_upper_x : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_upper_x_prefix,
		"fp_parse_x : arg.prefix"
	);

	test(
		arg.write == &fp_arg_hh_upper_x_write,
		"fp_parse_upper_x : arg.write"
	);
}

// lx
void		test_parse_upper_x_case4(void)
{
	printf(KYEL "test_parse_upper_x_case4\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	tags.mask |= FP_MASK_LENGTH_L;
	parse(&tags, &arg, 0x123456789abcdef0);

	test(
		arg.data.i == 0x123456789abcdef0,
		"fp_parse_upper_x : arg.data.i"
	);

	test(
		arg.length == &fp_arg_lx_length,
		"fp_parse_upper_x : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_upper_x : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_upper_x_prefix,
		"fp_parse_x : arg.prefix"
	);

	test(
		arg.write == &fp_arg_l_upper_x_write,
		"fp_parse_upper_x : arg.write"
	);
}

// llx
void		test_parse_upper_x_case5(void)
{
	printf(KYEL "test_parse_upper_x_case5\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	tags.mask |= FP_MASK_LENGTH_L;
	tags.mask |= FP_MASK_LENGTH_LL;
	parse(&tags, &arg, 0x123456789abcdef0);

	test(
		arg.data.i == 0x123456789abcdef0,
		"fp_parse_upper_x : arg.data.i"
	);

	test(
		arg.length == &fp_arg_llx_length,
		"fp_parse_upper_x : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_upper_x : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_upper_x_prefix,
		"fp_parse_x : arg.prefix"
	);

	test(
		arg.write == &fp_arg_ll_upper_x_write,
		"fp_parse_upper_x : arg.write"
	);
}

// tags->mask & FP_MASK_PRECISION
void		test_parse_upper_x_case6(void)
{
	printf(KYEL "test_parse_upper_x_case6\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, 0x1234);

	test(
		arg.data.i == 0x1234,
		"fp_parse_upper_x : arg.data.i"
	);

	test(
		arg.length == &fp_arg_x_length,
		"fp_parse_upper_x : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_upper_x : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_upper_x_prefix,
		"fp_parse_x : arg.prefix"
	);

	test(
		arg.write == &fp_arg_upper_x_write,
		"fp_parse_upper_x : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_upper_x : tags.mask & FP_MASK_FLAG_ZERO"
	);
}
