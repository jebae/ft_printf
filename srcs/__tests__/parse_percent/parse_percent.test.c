#include "ft_printf.test.h"

static size_t	parse(
	const char *format,
	t_fp_buffer *buf,
	...
)
{
	va_list		ap;
	size_t		res;
	int			error;

	error = 0;
	va_start(ap, buf);
	res = fp_parse_percent(format, ap, buf, &error);
	va_end(ap);

	test(
		error == 0,
		"fp_parse_percent : error"
	);
	return (res);
}

// case %%
void		test_parse_percent_case1(void)
{
	printf(KYEL "test_parse_percent_case1\n" KNRM);
	const char	*format = "%%";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345) == 2,
		"fp_parse_percent (%%) : return value"
	);

	test(
		buf.i == 0,
		"fp_parse_percent (%%) : buf.i"
	);

	test(
		buf.data[0] == '%',
		"fp_parse_percent (%%) : buf.data[i]"
	);
}

// case %d
void		test_parse_percent_case2(void)
{
	printf(KYEL "test_parse_percent_case2\n" KNRM);
	const char	*format = "%d";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345) == 2,
		"fp_parse_percent (%d) : return value"
	);

	test(
		buf.i == 4,
		"fp_parse_percent (%d) : buf.i"
	);

	for (int i=0; i < buf.i; i++)
		test(
			buf.data[i] == '1' + i,
			"fp_parse_percent (%d) : buf.data[i]"
		);
}

// case %+010lld
void		test_parse_percent_case3(void)
{
	printf(KYEL "test_parse_percent_case3\n" KNRM);
	const char	*format = "%+010lld";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345) == ft_strlen(format),
		"fp_parse_percent (%+010lld) : return value"
	);

	test(
		buf.i == 9,
		"fp_parse_percent (%+010lld) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "+000012345") == 0,
		"fp_parse_percent (%+010lld) : buf.data"
	);
}

// case much flags %d
void		test_parse_percent_case4(void)
{
	printf(KYEL "test_parse_percent_case4\n" KNRM);
	const char	*format = "%+04ll-hhl10d";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345) == ft_strlen(format),
		"fp_parse_percent (%+04ll-hhl10d) : return value"
	);

	test(
		buf.i == 9,
		"fp_parse_percent (%+04ll-hhl10d) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "+12345    ") == 0,
		"fp_parse_percent (%+04ll-hhl10d) : buf.data"
	);
}

// case %u
void		test_parse_percent_case5(void)
{
	printf(KYEL "test_parse_percent_case5\n" KNRM);
	const char	*format = "%u";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345) == ft_strlen(format),
		"fp_parse_percent (%u) : return value"
	);

	test(
		buf.i == 4,
		"fp_parse_percent (%u) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "12345") == 0,
		"fp_parse_percent (%u) : buf.data"
	);
}

// case %010llu
void		test_parse_percent_case6(void)
{
	printf(KYEL "test_parse_percent_case6\n" KNRM);
	const char	*format = "%010llu";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345) == ft_strlen(format),
		"fp_parse_percent (%010llu) : return value"
	);

	test(
		buf.i == 9,
		"fp_parse_percent (%010llu) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "0000012345") == 0,
		"fp_parse_percent (%010llu) : buf.data"
	);
}

// case much flags %u
void		test_parse_percent_case7(void)
{
	printf(KYEL "test_parse_percent_case7\n" KNRM);
	const char	*format = "%010-6+0hhu";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345) == ft_strlen(format),
		"fp_parse_percent (%010-6+0hhu) : return value"
	);

	test(
		buf.i == 5,
		"fp_parse_percent (%010-6+0hhu) : buf.i"
	);

	test(
		ft_strcmp(buf.data, "57    ") == 0,
		"fp_parse_percent (%010-6+0hhu) : buf.data"
	);
}

// case %f
void		test_parse_percent_case8(void)
{
	printf(KYEL "test_parse_percent_case8\n" KNRM);
	const char	*format = "%f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.140000") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case %.1f
void		test_parse_percent_case9(void)
{
	printf(KYEL "test_parse_percent_case9\n" KNRM);
	const char	*format = "%.1f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.1") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case %10.1f
void		test_parse_percent_case10(void)
{
	printf(KYEL "test_parse_percent_case10\n" KNRM);
	const char	*format = "%10.1f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "       3.1") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case %+020.10f
void		test_parse_percent_case11(void)
{
	printf(KYEL "test_parse_percent_case11\n" KNRM);
	const char	*format = "%+020.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.00000000009) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "+00000000.0000000001") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case %+-020.10f
void		test_parse_percent_case12(void)
{
	printf(KYEL "test_parse_percent_case12\n" KNRM);
	const char	*format = "%+-020.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.00000000009) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "+99.0000000001      ") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case %+20.10f
void		test_parse_percent_case13(void)
{
	printf(KYEL "test_parse_percent_case13\n" KNRM);
	const char	*format = "%+20.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.00000000009) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "      +99.0000000001") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case % 20.10f
void		test_parse_percent_case14(void)
{
	printf(KYEL "test_parse_percent_case14\n" KNRM);
	const char	*format = "% 20.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.00000000009) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "       99.0000000001") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case % 20.10f (nan)
void		test_parse_percent_case15(void)
{
	printf(KYEL "test_parse_percent_case15\n" KNRM);
	const char	*format = "% 20.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, NAN) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "                 nan") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case % 20.10f (-inf)
void		test_parse_percent_case16(void)
{
	printf(KYEL "test_parse_percent_case16\n" KNRM);
	const char	*format = "% 20.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -INFINITY) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "                -inf") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case % 020.10f (-inf)
void		test_parse_percent_case17(void)
{
	printf(KYEL "test_parse_percent_case17\n" KNRM);
	const char	*format = "% 020.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -INFINITY) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "                -inf") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case more than width
void		test_parse_percent_case18(void)
{
	printf(KYEL "test_parse_percent_case18\n" KNRM);
	const char	*format = "% 020.10f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345678912345.99887766554433) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, " 12345678912345.9980468750") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case %020.d
void		test_parse_percent_case19(void)
{
	printf(KYEL "test_parse_percent_case19\n" KNRM);
	const char	*format = "%020.d";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 1) == ft_strlen(format),
		"fp_parse_percent (%020.d) : return value"
	);

	test(
		ft_strcmp(buf.data, "                   1") == 0,
		"fp_parse_percent (%020.d) : buf.data"
	);
}

// case %020.u
void		test_parse_percent_case20(void)
{
	printf(KYEL "test_parse_percent_case20\n" KNRM);
	const char	*format = "%020.u";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 1) == ft_strlen(format),
		"fp_parse_percent (%020.u) : return value"
	);

	test(
		ft_strcmp(buf.data, "                   1") == 0,
		"fp_parse_percent (%020.u) : buf.data"
	);
}

// case %x
void		test_parse_percent_case21(void)
{
	printf(KYEL "test_parse_percent_case21\n" KNRM);
	const char	*format = "%x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%x) : return value"
	);

	test(
		ft_strcmp(buf.data, "fedc") == 0,
		"fp_parse_percent (%x) : buf.data"
	);
}

// case %020x
void		test_parse_percent_case22(void)
{
	printf(KYEL "test_parse_percent_case22\n" KNRM);
	const char	*format = "%020x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%020x) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000000000000000fedc") == 0,
		"fp_parse_percent (%020x) : buf.data"
	);
}

// case % 20x
void		test_parse_percent_case23(void)
{
	printf(KYEL "test_parse_percent_case23\n" KNRM);
	const char	*format = "% 20x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (% 20x) : return value"
	);

	test(
		ft_strcmp(buf.data, "                fedc") == 0,
		"fp_parse_percent (% 20x) : buf.data"
	);
}

// case %+x
void		test_parse_percent_case24(void)
{
	printf(KYEL "test_parse_percent_case24\n" KNRM);
	const char	*format = "%+x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%+x) : return value"
	);

	test(
		ft_strcmp(buf.data, "fedc") == 0,
		"fp_parse_percent (%+x) : buf.data"
	);
}

