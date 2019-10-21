#include "ft_printf.test.h"

// case simple
void		test_arg_s_write_case1(void)
{
	printf(KYEL "test_arg_s_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	data.ptr = (void *)"hello world";
	fp_arg_s_write(&data, &tags, fp_arg_s_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %s\n", data.ptr);
}

// case ""
void		test_arg_s_write_case2(void)
{
	printf(KYEL "test_arg_s_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	data.ptr = (void *)"";
	fp_arg_s_write(&data, &tags, fp_arg_s_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %s\n", data.ptr);
}

// case more than buffe size
void		test_arg_s_write_case3(void)
{
	printf(KYEL "test_arg_s_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	data.ptr = (void *)"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries,";
	printf("result : ");
	fp_arg_s_write(&data, &tags, fp_arg_s_length(&data, &tags), &buf);
	printf("%s\n", buf.data);
	printf("expect : %s\n", data.ptr);
}

// case precsion < len
void		test_arg_s_write_case4(void)
{
	printf(KYEL "test_arg_s_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 3;
	data.ptr = (void *)"hello world";
	fp_arg_s_write(&data, &tags, fp_arg_s_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.3s\n", data.ptr);
}

// case precsion > len
void		test_arg_s_write_case5(void)
{
	printf(KYEL "test_arg_s_write_case5\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 20;
	data.ptr = (void *)"hello world";
	fp_arg_s_write(&data, &tags, fp_arg_s_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.20s\n", data.ptr);
}

// case precsion = 0
void		test_arg_s_write_case6(void)
{
	printf(KYEL "test_arg_s_write_case6\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	tags.mask |= FP_MASK_PRECISION;
	tags.precision = 0;
	data.ptr = (void *)"hello world";
	fp_arg_s_write(&data, &tags, fp_arg_s_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %.s\n", data.ptr);
}