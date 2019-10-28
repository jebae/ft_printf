#include "ft_printf.test.h"

static void	parse(
	t_fp_tags *tags,
	t_fp_arg *arg,
	...
)
{
	va_list		ap;

	va_start(ap, arg);
	fp_parse_e(ap, tags, arg);
	va_end(ap);
}

// e
void		test_parse_e_case1(void)
{
	printf(KYEL "test_parse_e_case1\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	fxp_init(&arg.data.f.int_part);
	fxp_init(&arg.data.f.fraction_part);
	parse(&tags, &arg, 3.14e0);

	test(
		arg.data.f.float64 == 3.14e0,
		"fp_parse_e (e) : arg.data.f.float64"
	);

	test(
		arg.data.f.int_part.e == 0,
		"fp_parse_e (e) : arg.data.f.int_part.e"
	);

	test(
		arg.data.f.int_part.num.data[0] == 0x03,
		"fp_parse_e (e) : arg.data.f.int_part.num.data"
	);

	test(
		arg.data.f.fraction_part.e == -2,
		"fp_parse_e (e) : arg.data.f.fraction_part.e"
	);

	test(
		arg.data.f.fraction_part.num.data[0] == 0x14,
		"fp_parse_e (e) : arg.data.f.fraction_part.num.data[0]"
	);

	test(
		arg.length == &fp_arg_e_length,
		"fp_parse_e (e) : arg.length"
	);

	test(
		arg.sign == &fp_arg_f_sign,
		"fp_parse_e (e) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (e) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (e) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_e_write,
		"fp_parse_e (e) : arg.write"
	);

	fxp_del(&arg.data.f.int_part);
	fxp_del(&arg.data.f.fraction_part);
}

// case nan
void		test_parse_e_case2(void)
{
	printf(KYEL "test_parse_e_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, NAN);

	test(
		ft_is_nan(arg.data.f.float64),
		"fp_parse_e (e) : arg.data.f.float64"
	);

	test(
		arg.length == &fp_arg_e_length,
		"fp_parse_e (e) : arg.length"
	);

	test(
		arg.sign == &fp_arg_f_sign,
		"fp_parse_e (e) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (e) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (e) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_e_write,
		"fp_parse_e (e) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_e (e) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// case inf
void		test_parse_e_case3(void)
{
	printf(KYEL "test_parse_e_case3\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, INFINITY);

	test(
		arg.data.f.float64 == INFINITY,
		"fp_parse_e (e) : arg.data.f.float64"
	);

	test(
		arg.length == &fp_arg_e_length,
		"fp_parse_e (e) : arg.length"
	);

	test(
		arg.sign == &fp_arg_f_sign,
		"fp_parse_e (e) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (e) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (e) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_e_write,
		"fp_parse_e (e) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_e (e) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// case -inf
void		test_parse_e_case4(void)
{
	printf(KYEL "test_parse_e_case4\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, -INFINITY);

	test(
		arg.data.f.float64 == -INFINITY,
		"fp_parse_e (e) : arg.data.f.float64"
	);

	test(
		arg.length == &fp_arg_e_length,
		"fp_parse_e (e) : arg.length"
	);

	test(
		arg.sign == &fp_arg_f_sign,
		"fp_parse_e (e) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (e) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (e) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_e_write,
		"fp_parse_e (e) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_e (e) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// le
void		test_parse_e_case5(void)
{
	printf(KYEL "test_parse_e_case5\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	fxp_init(&arg.data.f.int_part);
	fxp_init(&arg.data.f.fraction_part);
	parse(&tags, &arg, 3.14e0L);

	test(
		arg.data.f.float128 == 3.14e0L,
		"fp_parse_e (le) : arg.data.f.float128"
	);

	test(
		arg.data.f.int_part.e == 0,
		"fp_parse_e (le) : arg.data.f.int_part.e"
	);

	test(
		arg.data.f.int_part.num.data[0] == 0x03,
		"fp_parse_e (le) : arg.data.f.int_part.num.data"
	);

	test(
		arg.data.f.fraction_part.e == -2,
		"fp_parse_e (le) : arg.data.f.fraction_part.e"
	);

	test(
		arg.data.f.fraction_part.num.data[0] == 0x14,
		"fp_parse_e (le) : arg.data.f.fraction_part.num.data[0]"
	);

	test(
		arg.length == &fp_arg_le_length,
		"fp_parse_e (le) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_e (le) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (le) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (le) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_le_write,
		"fp_parse_e (le) : arg.write"
	);

	fxp_del(&arg.data.f.int_part);
	fxp_del(&arg.data.f.fraction_part);
}

// case nan
void		test_parse_e_case6(void)
{
	printf(KYEL "test_parse_e_case6\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, (long double)NAN);

	test(
		ft_is_nan_l(arg.data.f.float128),
		"fp_parse_e (le) : arg.data.f.float128"
	);

	test(
		arg.length == &fp_arg_le_length,
		"fp_parse_e (le) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_e (le) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (le) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (le) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_le_write,
		"fp_parse_e (le) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_e (le) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// case inf
void		test_parse_e_case7(void)
{
	printf(KYEL "test_parse_e_case7\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, HUGE_VALL);

	test(
		arg.data.f.float128 == HUGE_VALL,
		"fp_parse_e (le) : arg.data.f.float128"
	);

	test(
		arg.length == &fp_arg_le_length,
		"fp_parse_e (le) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_e (le) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (le) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (le) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_le_write,
		"fp_parse_e (le) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_e (le) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}

// case -inf
void		test_parse_e_case8(void)
{
	printf(KYEL "test_parse_e_case8\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	tags.mask |= FP_MASK_FLAG_ZERO;
	parse(&tags, &arg, -HUGE_VALL);

	test(
		arg.data.f.float128 == -HUGE_VALL,
		"fp_parse_e (le) : arg.data.f.float128"
	);

	test(
		arg.length == &fp_arg_le_length,
		"fp_parse_e (le) : arg.length"
	);

	test(
		arg.sign == &fp_arg_lf_sign,
		"fp_parse_e (le) : arg.sign"
	);

	test(
		arg.prefix == &fp_arg_no_prefix,
		"fp_parse_e (le) : arg.prefix"
	);

	test(
		arg.leading_zero == &fp_arg_no_leading_zero,
		"fp_parse_e (le) : arg.leading_zero"
	);

	test(
		arg.write == &fp_arg_le_write,
		"fp_parse_e (le) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_FLAG_ZERO) == 0,
		"fp_parse_e (le) : tags.mask & FP_MASK_FLAG_ZERO"
	);
}