// case %020.x
void		test_parse_percent_case25(void)
{
	printf(KYEL "test_parse_percent_case25\n" KNRM);
	const char	*format = "%020.x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%020.x) : return value"
	);

	test(
		ft_strcmp(buf.data, "                fedc") == 0,
		"fp_parse_percent (%020.x) : buf.data"
	);
}

// case %4x (more than width)
void		test_parse_percent_case26(void)
{
	printf(KYEL "test_parse_percent_case26\n" KNRM);
	const char	*format = "%4x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedcab12) == ft_strlen(format),
		"fp_parse_percent (%4x) : return value"
	);

	test(
		ft_strcmp(buf.data, "fedcab12") == 0,
		"fp_parse_percent (%4x) : buf.data"
	);
}

// case % 04x (0)
void		test_parse_percent_case27(void)
{
	printf(KYEL "test_parse_percent_case27\n" KNRM);
	const char	*format = "% 04x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (% 04x) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000") == 0,
		"fp_parse_percent (% 04x) : buf.data"
	);
}

// case %o
void		test_parse_percent_case28(void)
{
	printf(KYEL "test_parse_percent_case28\n" KNRM);
	const char	*format = "%o";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 07361435) == ft_strlen(format),
		"fp_parse_percent (%o) : return value"
	);

	test(
		ft_strcmp(buf.data, "7361435") == 0,
		"fp_parse_percent (%o) : buf.data"
	);
}

// case %+ 10hho
void		test_parse_percent_case29(void)
{
	printf(KYEL "test_parse_percent_case29\n" KNRM);
	const char	*format = "%+ 10hho";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 02023341) == ft_strlen(format),
		"fp_parse_percent (%+ 10hho) : return value"
	);

	test(
		ft_strcmp(buf.data, "       341") == 0,
		"fp_parse_percent (%+ 10hho) : buf.data"
	);
}

// case %+ 040l.o
void		test_parse_percent_case30(void)
{
	printf(KYEL "test_parse_percent_case30\n" KNRM);
	const char	*format = "%+ 040l.o";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 01777777777777777777777) == ft_strlen(format),
		"fp_parse_percent (%+ 040l.o) : return value"
	);

	test(
		ft_strcmp(buf.data, "                  1777777777777777777777") == 0,
		"fp_parse_percent (%+ 040l.o) : buf.data"
	);
}

// case %+ 040lo
void		test_parse_percent_case31(void)
{
	printf(KYEL "test_parse_percent_case31\n" KNRM);
	const char	*format = "%+ 040lo";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 01777777777777777777777) == ft_strlen(format),
		"fp_parse_percent (%+ 040lo) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000000000000000001777777777777777777777") == 0,
		"fp_parse_percent (%+ 040lo) : buf.data"
	);
}

// case %10.4f (-0.0)
void		test_parse_percent_case32(void)
{
	printf(KYEL "test_parse_percent_case32\n" KNRM);
	const char	*format = "%10.4f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -0.0) == ft_strlen(format),
		"fp_parse_percent (%10.4f) : return value"
	);

	test(
		ft_strcmp(buf.data, "   -0.0000") == 0,
		"fp_parse_percent (%10.4f) : buf.data"
	);
}

// case %010.4f (-0.0)
void		test_parse_percent_case33(void)
{
	printf(KYEL "test_parse_percent_case33\n" KNRM);
	const char	*format = "%010.4f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -0.0) == ft_strlen(format),
		"fp_parse_percent (%010.4f) : return value"
	);

	test(
		ft_strcmp(buf.data, "-0000.0000") == 0,
		"fp_parse_percent (%010.4f) : buf.data"
	);
}

// case %Lf
void		test_parse_percent_case34(void)
{
	printf(KYEL "test_parse_percent_case34\n" KNRM);
	const char	*format = "%Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14L) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.140000") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case %.1Lf
void		test_parse_percent_case35(void)
{
	printf(KYEL "test_parse_percent_case35\n" KNRM);
	const char	*format = "%.1Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14L) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.1") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case %10.1Lf
