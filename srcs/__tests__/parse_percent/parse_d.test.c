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
		"fp_parse_d (d) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_d_length,
		"fp_parse_d (d) : arg.length"
	);

	test(
		arg.sign == &fp_arg_d_sign,
		"fp_parse_d (d) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_d (d) : arg.prefix"
	);

	test(
		arg.write == &fp_arg_d_write,
		"fp_parse_d (d) : arg.write"
	);
}

// hd
void		test_parse_d_case2(void)
{
	printf(KYEL "test_parse_d_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_d (hd) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_hd_length,
		"fp_parse_d (hd) : arg.length"
	);

	test(
		arg.sign == &fp_arg_hd_sign,
		"fp_parse_d (hd) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_d (hd) : arg.prefix"
	);

	test(
		arg.write == &fp_arg_hd_write,
		"fp_parse_d (hd) : arg.write"
	);
}

// hhd
void		test_parse_d_case3(void)
{
	printf(KYEL "test_parse_d_case3\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_d (hhd) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_hhd_length,
		"fp_parse_d (hhd) : arg.length"
	);

	test(
		arg.sign == &fp_arg_hhd_sign,
		"fp_parse_d (hhd) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_d (hhd) : arg.prefix"
	);

	test(
		arg.write == &fp_arg_hhd_write,
		"fp_parse_d (hhd) : arg.write"
	);
}

// ld
void		test_parse_d_case4(void)
{
	printf(KYEL "test_parse_d_case4\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	tags.mask |= FP_MASK_LENGTH_L;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_d (ld) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_ld_length,
		"fp_parse_d (ld) : arg.length"
	);

	test(
		arg.sign == &fp_arg_ld_sign,
		"fp_parse_d (ld) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_d (ld) : arg.prefix"
	);

	test(
		arg.write == &fp_arg_ld_write,
		"fp_parse_d (ld) : arg.write"
	);
}

// lld
void		test_parse_d_case5(void)
{
	printf(KYEL "test_parse_d_case5\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	tags.mask |= FP_MASK_LENGTH_L;
	tags.mask |= FP_MASK_LENGTH_LL;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_d (lld) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_lld_length,
		"fp_parse_d (lld) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lld_sign,
		"fp_parse_d (lld) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_d (lld) : arg.prefix"
	);

	test(
		arg.write == &fp_arg_lld_write,
		"fp_parse_d (lld) : arg.write"
	);
}

// tags->mask & FP_MASK_PRECISION
void		test_parse_d_case6(void)
{
	printf(KYEL "test_parse_d_case6\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_d : arg.data.i"
	);

	test(
		arg.length == &fp_arg_d_length,
		"fp_parse_d : arg.length"
	);

	test(
		arg.sign == &fp_arg_d_sign,
		"fp_parse_d : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_d : arg.prefix"
	);

	test(
		arg.write == &fp_arg_d_write,
		"fp_parse_d : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_d : tags.mask & FP_MASK_FLAG_ZERO"
	);
}
