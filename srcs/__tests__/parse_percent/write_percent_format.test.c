#include "ft_printf.test.h"

// %d (positive)
void		test_write_percent_format_case1(void)
{
	printf(KYEL "test_write_percent_format_case1\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 4,
		"write_percent_format (%d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "12345") == 0,
		"write_percent_format (%d, 12345) : strcmp"
	);
}

// %d (negative)
void		test_write_percent_format_case2(void)
{
	printf(KYEL "test_write_percent_format_case2\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 5,
		"write_percent_format (%d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-12345") == 0,
		"write_percent_format (%d, -12345) : strcmp"
	);
}

// %+d (positive)
void		test_write_percent_format_case3(void)
{
	printf(KYEL "test_write_percent_format_case3\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_PLUS;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 5,
		"write_percent_format (%+d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "+12345") == 0,
		"write_percent_format (%+d, 12345) : strcmp"
	);
}

// %+d (negative)
void		test_write_percent_format_case4(void)
{
	printf(KYEL "test_write_percent_format_case4\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_PLUS;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 5,
		"write_percent_format (%+d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-12345") == 0,
		"write_percent_format (%+d, -12345) : strcmp"
	);
}

// % d (positive)
void		test_write_percent_format_case5(void)
{
	printf(KYEL "test_write_percent_format_case5\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_SPACE;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 5,
		"write_percent_format (% d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, " 12345") == 0,
		"write_percent_format (% d, 12345) : strcmp"
	);
}

// % d (negative)
void		test_write_percent_format_case6(void)
{
	printf(KYEL "test_write_percent_format_case6\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_SPACE;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 5,
		"write_percent_format (% d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-12345") == 0,
		"write_percent_format (% d, -12345) : strcmp"
	);
}

// %10d (positive)
void		test_write_percent_format_case7(void)
{
	printf(KYEL "test_write_percent_format_case7\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%10d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "     12345") == 0,
		"write_percent_format (%10d, 12345) : strcmp"
	);
}

// %10d (positive)
void		test_write_percent_format_case8(void)
{
	printf(KYEL "test_write_percent_format_case8\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%10d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "     12345") == 0,
		"write_percent_format (%10d, 12345) : strcmp"
	);
}

// %10d (negative)
void		test_write_percent_format_case9(void)
{
	printf(KYEL "test_write_percent_format_case9\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%10d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "    -12345") == 0,
		"write_percent_format (%10d, -12345) : strcmp"
	);
}

// %+10d (positive)
void		test_write_percent_format_case10(void)
{
	printf(KYEL "test_write_percent_format_case10\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%+10d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "    +12345") == 0,
		"write_percent_format (%+10d, 12345) : strcmp"
	);
}

// %+10d (negative)
void		test_write_percent_format_case11(void)
{
	printf(KYEL "test_write_percent_format_case11\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%+10d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "    -12345") == 0,
		"write_percent_format (%+10d, -12345) : strcmp"
	);
}

// % 10d (positive)
void		test_write_percent_format_case12(void)
{
	printf(KYEL "test_write_percent_format_case12\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (% 10d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "     12345") == 0,
		"write_percent_format (% 10d, 12345) : strcmp"
	);
}

// % 10d (negative)
void		test_write_percent_format_case13(void)
{
	printf(KYEL "test_write_percent_format_case13\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (% 10d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "    -12345") == 0,
		"write_percent_format (% 10d, -12345) : strcmp"
	);
}

// %010d (positive)
void		test_write_percent_format_case14(void)
{
	printf(KYEL "test_write_percent_format_case14\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_ZERO;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%010d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "0000012345") == 0,
		"write_percent_format (%010d, 12345) : strcmp"
	);
}

// %010d (negative)
void		test_write_percent_format_case15(void)
{
	printf(KYEL "test_write_percent_format_case15\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_ZERO;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%010d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-000012345") == 0,
		"write_percent_format (%010d, -12345) : strcmp"
	);
}

// %+010d (positive)
void		test_write_percent_format_case16(void)
{
	printf(KYEL "test_write_percent_format_case16\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_ZERO;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%+010d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "+000012345") == 0,
		"write_percent_format (%+010d, 12345) : strcmp"
	);
}

// %+010d (negative)
void		test_write_percent_format_case17(void)
{
	printf(KYEL "test_write_percent_format_case17\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_ZERO;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%+010d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-000012345") == 0,
		"write_percent_format (%+010d, -12345) : strcmp"
	);
}

// % 010d (positive)
void		test_write_percent_format_case18(void)
{
	printf(KYEL "test_write_percent_format_case18\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_ZERO;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (% 010d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, " 000012345") == 0,
		"write_percent_format (% 010d, 12345) : strcmp"
	);
}

// % 010d (negative)
void		test_write_percent_format_case19(void)
{
	printf(KYEL "test_write_percent_format_case19\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_ZERO;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (% 010d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-000012345") == 0,
		"write_percent_format (% 010d, -12345) : strcmp"
	);
}

// %-10d (positive)
void		test_write_percent_format_case20(void)
{
	printf(KYEL "test_write_percent_format_case20\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_MINUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%-10d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "12345     ") == 0,
		"write_percent_format (%-10d, 12345) : strcmp"
	);
}

// %-10d (negative)
void		test_write_percent_format_case21(void)
{
	printf(KYEL "test_write_percent_format_case21\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_MINUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%-10d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-12345    ") == 0,
		"write_percent_format (%-10d, -12345) : strcmp"
	);
}

// %- 10d (positive)
void		test_write_percent_format_case22(void)
{
	printf(KYEL "test_write_percent_format_case22\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_MINUS;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%- 10d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, " 12345    ") == 0,
		"write_percent_format (%- 10d, 12345) : strcmp"
	);
}

// %- 10d (negative)
void		test_write_percent_format_case23(void)
{
	printf(KYEL "test_write_percent_format_case23\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_MINUS;
	tags.mask |= FP_MASK_FLAG_SPACE;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%- 10d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-12345    ") == 0,
		"write_percent_format (%- 10d, -12345) : strcmp"
	);
}

// %-+10d (positive)
void		test_write_percent_format_case24(void)
{
	printf(KYEL "test_write_percent_format_case24\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = 12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_MINUS;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%-+10d, 12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "+12345    ") == 0,
		"write_percent_format (%-+10d, 12345) : strcmp"
	);
}

// %-+10d (negative)
void		test_write_percent_format_case25(void)
{
	printf(KYEL "test_write_percent_format_case25\n" KNRM);
	t_fp_tags		tags;
	t_fp_arg		arg;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	arg.data.i = -12345;
	arg.length = &fp_arg_d_length;
	arg.sign = &fp_arg_d_sign;
	arg.write = &fp_arg_d_write;
	tags.mask |= FP_MASK_FLAG_MINUS;
	tags.mask |= FP_MASK_FLAG_PLUS;
	tags.width = 10;
	fp_write_percent_format(&arg, &tags, &buf);

	test(
		buf.i == 9,
		"write_percent_format (%-+10d, -12345) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "-12345    ") == 0,
		"write_percent_format (%-+10d, -12345) : strcmp"
	);
}
