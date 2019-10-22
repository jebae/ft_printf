#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_u(ap, tags, arg);
	va_end(ap);
}

// u
void		test_parse_u_case1(void)
{
	printf(KYEL "test_parse_u_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_u (u) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_u_length,
		"fp_parse_u (u) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_u (u) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_u (u) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_u (u) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_u_write,
		"fp_parse_u (u) : arg.write"
	);
}

// hu
void		test_parse_u_case2(void)
{
	printf(KYEL "test_parse_u_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_u (hu) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_hu_length,
		"fp_parse_u (hu) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_u (hu) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_u (hu) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_u (hu) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_hu_write,
		"fp_parse_u (hu) : arg.write"
	);
}

// hhu
void		test_parse_u_case3(void)
{
	printf(KYEL "test_parse_u_case3\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_HH;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_u (hhu) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_hhu_length,
		"fp_parse_u (hhu) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_u (hhu) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_u (hhu) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_u (hhu) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_hhu_write,
		"fp_parse_u (hhu) : arg.write"
	);
}

// lu
void		test_parse_u_case4(void)
{
	printf(KYEL "test_parse_u_case4\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_H;
	tags.mask |= FP_MASK_LENGTH_HH;
	tags.mask |= FP_MASK_LENGTH_L;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_u (lu) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_lu_length,
		"fp_parse_u (lu) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_u (lu) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_u (lu) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_u (lu) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_lu_write,
		"fp_parse_u (lu) : arg.write"
	);
}

// llu
void		test_parse_u_case5(void)
{
	printf(KYEL "test_parse_u_case5\n" KNRM);
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
		"fp_parse_u (llu) : arg.data.i"
	);

	test(
		arg.length == &fp_arg_llu_length,
		"fp_parse_u (llu) : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_u (llu) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_u (llu) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_u (llu) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_llu_write,
		"fp_parse_u (llu) : arg.write"
	);
}

// tags->mask & FP_MASK_PRECISION
void		test_parse_u_case6(void)
{
	printf(KYEL "test_parse_u_case6\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, 12345);

	test(
		arg.data.i == 12345,
		"fp_parse_u : arg.data.i"
	);

	test(
		arg.length == &fp_arg_u_length,
		"fp_parse_u : arg.length"
	);

	test(
		arg.sign == &fp_arg_no_sign,
		"fp_parse_u : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_u : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_leading_zero,
		"fp_parse_u : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_u_write,
		"fp_parse_u : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_u : tags.mask & FP_MASK_FLAG_ZERO"
	);
}