void		test_parse_percent_case36(void)
{
	printf(KYEL "test_parse_percent_case36\n" KNRM);
	const char	*format = "%10.1Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14L) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "       3.1") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case %+020.10Lf
void		test_parse_percent_case37(void)
{
	printf(KYEL "test_parse_percent_case37\n" KNRM);
	const char	*format = "%+020.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.00000000009L) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "+00000000.0000000001") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case %+-020.10Lf
void		test_parse_percent_case38(void)
{
	printf(KYEL "test_parse_percent_case38\n" KNRM);
	const char	*format = "%+-020.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.00000000009L) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "+99.0000000001      ") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case %+20.10Lf
void		test_parse_percent_case39(void)
{
	printf(KYEL "test_parse_percent_case39\n" KNRM);
	const char	*format = "%+20.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.00000000009L) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "      +99.0000000001") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case % 20.10Lf
void		test_parse_percent_case40(void)
{
	printf(KYEL "test_parse_percent_case40\n" KNRM);
	const char	*format = "% 20.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.00000000009L) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "       99.0000000001") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case % 20.10Lf (nan)
void		test_parse_percent_case41(void)
{
	printf(KYEL "test_parse_percent_case41\n" KNRM);
	const char	*format = "% 20.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, (long double)NAN) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "                 nan") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case % 20.10Lf (-inf)
void		test_parse_percent_case42(void)
{
	printf(KYEL "test_parse_percent_case42\n" KNRM);
	const char	*format = "% 20.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -HUGE_VALL) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "                -inf") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case % 020.10Lf (-inf)
void		test_parse_percent_case43(void)
{
	printf(KYEL "test_parse_percent_case43\n" KNRM);
	const char	*format = "% 020.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -HUGE_VALL) == ft_strlen(format),
		"fp_parse_percent (%f) : return value"
	);

	test(
		ft_strcmp(buf.data, "                -inf") == 0,
		"fp_parse_percent (%f) : buf.data"
	);
}

// case more than width
void		test_parse_percent_case44(void)
{
	printf(KYEL "test_parse_percent_case44\n" KNRM);
	const char	*format = "% 020.10Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 12345678912345.99887766554433L) == ft_strlen(format),
		"fp_parse_percent (%Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, " 12345678912345.9988775253") == 0,
		"fp_parse_percent (%Lf) : buf.data"
	);
}

// case %s
void		test_parse_percent_case45(void)
{
	printf(KYEL "test_parse_percent_case45\n" KNRM);
	const char	*format = "%s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "hello world") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %.s
void		test_parse_percent_case46(void)
{
	printf(KYEL "test_parse_percent_case46\n" KNRM);
	const char	*format = "%.s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %.2s
void		test_parse_percent_case47(void)
{
	printf(KYEL "test_parse_percent_case47\n" KNRM);
	const char	*format = "%.2s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "he") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %3.2s
void		test_parse_percent_case48(void)
{
	printf(KYEL "test_parse_percent_case48\n" KNRM);
	const char	*format = "%3.2s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, " he") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %-3.2s
void		test_parse_percent_case49(void)
{
	printf(KYEL "test_parse_percent_case49\n" KNRM);
	const char	*format = "%-3.2s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "he ") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %hhllh +020s
void		test_parse_percent_case50(void)
{
	printf(KYEL "test_parse_percent_case50\n" KNRM);
	const char	*format = "%hhllh +020s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "000000000hello world") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %hhllh +020.s
void		test_parse_percent_case51(void)
{
	printf(KYEL "test_parse_percent_case51\n" KNRM);
	const char	*format = "%hhllh +020.s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "00000000000000000000") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %8.2s
void		test_parse_percent_case52(void)
{
	printf(KYEL "test_parse_percent_case52\n" KNRM);
	const char	*format = "%8.2s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "      he") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %1.2s
void		test_parse_percent_case53(void)
{
	printf(KYEL "test_parse_percent_case53\n" KNRM);
	const char	*format = "%1.2s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "hello world") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "he") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %10s ("")
void		test_parse_percent_case54(void)
{
	printf(KYEL "test_parse_percent_case54\n" KNRM);
	const char	*format = "%10s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "          ") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %10.1s ("")
void		test_parse_percent_case55(void)
{
	printf(KYEL "test_parse_percent_case55\n" KNRM);
	const char	*format = "%10.1s";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, "") == ft_strlen(format),
		"fp_parse_percent (%s) : return value"
	);

	test(
		ft_strcmp(buf.data, "          ") == 0,
		"fp_parse_percent (%s) : buf.data"
	);
}

// case %c
void		test_parse_percent_case56(void)
{
	printf(KYEL "test_parse_percent_case56\n" KNRM);
	const char	*format = "%c";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 'h') == ft_strlen(format),
		"fp_parse_percent (%c) : return value"
	);

	test(
		ft_strcmp(buf.data, "h") == 0,
		"fp_parse_percent (%c) : buf.data"
	);
}

// case %020.c
void		test_parse_percent_case57(void)
{
	printf(KYEL "test_parse_percent_case57\n" KNRM);
	const char	*format = "%020.c";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 'h') == ft_strlen(format),
		"fp_parse_percent (%c) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000000000000000000h") == 0,
		"fp_parse_percent (%c) : buf.data"
	);
}

// case %-20c
void		test_parse_percent_case58(void)
{
	printf(KYEL "test_parse_percent_case58\n" KNRM);
	const char	*format = "%-20c";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 'h') == ft_strlen(format),
		"fp_parse_percent (%c) : return value"
	);

	test(
		ft_strcmp(buf.data, "h                   ") == 0,
		"fp_parse_percent (%c) : buf.data"
	);
}

// case %X
void		test_parse_percent_case59(void)
{
	printf(KYEL "test_parse_percent_case59\n" KNRM);
	const char	*format = "%X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%X) : return value"
	);

	test(
		ft_strcmp(buf.data, "FEDC") == 0,
		"fp_parse_percent (%X) : buf.data"
	);
}

// case %020X
void		test_parse_percent_case60(void)
{
	printf(KYEL "test_parse_percent_case60\n" KNRM);
	const char	*format = "%020X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%020X) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000000000000000FEDC") == 0,
		"fp_parse_percent (%020X) : buf.data"
	);
}

// case % 20X
void		test_parse_percent_case61(void)
{
	printf(KYEL "test_parse_percent_case61\n" KNRM);
	const char	*format = "% 20X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (% 20X) : return value"
	);

	test(
		ft_strcmp(buf.data, "                FEDC") == 0,
		"fp_parse_percent (% 20X) : buf.data"
	);
}

// case %+X
void		test_parse_percent_case62(void)
{
	printf(KYEL "test_parse_percent_case62\n" KNRM);
	const char	*format = "%+X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%+X) : return value"
	);

	test(
		ft_strcmp(buf.data, "FEDC") == 0,
		"fp_parse_percent (%+X) : buf.data"
	);
}

// case %020.X
void		test_parse_percent_case63(void)
{
	printf(KYEL "test_parse_percent_case63\n" KNRM);
	const char	*format = "%020.X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedc) == ft_strlen(format),
		"fp_parse_percent (%020.X) : return value"
	);

	test(
		ft_strcmp(buf.data, "                FEDC") == 0,
		"fp_parse_percent (%020.X) : buf.data"
	);
}

