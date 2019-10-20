#include "ft_printf.test.h"

void		test_int_write_case1(void)
{
	printf(KYEL "test_int_write_case1\n" KNRM);
	int				d = 123;
	size_t			len = fp_int_length(d, 10);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_int_write(d, len, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %d\n", d);
}

void		test_int_write_case2(void)
{
	printf(KYEL "test_int_write_case2\n" KNRM);
	long long		d = 9223372036854775807;
	size_t			len = fp_int_length(d, 10);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_int_write(d, len, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %lld\n", d);
}

void		test_int_write_case3(void)
{
	printf(KYEL "test_int_write_case3\n" KNRM);
	long long		d = -321;
	size_t			len = fp_int_length(d, 10);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_int_write(d, len, &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %lld\n", d);
}

void		test_int_write_case4(void)
{
	printf(KYEL "test_int_write_case4\n" KNRM);
	int				d = 0;
	size_t			len = fp_int_length(d, 10);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_int_write(d, len, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %d\n", d);
}

void		test_int_write_case5(void)
{
	printf(KYEL "test_int_write_case5\n" KNRM);
	int				d = 1;
	size_t			len = fp_int_length(d, 10);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_int_write(d, len, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %d\n", d);
}

// case type cast
void		test_int_write_case6(void)
{
	printf(KYEL "test_int_write_case6\n" KNRM);
	int				d = -2147483148;
	size_t			len = fp_int_length((short)d, 10);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_int_write((short)d, len, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hd\n", (short)d);
}

void		test_uint_write_case1(void)
{
	printf(KYEL "test_uint_write_case1\n" KNRM);
	unsigned int	d = 123;
	size_t			len = fp_uint_length(d, 10);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	fp_uint_write(d, len, 10, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %u\n", d);
}

void		test_uint_write_case2(void)
{
	printf(KYEL "test_uint_write_case2\n" KNRM);
	unsigned long long	d = 9223372036854775807;
	size_t				len = fp_uint_length(d, 10);
	t_fp_buffer			buf;

	fp_init_buffer(&buf);
	fp_uint_write(d, len, 10, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llu\n", d);
}

void		test_uint_write_case3(void)
{
	printf(KYEL "test_uint_write_case3\n" KNRM);
	unsigned long long		d = -321;
	size_t					len = fp_uint_length(d, 10);
	t_fp_buffer				buf;

	fp_init_buffer(&buf);
	fp_uint_write(d, len, 10, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llu\n", d);
}

void		test_uint_write_case4(void)
{
	printf(KYEL "test_uint_write_case4\n" KNRM);
	unsigned int			d = 0;
	size_t					len = fp_uint_length(d, 10);
	t_fp_buffer				buf;

	fp_init_buffer(&buf);
	fp_uint_write(d, len, 10, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %u\n", d);
}

void		test_uint_write_case5(void)
{
	printf(KYEL "test_uint_write_case5\n" KNRM);
	unsigned long long		d = ULLONG_MAX;
	size_t					len = fp_uint_length(d, 16);
	t_fp_buffer				buf;

	fp_init_buffer(&buf);
	fp_uint_write(d, len, 16, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llx\n", d);
}

void		test_uint_write_case6(void)
{
	printf(KYEL "test_uint_write_case6\n" KNRM);
	unsigned long long		d = ULLONG_MAX;
	size_t					len = fp_uint_length(d, 8);
	t_fp_buffer				buf;

	fp_init_buffer(&buf);
	fp_uint_write(d, len, 8, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llo\n", d);
}

void		test_uint_upper_write_case1(void)
{
	printf(KYEL "test_uint_upper_write_case1\n" KNRM);
	unsigned long long		d = ULLONG_MAX;
	size_t					len = fp_uint_length(d, 16);
	t_fp_buffer				buf;

	fp_init_buffer(&buf);
	fp_uint_upper_write(d, len, 16, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llX\n", d);
}

void		test_uint_upper_write_case2(void)
{
	printf(KYEL "test_uint_upper_write_case2\n" KNRM);
	unsigned long long		d = 0x2ab8def;
	size_t					len = fp_uint_length(d, 16);
	t_fp_buffer				buf;

	fp_init_buffer(&buf);
	fp_uint_upper_write(d, len, 16, &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llX\n", d);
}
