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

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) == 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
	);
}

// case nan
void		test_parse_f_case2(void)
{
	printf(KYEL "test_parse_f_case2\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, NAN);

	test(
		ft_is_nan(arg.data.f),
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

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) != 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
	);
}

// case inf
void		test_parse_f_case3(void)
{
	printf(KYEL "test_parse_f_case3\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, INFINITY);

	test(
		arg.data.f == INFINITY,
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

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) != 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
	);
}

// case -inf
void		test_parse_f_case4(void)
{
	printf(KYEL "test_parse_f_case4\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	parse(&tags, &arg, -INFINITY);

	test(
		arg.data.f == -INFINITY,
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

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) != 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
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
		arg.data.lf == 3.14L,
		"fp_parse_f (lf) : arg.data.lf"
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
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) == 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
	);
}

// lf case nan
void		test_parse_f_case6(void)
{
	printf(KYEL "test_parse_f_case6\n" KNRM);
	t_fp_arg	arg;
	t_fp_tags	tags;

	fp_init_tags(&tags);
	tags.mask |= FP_MASK_LENGTH_FL;
	parse(&tags, &arg, (long double)NAN);

	test(
		ft_is_nan_l(arg.data.lf),
		"fp_parse_f (lf) : arg.data.lf"
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
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) != 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
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
	parse(&tags, &arg, HUGE_VALL);

	test(
		arg.data.lf == HUGE_VALL,
		"fp_parse_f (lf) : arg.data.lf"
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
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) != 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
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
	parse(&tags, &arg, -HUGE_VALL);

	test(
		arg.data.lf == -HUGE_VALL,
		"fp_parse_f (lf) : arg.data.lf"
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
		arg.write == &fp_arg_lf_write,
		"fp_parse_f (lf) : arg.write"
	);

	test(
		(tags.mask & FP_MASK_IGNORE_ZERO_PAD) != 0,
		"fp_parse_f : tags.mask & FP_MASK_IGNORE_ZERO_PAD"
	);
}