// case %4X (more than width)
void		test_parse_percent_case64(void)
{
	printf(KYEL "test_parse_percent_case64\n" KNRM);
	const char	*format = "%4X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xfedcab12) == ft_strlen(format),
		"fp_parse_percent (%4X) : return value"
	);

	test(
		ft_strcmp(buf.data, "FEDCAB12") == 0,
		"fp_parse_percent (%4X) : buf.data"
	);
}

// case % 04X (0)
void		test_parse_percent_case65(void)
{
	printf(KYEL "test_parse_percent_case65\n" KNRM);
	const char	*format = "% 04X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (% 04X) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000") == 0,
		"fp_parse_percent (% 04X) : buf.data"
	);
}

// case %#x
void		test_parse_percent_case66(void)
{
	printf(KYEL "test_parse_percent_case66\n" KNRM);
	const char	*format = "%#x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#x) : return value"
	);

	test(
		ft_strcmp(buf.data, "0xabcdef") == 0,
		"fp_parse_percent (%#x) : buf.data"
	);
}

// case %#x (0)
void		test_parse_percent_case67(void)
{
	printf(KYEL "test_parse_percent_case67\n" KNRM);
	const char	*format = "%#x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%#x) : return value"
	);

	test(
		ft_strcmp(buf.data, "0") == 0,
		"fp_parse_percent (%#x) : buf.data"
	);
}

// case %#020x
void		test_parse_percent_case68(void)
{
	printf(KYEL "test_parse_percent_case68\n" KNRM);
	const char	*format = "%#020x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#020x) : return value"
	);

	test(
		ft_strcmp(buf.data, "0x000000000000abcdef") == 0,
		"fp_parse_percent (%#020x) : buf.data"
	);
}

// case %#20x
void		test_parse_percent_case69(void)
{
	printf(KYEL "test_parse_percent_case69\n" KNRM);
	const char	*format = "%#20x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#20x) : return value"
	);

	test(
		ft_strcmp(buf.data, "            0xabcdef") == 0,
		"fp_parse_percent (%#20x) : buf.data"
	);
}

// case %#020.x
void		test_parse_percent_case70(void)
{
	printf(KYEL "test_parse_percent_case70\n" KNRM);
	const char	*format = "%#020.x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#020.x) : return value"
	);

	test(
		ft_strcmp(buf.data, "            0xabcdef") == 0,
		"fp_parse_percent (%#020.x) : buf.data"
	);
}

// case %#X
void		test_parse_percent_case71(void)
{
	printf(KYEL "test_parse_percent_case71\n" KNRM);
	const char	*format = "%#X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#X) : return value"
	);

	test(
		ft_strcmp(buf.data, "0XABCDEF") == 0,
		"fp_parse_percent (%#X) : buf.data"
	);
}

// case %#X (0)
void		test_parse_percent_case72(void)
{
	printf(KYEL "test_parse_percent_case72\n" KNRM);
	const char	*format = "%#X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%#X) : return value"
	);

	test(
		ft_strcmp(buf.data, "0") == 0,
		"fp_parse_percent (%#X) : buf.data"
	);
}

// case %#020X
void		test_parse_percent_case73(void)
{
	printf(KYEL "test_parse_percent_case73\n" KNRM);
	const char	*format = "%#020X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#020X) : return value"
	);

	test(
		ft_strcmp(buf.data, "0X000000000000ABCDEF") == 0,
		"fp_parse_percent (%#020X) : buf.data"
	);
}

// case %#20X
void		test_parse_percent_case74(void)
{
	printf(KYEL "test_parse_percent_case74\n" KNRM);
	const char	*format = "%#20X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#20X) : return value"
	);

	test(
		ft_strcmp(buf.data, "            0XABCDEF") == 0,
		"fp_parse_percent (%#20X) : buf.data"
	);
}

// case %#020.X
void		test_parse_percent_case75(void)
{
	printf(KYEL "test_parse_percent_case75\n" KNRM);
	const char	*format = "%#020.X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#020.X) : return value"
	);

	test(
		ft_strcmp(buf.data, "            0XABCDEF") == 0,
		"fp_parse_percent (%#020.X) : buf.data"
	);
}

// case %#-020X
void		test_parse_percent_case76(void)
{
	printf(KYEL "test_parse_percent_case76\n" KNRM);
	const char	*format = "%#-020X";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%#-020X) : return value"
	);

	test(
		ft_strcmp(buf.data, "0XABCDEF            ") == 0,
		"fp_parse_percent (%#-020X) : buf.data"
	);
}

// case %p
void		test_parse_percent_case77(void)
{
	printf(KYEL "test_parse_percent_case77\n" KNRM);
	const char	*format = "%p";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%p) : return value"
	);

	test(
		ft_strcmp(buf.data, "0xabcdef") == 0,
		"fp_parse_percent (%p) : buf.data"
	);
}

// case %020p
void		test_parse_percent_case78(void)
{
	printf(KYEL "test_parse_percent_case78\n" KNRM);
	const char	*format = "%020p";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%020p) : return value"
	);

	test(
		ft_strcmp(buf.data, "0x000000000000abcdef") == 0,
		"fp_parse_percent (%020p) : buf.data"
	);
}

// case %020.p
void		test_parse_percent_case79(void)
{
	printf(KYEL "test_parse_percent_case79\n" KNRM);
	const char	*format = "%020.p";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0xabcdef) == ft_strlen(format),
		"fp_parse_percent (%020.p) : return value"
	);

	test(
		ft_strcmp(buf.data, "            0xabcdef") == 0,
		"fp_parse_percent (%020.p) : buf.data"
	);
}

