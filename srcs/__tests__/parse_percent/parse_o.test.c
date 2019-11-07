#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_o(ap, tags, arg);
	va_end(ap);
}

// o
void		test_parse_o_case1(void)
{
	printf(KYEL "test_parse_o_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, 0377);

	test(
		arg.data.i == 0377,
		"fp_parse_o : arg.data.i"
	);

	test(
		arg.length == &fp_arg_o_length,
		"fp_parse_o : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_o : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_o_prefix,
		"fp_parse_o : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_o : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_o_write,
		"fp_parse_o : arg.write"
	);
}

// ho
void		test_parse_o_case2(void)
{
	printf(KYEL "test_parse_o_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 0377);

	test(
		arg.data.i == 0377,
		"fp_parse_o : arg.data.i"
	);

	test(
		arg.length == &fp_arg_ho_length,
		"fp_parse_o : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_o : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_ho_prefix,
		"fp_parse_o : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_o : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_ho_write,
		"fp_parse_o : arg.write"
	);
}

// hho
void		test_parse_o_case3(void)
{
	printf(KYEL "test_parse_o_case3\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 0377);

	test(
		arg.data.i == 0377,
		"fp_parse_o : arg.data.i"
	);

	test(
		arg.length == &fp_arg_hho_length,
		"fp_parse_o : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_o : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_hho_prefix,
		"fp_parse_o : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_o : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_hho_write,
		"fp_parse_o : arg.write"
	);
}

// lo
void		test_parse_o_case4(void)
{
	printf(KYEL "test_parse_o_case4\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	tags.mask |= FP_MASK_LENGTH_L;
	parse(&tags, &arg, 0377);

	test(
		arg.data.i == 0377,
		"fp_parse_o : arg.data.i"
	);

	test(
		arg.length == &fp_arg_lo_length,
		"fp_parse_o : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_o : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_lo_prefix,
		"fp_parse_o : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_o : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_lo_write,
		"fp_parse_o : arg.write"
	);
}

// llo
void		test_parse_o_case5(void)
{
	printf(KYEL "test_parse_o_case5\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	tags.mask |= FP_MASK_LENGTH_L;
	tags.mask |= FP_MASK_LENGTH_LL;
	parse(&tags, &arg, 0377);

	test(
		arg.data.i == 0377,
		"fp_parse_o : arg.data.i"
	);

	test(
		arg.length == &fp_arg_llo_length,
		"fp_parse_o : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_o : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_llo_prefix,
		"fp_parse_o : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_o : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_llo_write,
		"fp_parse_o : arg.write"
	);
}

// tags->mask & FP_MASK_PRECISION
void		test_parse_o_case6(void)
{
	printf(KYEL "test_parse_o_case6\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, 0377);

	test(
		arg.data.i == 0377,
		"fp_parse_o : arg.data.i"
	);

	test(
		arg.length == &fp_arg_o_length,
		"fp_parse_o : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_o : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_o_prefix,
		"fp_parse_o : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_o : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_o_write,
		"fp_parse_o : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_o : tags.mask & FP_MASK_FLAG_ZERO"
	);
}
