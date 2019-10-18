#include "ft_printf.test.h"

// case 3.14
void		test_arg_f_write_case1(void)
{
	printf(KYEL "test_arg_f_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f = 3.14;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %f\n", data.f);
}

// case negative
void		test_arg_f_write_case2(void)
{
	printf(KYEL "test_arg_f_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 6;
	data.f = -3.14;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s (no need sign)\n", buf.data);
	printf("expect : %f\n", data.f);
}

// case precision = 50
void		test_arg_f_write_case3(void)
{
	printf(KYEL "test_arg_f_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f = 9.87654321;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f);
}

// case precision = 0
void		test_arg_f_write_case4(void)
{
	printf(KYEL "test_arg_f_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 0;
	data.f = 9.87654321;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.0f\n", data.f);
}

// case 0
void		test_arg_f_write_case5(void)
{
	printf(KYEL "test_arg_f_write_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f = 0.0;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f);
}

// case inf
void		test_arg_f_write_case6(void)
{
	printf(KYEL "test_arg_f_write_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f = INFINITY;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f);
}

// case -inf
void		test_arg_f_write_case7(void)
{
	printf(KYEL "test_arg_f_write_case7\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f = -INFINITY;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f);
}

// case nan
void		test_arg_f_write_case8(void)
{
	printf(KYEL "test_arg_f_write_case8\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	tags.precision = 50;
	data.f = NAN;
	fp_arg_f_write(&data, &tags, fp_arg_f_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.50f\n", data.f);
}