// case %020p (0)
void		test_parse_percent_case80(void)
{
	printf(KYEL "test_parse_percent_case80\n" KNRM);
	const char	*format = "%020p";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0x0) == ft_strlen(format),
		"fp_parse_percent (%020p) : return value"
	);

	test(
		ft_strcmp(buf.data, "0x000000000000000000") == 0,
		"fp_parse_percent (%020p) : buf.data"
	);
}

// case %#.f
void		test_parse_percent_case81(void)
{
	printf(KYEL "test_parse_percent_case81\n" KNRM);
	const char	*format = "%#.f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14) == ft_strlen(format),
		"fp_parse_percent (%#.f) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.") == 0,
		"fp_parse_percent (%#.f) : buf.data"
	);
}

// case %#f
void		test_parse_percent_case82(void)
{
	printf(KYEL "test_parse_percent_case82\n" KNRM);
	const char	*format = "%#f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14) == ft_strlen(format),
		"fp_parse_percent (%#f) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.140000") == 0,
		"fp_parse_percent (%#f) : buf.data"
	);
}

// case %#.f (nan)
void		test_parse_percent_case83(void)
{
	printf(KYEL "test_parse_percent_case83\n" KNRM);
	const char	*format = "%#.f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, NAN) == ft_strlen(format),
		"fp_parse_percent (%#.f) : return value"
	);

	test(
		ft_strcmp(buf.data, "nan") == 0,
		"fp_parse_percent (%#.f) : buf.data"
	);
}

// case %#.f (inf)
void		test_parse_percent_case84(void)
{
	printf(KYEL "test_parse_percent_case84\n" KNRM);
	const char	*format = "%#.f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, INFINITY) == ft_strlen(format),
		"fp_parse_percent (%#.f) : return value"
	);

	test(
		ft_strcmp(buf.data, "inf") == 0,
		"fp_parse_percent (%#.f) : buf.data"
	);
}

// case %#.f (-inf)
void		test_parse_percent_case85(void)
{
	printf(KYEL "test_parse_percent_case85\n" KNRM);
	const char	*format = "%#.f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -INFINITY) == ft_strlen(format),
		"fp_parse_percent (%#.f) : return value"
	);

	test(
		ft_strcmp(buf.data, "-inf") == 0,
		"fp_parse_percent (%#.f) : buf.data"
	);
}

// case %#.Lf
void		test_parse_percent_case86(void)
{
	printf(KYEL "test_parse_percent_case86\n" KNRM);
	const char	*format = "%#.Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14L) == ft_strlen(format),
		"fp_parse_percent (%#.Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.") == 0,
		"fp_parse_percent (%#.Lf) : buf.data"
	);
}

// case %#Lf
void		test_parse_percent_case87(void)
{
	printf(KYEL "test_parse_percent_case87\n" KNRM);
	const char	*format = "%#Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.14L) == ft_strlen(format),
		"fp_parse_percent (%#Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.140000") == 0,
		"fp_parse_percent (%#Lf) : buf.data"
	);
}

// case %#.Lf (nan)
void		test_parse_percent_case88(void)
{
	printf(KYEL "test_parse_percent_case88\n" KNRM);
	const char	*format = "%#.Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, (long double)NAN) == ft_strlen(format),
		"fp_parse_percent (%#.Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "nan") == 0,
		"fp_parse_percent (%#.Lf) : buf.data"
	);
}

// case %#.Lf (inf)
void		test_parse_percent_case89(void)
{
	printf(KYEL "test_parse_percent_case89\n" KNRM);
	const char	*format = "%#.Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, HUGE_VALL) == ft_strlen(format),
		"fp_parse_percent (%#.Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "inf") == 0,
		"fp_parse_percent (%#.Lf) : buf.data"
	);
}

// case %#.Lf (-inf)
void		test_parse_percent_case90(void)
{
	printf(KYEL "test_parse_percent_case90\n" KNRM);
	const char	*format = "%#.Lf";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -HUGE_VALL) == ft_strlen(format),
		"fp_parse_percent (%#.Lf) : return value"
	);

	test(
		ft_strcmp(buf.data, "-inf") == 0,
		"fp_parse_percent (%#.Lf) : buf.data"
	);
}

// case %,'*:20;_c
void		test_parse_percent_case91(void)
{
	printf(KYEL "test_parse_percent_case91\n" KNRM);
	const char	*format = "%,'*:20;_c";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 'h') == ft_strlen(format),
		"fp_parse_percent (%,'*:20;_c) : return value"
	);

	test(
		ft_strcmp(buf.data, "                   h") == 0,
		"fp_parse_percent (%,'*:20;_c) : buf.data"
	);
}

// case %@c
void		test_parse_percent_case92(void)
{
	printf(KYEL "test_parse_percent_case92\n" KNRM);
	const char	*format = "%@c";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 'h') == 2,
		"fp_parse_percent (%@c) : return value"
	);

	test(
		ft_strcmp(buf.data, "@") == 0,
		"fp_parse_percent (%@c) : buf.data"
	);
}

// case %020(c
void		test_parse_percent_case93(void)
{
	printf(KYEL "test_parse_percent_case93\n" KNRM);
	const char	*format = "%020(c";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 'h') == 5,
		"fp_parse_percent (%020(c) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000000000000000000(") == 0,
		"fp_parse_percent (%020(c) : buf.data"
	);
}

// case %020(c
void		test_parse_percent_case94(void)
{
	printf(KYEL "test_parse_percent_case94\n" KNRM);
	const char	*format = "%020%";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 'h') == 5,
		"fp_parse_percent (%020%) : return value"
	);

	test(
		ft_strcmp(buf.data, "0000000000000000000%") == 0,
		"fp_parse_percent (%020%) : buf.data"
	);
}

// case %.5d
void		test_parse_percent_case95(void)
{
	printf(KYEL "test_parse_percent_case95\n" KNRM);
	const char	*format = "%.5d";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 42) == ft_strlen(format),
		"fp_parse_percent (%.5d) : return value"
	);

	test(
		ft_strcmp(buf.data, "00042") == 0,
		"fp_parse_percent (%.5d) : buf.data"
	);
}

