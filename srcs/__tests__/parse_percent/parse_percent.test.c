#include "ft_printf.test.h"

static size_t	parse(
	const char *format,
	t_fp_buffer *buf,
	...
)
{
	va_list		ap;
	size_t		res;

	va_start(ap, buf);
	res = fp_parse_percent(format, ap, buf);
	va_end(ap);
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

/*
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
*/

// case nan
// case inf
// case -inf
// case 0
