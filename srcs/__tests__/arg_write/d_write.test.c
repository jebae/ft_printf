#include "ft_printf.test.h"

void		test_arg_d_write_case1(void)
{
	printf(KYEL "test_arg_d_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 123;
	fp_arg_d_write(&data, NULL, fp_arg_d_length(&data, NULL), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %d\n", (int)data.i);
}

void		test_arg_d_write_case2(void)
{
	printf(KYEL "test_arg_d_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = -123;
	fp_arg_d_write(&data, NULL, fp_arg_d_length(&data, NULL), &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %d\n", (int)data.i);
}

void		test_arg_d_write_case3(void)
{
	printf(KYEL "test_arg_d_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 2147483647;
	fp_arg_d_write(&data, NULL, fp_arg_d_length(&data, NULL), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %d\n", (int)data.i);
}

void		test_arg_d_write_case4(void)
{
	printf(KYEL "test_arg_d_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0;
	fp_arg_d_write(&data, NULL, fp_arg_d_length(&data, NULL), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %d\n", (int)data.i);
}

void		test_arg_hd_write_case1(void)
{
	printf(KYEL "test_arg_hd_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = -32769;
	fp_arg_hd_write(&data, NULL, fp_arg_hd_length(&data, NULL), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hd\n", (short)data.i);
}

void		test_arg_hhd_write_case1(void)
{
	printf(KYEL "test_arg_hhd_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = -257;
	fp_arg_hhd_write(&data, NULL, fp_arg_hhd_length(&data, NULL), &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %hhd\n", (char)data.i);
}

void		test_arg_ld_write_case1(void)
{
	printf(KYEL "test_arg_ld_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 9223372036854775807;
	fp_arg_ld_write(&data, NULL, fp_arg_ld_length(&data, NULL), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %ld\n", (long)data.i);
}

void		test_arg_lld_write_case1(void)
{
	printf(KYEL "test_arg_lld_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 9223372036854775807;
	fp_arg_lld_write(&data, NULL, fp_arg_lld_length(&data, NULL), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %lld\n", data.i);
}