// case %#.x (0)
void		test_parse_percent_case96(void)
{
	printf(KYEL "test_parse_percent_case96\n" KNRM);
	const char	*format = "%#.x";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%#.x) : return value"
	);

	test(
		ft_strcmp(buf.data, "") == 0,
		"fp_parse_percent (%#.x) : buf.data"
	);
}

// case %#.5o
void		test_parse_percent_case97(void)
{
	printf(KYEL "test_parse_percent_case97\n" KNRM);
	const char	*format = "%#.5o";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 42) == ft_strlen(format),
		"fp_parse_percent (%#.5o) : return value"
	);

	test(
		ft_strcmp(buf.data, "00052") == 0,
		"fp_parse_percent (%#.5o) : buf.data"
	);
}

// case %.20u
void		test_parse_percent_case98(void)
{
	printf(KYEL "test_parse_percent_case98\n" KNRM);
	const char	*format = "%.20u";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%.20u) : return value"
	);

	test(
		ft_strcmp(buf.data, "00000000000000000000") == 0,
		"fp_parse_percent (%.20u) : buf.data"
	);
}

// case %#o (0)
void		test_parse_percent_case99(void)
{
	printf(KYEL "test_parse_percent_case99\n" KNRM);
	const char	*format = "%#o";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%#o) : return value"
	);

	test(
		ft_strcmp(buf.data, "0") == 0,
		"fp_parse_percent (%#o) : buf.data"
	);
}

// case %#.o (0)
void		test_parse_percent_case100(void)
{
	printf(KYEL "test_parse_percent_case100\n" KNRM);
	const char	*format = "%#.o";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%#.o) : return value"
	);

	test(
		ft_strcmp(buf.data, "0") == 0,
		"fp_parse_percent (%#.o) : buf.data"
	);
}

// case %.o (0)
void		test_parse_percent_case101(void)
{
	printf(KYEL "test_parse_percent_case101\n" KNRM);
	const char	*format = "%.o";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%.o) : return value"
	);

	test(
		ft_strcmp(buf.data, "") == 0,
		"fp_parse_percent (%.o) : buf.data"
	);
}

// case %
void		test_parse_percent_case102(void)
{
	printf(KYEL "test_parse_percent_case102\n" KNRM);
	const char	*format = "%";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0) == ft_strlen(format),
		"fp_parse_percent (%) : return value"
	);

	test(
		ft_strcmp(buf.data, "") == 0,
		"fp_parse_percent (%) : buf.data"
	);
}

// case %ls
void		test_parse_percent_case103(void)
{
	printf(KYEL "test_parse_percent_case103\n" KNRM);
	const char			*format = "%ls";
	t_fp_buffer			buf;
	unsigned char		expected[21] = {
		0xea, 0xb0, 0x80,
		0xeb, 0x82, 0x98,
		0x61,
		0xeb, 0x8b, 0xa4,
		0xf0, 0x9f, 0x92, 0xbb,
		0xeb, 0x9d, 0xbc,
		0x3b,
		0x3b,
		0x61,
		0x6b
	};

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, L"가나a다💻라;;ak") == ft_strlen(format),
		"fp_parse_percent (%ls) : return value"
	);

	test(
		buf.i == 20,
		"fp_parse_percent (%ls) : buf.i"
	);

	test(
		ft_memcmp(buf.data, expected, 21) == 0,
		"fp_parse_percent (%ls) : buf.data"
	);
}

// case %.7ls
void		test_parse_percent_case104(void)
{
	printf(KYEL "test_parse_percent_case104\n" KNRM);
	const char			*format = "%.7ls";
	t_fp_buffer			buf;
	unsigned char		expected[21] = {
		0xea, 0xb0, 0x80,
		0xeb, 0x82, 0x98,
		0x61,
		0xeb, 0x8b, 0xa4,
		0xf0, 0x9f, 0x92, 0xbb,
		0xeb, 0x9d, 0xbc,
		0x3b,
		0x3b,
		0x61,
		0x6b
	};

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, L"가나a다💻라;;ak") == ft_strlen(format),
		"fp_parse_percent (%.7ls) : return value"
	);

	test(
		buf.i == 6,
		"fp_parse_percent (%ls) : buf.i"
	);

	test(
		ft_memcmp(buf.data, expected, 7) == 0,
		"fp_parse_percent (%.7ls) : buf.data"
	);
}

// case %.9ls
void		test_parse_percent_case105(void)
{
	printf(KYEL "test_parse_percent_case105\n" KNRM);
	const char			*format = "%.9ls";
	t_fp_buffer			buf;
	unsigned char		expected[21] = {
		0xea, 0xb0, 0x80,
		0xeb, 0x82, 0x98,
		0x61,
		0xeb, 0x8b, 0xa4,
		0xf0, 0x9f, 0x92, 0xbb,
		0xeb, 0x9d, 0xbc,
		0x3b,
		0x3b,
		0x61,
		0x6b
	};

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, L"가나a다💻라;;ak") == ft_strlen(format),
		"fp_parse_percent (%.9ls) : return value"
	);

	test(
		buf.i == 6,
		"fp_parse_percent (%ls) : buf.i"
	);

	test(
		ft_memcmp(buf.data, expected, 7) == 0,
		"fp_parse_percent (%.9ls) : buf.data"
	);
}

// case %08.2f carry
void		test_parse_percent_case106(void)
{
	printf(KYEL "test_parse_percent_case106\n" KNRM);
	const char	*format = "%08.2f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.999) == ft_strlen(format),
		"fp_parse_percent (%08.2f) : return value"
	);

	test(
		ft_strcmp(buf.data, "00100.00") == 0,
		"fp_parse_percent (%08.2f) : buf.data"
	);
}

// case %8.2f carry
void		test_parse_percent_case107(void)
{
	printf(KYEL "test_parse_percent_case107\n" KNRM);
	const char	*format = "%8.2f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 99.999) == ft_strlen(format),
		"fp_parse_percent (%8.2f) : return value"
	);

	test(
		ft_strcmp(buf.data, "  100.00") == 0,
		"fp_parse_percent (%8.2f) : buf.data"
	);
}

