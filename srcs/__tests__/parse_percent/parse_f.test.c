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
	fxp_init(&arg.data.f.int_part);
	fxp_init(&arg.data.f.fraction_part);
	parse(&tags, &arg, 3.14);

	test(
		arg.data.f.float64 == 3.14,
		"fp_parse_f (f) : arg.data.f.float64"
	);

	test(
		arg.data.f.int_part.e == 0,
		"fp_parse_f (f) : arg.data.f.int_part.e"
	);

	test(
		arg.data.f.int_part.num.data[0] == 0x03,
		"fp_parse_f (f) : arg.data.f.int_part.num.data"
	);

	test(
		arg.data.f.fraction_part.e == -2,
		"fp_parse_f (f) : arg.data.f.fraction_part.e"
	);

	test(
		arg.data.f.fraction_part.num.data[0] == 0x14,
		"fp_parse_f (f) : arg.data.f.fraction_part.num.data[0]"
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
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (f) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (f) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_f_write,
		"fp_parse_f (f) : arg.write"
	);

	fxp_del(&arg.data.f.int_part);
	fxp_del(&arg.data.f.fraction_part);
}

// case nan
void		test_parse_f_case2(void)
{
	printf(KYEL "test_parse_f_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, NAN);

	test(
		ft_is_nan(arg.data.f.float64),
		"fp_parse_f (f) : arg.data.f.float64"
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
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (f) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (f) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_f_write,
		"fp_parse_f (f) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_f : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// case inf
void		test_parse_f_case3(void)
{
	printf(KYEL "test_parse_f_case3\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, INFINITY);

	test(
		arg.data.f.float64 == INFINITY,
		"fp_parse_f (f) : arg.data.f.float64"
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
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (f) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (f) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_f_write,
		"fp_parse_f (f) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_f : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// case -inf
void		test_parse_f_case4(void)
{
	printf(KYEL "test_parse_f_case4\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, -INFINITY);

	test(
		arg.data.f.float64 == -INFINITY,
		"fp_parse_f (f) : arg.data.f.float64"
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
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (f) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (f) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_f_write,
		"fp_parse_f (f) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_f : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// lf
void		test_parse_f_case5(void)
{
	printf(KYEL "test_parse_f_case5\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	parse(&tags, &arg, 3.14L);

	test(
		arg.data.f.float128 == 3.14L,
		"fp_parse_f (lf) : arg.data.f.float128"
	);

	test(
		arg.data.f.int_part.e == 0,
		"fp_parse_f (lf) : arg.data.f.int_part.e"
	);

	test(
		arg.data.f.int_part.num.data[0] == 0x03,
		"fp_parse_f (lf) : arg.data.f.int_part.num.data"
	);

	test(
		arg.data.f.fraction_part.e == -2,
		"fp_parse_f (lf) : arg.data.f.fraction_part.e"
	);

	test(
		arg.data.f.fraction_part.num.data[0] == 0x14,
		"fp_parse_f (lf) : arg.data.f.fraction_part.num.data[0]"
	);

	test(
		arg.length == &fp_arg_lf_length,
		"fp_parse_f (lf) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_f (lf) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (lf) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (lf) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	fxp_del(&arg.data.f.int_part);
	fxp_del(&arg.data.f.fraction_part);
}

// lf case nan
void		test_parse_f_case6(void)
{
	printf(KYEL "test_parse_f_case6\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, (long double)NAN);

	test(
		ft_is_nan_l(arg.data.f.float128),
		"fp_parse_f (lf) : arg.data.f.float128"
	);

	test(
		arg.length == &fp_arg_lf_length,
		"fp_parse_f (lf) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_f (lf) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (lf) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (lf) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_f (lf) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// lf case inf
void		test_parse_f_case7(void)
{
	printf(KYEL "test_parse_f_case7\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, HUGE_VALL);

	test(
		arg.data.f.float128 == HUGE_VALL,
		"fp_parse_f (lf) : arg.data.f.float128"
	);

	test(
		arg.length == &fp_arg_lf_length,
		"fp_parse_f (lf) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_f (lf) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (lf) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (lf) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_f (lf) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// lf case inf
void		test_parse_f_case8(void)
{
	printf(KYEL "test_parse_f_case8\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, -HUGE_VALL);

	test(
		arg.data.f.float128 == -HUGE_VALL,
		"fp_parse_f (lf) : arg.data.f.float128"
	);

	test(
		arg.length == &fp_arg_lf_length,
		"fp_parse_f (lf) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_f (lf) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_f (lf) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_f (lf) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_f (lf) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}