// case %8.2f carry
void		test_parse_percent_case108(void)
{
	printf(KYEL "test_parse_percent_case108\n" KNRM);
	const char	*format = "%8.2f";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -99.999) == ft_strlen(format),
		"fp_parse_percent (%8.2f) : return value"
	);

	test(
		ft_strcmp(buf.data, " -100.00") == 0,
		"fp_parse_percent (%8.2f) : buf.data"
	);
}

// case %e
void		test_parse_percent_case109(void)
{
	printf(KYEL "test_parse_percent_case109\n" KNRM);
	const char	*format = "%e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.141592) == ft_strlen(format),
		"fp_parse_percent (%e) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.141592e+00") == 0,
		"fp_parse_percent (%e) : buf.data"
	);
}

// case %15e
void		test_parse_percent_case110(void)
{
	printf(KYEL "test_parse_percent_case110\n" KNRM);
	const char	*format = "%15e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 9.9999999999999999e5) == ft_strlen(format),
		"fp_parse_percent (%15e) : return value"
	);

	test(
		ft_strcmp(buf.data, "   1.000000e+06") == 0,
		"fp_parse_percent (%15e) : buf.data"
	);
}

// case %015e
void		test_parse_percent_case111(void)
{
	printf(KYEL "test_parse_percent_case111\n" KNRM);
	const char	*format = "%015e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 9.9999999999999999e-100) == ft_strlen(format),
		"fp_parse_percent (%015e) : return value"
	);

	test(
		ft_strcmp(buf.data, "0001.000000e-99") == 0,
		"fp_parse_percent (%015e) : buf.data"
	);
}

// case %015.3e
void		test_parse_percent_case112(void)
{
	printf(KYEL "test_parse_percent_case112\n" KNRM);
	const char	*format = "%015.3e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 9.9999999999999999e-101) == ft_strlen(format),
		"fp_parse_percent (%015.3e) : return value"
	);

	test(
		ft_strcmp(buf.data, "000001.000e-100") == 0,
		"fp_parse_percent (%015.3e) : buf.data"
	);
}

// case %+15.3e
void		test_parse_percent_case113(void)
{
	printf(KYEL "test_parse_percent_case113\n" KNRM);
	const char	*format = "%+15.3e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 1.234512345e-100) == ft_strlen(format),
		"fp_parse_percent (%+15.3e) : return value"
	);

	test(
		ft_strcmp(buf.data, "    +1.235e-100") == 0,
		"fp_parse_percent (%+15.3e) : buf.data"
	);
}

// case % 15.3e
void		test_parse_percent_case114(void)
{
	printf(KYEL "test_parse_percent_case114\n" KNRM);
	const char	*format = "% 15.3e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 1.234512345e-100) == ft_strlen(format),
		"fp_parse_percent (% 15.3e) : return value"
	);

	test(
		ft_strcmp(buf.data, "     1.235e-100") == 0,
		"fp_parse_percent (% 15.3e) : buf.data"
	);
}

// case %.3e (0.0)
void		test_parse_percent_case115(void)
{
	printf(KYEL "test_parse_percent_case115\n" KNRM);
	const char	*format = "%.3e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0) == ft_strlen(format),
		"fp_parse_percent (%.3e) : return value"
	);

	test(
		ft_strcmp(buf.data, "0.000e+00") == 0,
		"fp_parse_percent (%.3e) : buf.data"
	);
}

// case %.e (0.0)
void		test_parse_percent_case116(void)
{
	printf(KYEL "test_parse_percent_case116\n" KNRM);
	const char	*format = "%.e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0) == ft_strlen(format),
		"fp_parse_percent (%.e) : return value"
	);

	test(
		ft_strcmp(buf.data, "0e+00") == 0,
		"fp_parse_percent (%.e) : buf.data"
	);
}

// case %.e (0.0, #)
void		test_parse_percent_case117(void)
{
	printf(KYEL "test_parse_percent_case117\n" KNRM);
	const char	*format = "%#.e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0) == ft_strlen(format),
		"fp_parse_percent (%#.e) : return value"
	);

	test(
		ft_strcmp(buf.data, "0.e+00") == 0,
		"fp_parse_percent (%#.e) : buf.data"
	);
}

// case %#+.e (0.0)
void		test_parse_percent_case118(void)
{
	printf(KYEL "test_parse_percent_case118\n" KNRM);
	const char	*format = "%#+.e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0) == ft_strlen(format),
		"fp_parse_percent (%#+.e) : return value"
	);

	test(
		ft_strcmp(buf.data, "+0.e+00") == 0,
		"fp_parse_percent (%#+.e) : buf.data"
	);
}

// case %+.e (-0.0)
void		test_parse_percent_case119(void)
{
	printf(KYEL "test_parse_percent_case119\n" KNRM);
	const char	*format = "%+.e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -0.0) == ft_strlen(format),
		"fp_parse_percent (%+.e) : return value"
	);

	test(
		ft_strcmp(buf.data, "-0e+00") == 0,
		"fp_parse_percent (%+.e) : buf.data"
	);
}

// case %010.2e (nan)
void		test_parse_percent_case120(void)
{
	printf(KYEL "test_parse_percent_case120\n" KNRM);
	const char	*format = "%010.2e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, NAN) == ft_strlen(format),
		"fp_parse_percent (%010.2e) : return value"
	);

	test(
		ft_strcmp(buf.data, "       nan") == 0,
		"fp_parse_percent (%010.2e) : buf.data"
	);
}

// case %010.2e (inf)
void		test_parse_percent_case121(void)
{
	printf(KYEL "test_parse_percent_case121\n" KNRM);
	const char	*format = "%010.2e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, INFINITY) == ft_strlen(format),
		"fp_parse_percent (%010.2e) : return value"
	);

	test(
		ft_strcmp(buf.data, "       inf") == 0,
		"fp_parse_percent (%010.2e) : buf.data"
	);
}

// case %+010.2e (inf)
void		test_parse_percent_case122(void)
{
	printf(KYEL "test_parse_percent_case122\n" KNRM);
	const char	*format = "%+010.2e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, INFINITY) == ft_strlen(format),
		"fp_parse_percent (%+010.2e) : return value"
	);

	test(
		ft_strcmp(buf.data, "      +inf") == 0,
		"fp_parse_percent (%+010.2e) : buf.data"
	);
}

// case %+010.2e (-inf)
void		test_parse_percent_case123(void)
{
	printf(KYEL "test_parse_percent_case123\n" KNRM);
	const char	*format = "%+010.2e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -INFINITY) == ft_strlen(format),
		"fp_parse_percent (%+010.2e) : return value"
	);

	test(
		ft_strcmp(buf.data, "      -inf") == 0,
		"fp_parse_percent (%+010.2e) : buf.data"
	);
}

// case %Le
void		test_parse_percent_case124(void)
{
	printf(KYEL "test_parse_percent_case124\n" KNRM);
	const char	*format = "%Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 3.141592L) == ft_strlen(format),
		"fp_parse_percent (%Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "3.141592e+00") == 0,
		"fp_parse_percent (%Le) : buf.data"
	);
}

// case %15e
void		test_parse_percent_case125(void)
{
	printf(KYEL "test_parse_percent_case125\n" KNRM);
	const char	*format = "%15e";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 9.9999999999999999e5) == ft_strlen(format),
		"fp_parse_percent (%15e) : return value"
	);

	test(
		ft_strcmp(buf.data, "   1.000000e+06") == 0,
		"fp_parse_percent (%15e) : buf.data"
	);
}

// case %015Le
void		test_parse_percent_case126(void)
{
	printf(KYEL "test_parse_percent_case126\n" KNRM);
	const char	*format = "%015Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 9.9999999999999999e-100L) == ft_strlen(format),
		"fp_parse_percent (%015Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "0001.000000e-99") == 0,
		"fp_parse_percent (%015Le) : buf.data"
	);
}

// case %015.3Le
void		test_parse_percent_case127(void)
{
	printf(KYEL "test_parse_percent_case127\n" KNRM);
	const char	*format = "%015.3Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 9.9999999999999999e-101L) == ft_strlen(format),
		"fp_parse_percent (%015.3Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "000001.000e-100") == 0,
		"fp_parse_percent (%015.3Le) : buf.data"
	);
}

// case %+15.3Le
void		test_parse_percent_case128(void)
{
	printf(KYEL "test_parse_percent_case128\n" KNRM);
	const char	*format = "%+15.3Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 1.234512345e-100L) == ft_strlen(format),
		"fp_parse_percent (%+15.3Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "    +1.235e-100") == 0,
		"fp_parse_percent (%+15.3Le) : buf.data"
	);
}

// case % 15.3Le
void		test_parse_percent_case129(void)
{
	printf(KYEL "test_parse_percent_case129\n" KNRM);
	const char	*format = "% 15.3Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 1.234512345e-100L) == ft_strlen(format),
		"fp_parse_percent (% 15.3Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "     1.235e-100") == 0,
		"fp_parse_percent (% 15.3Le) : buf.data"
	);
}

// case %.3Le (0.0)
void		test_parse_percent_case130(void)
{
	printf(KYEL "test_parse_percent_case130\n" KNRM);
	const char	*format = "%.3Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0L) == ft_strlen(format),
		"fp_parse_percent (%.3Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "0.000e+00") == 0,
		"fp_parse_percent (%.3Le) : buf.data"
	);
}

// case %.Le (0.0)
void		test_parse_percent_case131(void)
{
	printf(KYEL "test_parse_percent_case131\n" KNRM);
	const char	*format = "%.Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0L) == ft_strlen(format),
		"fp_parse_percent (%.Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "0e+00") == 0,
		"fp_parse_percent (%.Le) : buf.data"
	);
}

// case %.Le (0.0, #)
void		test_parse_percent_case132(void)
{
	printf(KYEL "test_parse_percent_case132\n" KNRM);
	const char	*format = "%#.Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0L) == ft_strlen(format),
		"fp_parse_percent (%#.Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "0.e+00") == 0,
		"fp_parse_percent (%#.e) : buf.data"
	);
}

// case %#+.Le (0.0)
void		test_parse_percent_case133(void)
{
	printf(KYEL "test_parse_percent_case133\n" KNRM);
	const char	*format = "%#+.Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, 0.0L) == ft_strlen(format),
		"fp_parse_percent (%#+.Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "+0.e+00") == 0,
		"fp_parse_percent (%#+.Le) : buf.data"
	);
}

// case %+.Le (-0.0)
void		test_parse_percent_case134(void)
{
	printf(KYEL "test_parse_percent_case134\n" KNRM);
	const char	*format = "%+.Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -0.0L) == ft_strlen(format),
		"fp_parse_percent (%+.Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "-0e+00") == 0,
		"fp_parse_percent (%+.Le) : buf.data"
	);
}

// case %010.2Le (nan)
void		test_parse_percent_case135(void)
{
	printf(KYEL "test_parse_percent_case135\n" KNRM);
	const char	*format = "%010.2Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, (long double)NAN) == ft_strlen(format),
		"fp_parse_percent (%010.2Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "       nan") == 0,
		"fp_parse_percent (%010.2Le) : buf.data"
	);
}

// case %010.2Le (inf)
void		test_parse_percent_case136(void)
{
	printf(KYEL "test_parse_percent_case136\n" KNRM);
	const char	*format = "%010.2Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, HUGE_VALL) == ft_strlen(format),
		"fp_parse_percent (%010.2Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "       inf") == 0,
		"fp_parse_percent (%010.2Le) : buf.data"
	);
}

// case %+010.2Le (inf)
void		test_parse_percent_case137(void)
{
	printf(KYEL "test_parse_percent_case137\n" KNRM);
	const char	*format = "%+010.2Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, HUGE_VALL) == ft_strlen(format),
		"fp_parse_percent (%+010.2Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "      +inf") == 0,
		"fp_parse_percent (%+010.2Le) : buf.data"
	);
}

// case %+010.2Le (-inf)
void		test_parse_percent_case138(void)
{
	printf(KYEL "test_parse_percent_case138\n" KNRM);
	const char	*format = "%+010.2Le";
	t_fp_buffer	buf;

	fp_init_buffer(&buf);

	test(
		parse(format, &buf, -HUGE_VALL) == ft_strlen(format),
		"fp_parse_percent (%+010.2Le) : return value"
	);

	test(
		ft_strcmp(buf.data, "      -inf") == 0,
		"fp_parse_percent (%+010.2Le) : buf.data"
	);
}
