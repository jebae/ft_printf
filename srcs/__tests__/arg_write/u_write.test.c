#include "ft_printf.test.h"

void		test_arg_u_write_case1(void)
{
	printf(KYEL "test_arg_u_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 123;
	fp_arg_u_write(&data, &tags, fp_arg_u_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %u\n", (unsigned int)data.i);
}

// case negative
void		test_arg_u_write_case2(void)
{
	printf(KYEL "test_arg_u_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -123;
	fp_arg_u_write(&data, &tags, fp_arg_u_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %u\n", (unsigned int)data.i);
}

// case max
void		test_arg_u_write_case3(void)
{
	printf(KYEL "test_arg_u_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 4294967295;
	fp_arg_u_write(&data, &tags, fp_arg_u_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %u\n", (unsigned int)data.i);
}

// case max + 1
void		test_arg_u_write_case4(void)
{
	printf(KYEL "test_arg_u_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 4294967296;
	fp_arg_u_write(&data, &tags, fp_arg_u_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %u\n", (unsigned int)data.i);
}

void		test_arg_hu_write_case1(void)
{
	printf(KYEL "test_arg_hu_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 65535;
	fp_arg_hu_write(&data, &tags, fp_arg_hu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hu\n", (unsigned short)data.i);
}

void		test_arg_hu_write_case2(void)
{
	printf(KYEL "test_arg_hu_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -65536;
	fp_arg_hu_write(&data, &tags, fp_arg_hu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hu\n", (unsigned short)data.i);
}

void		test_arg_hu_write_case3(void)
{
	printf(KYEL "test_arg_hu_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 65536;
	fp_arg_hu_write(&data, &tags, fp_arg_hu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hu\n", (unsigned short)data.i);
}

void		test_arg_hu_write_case4(void)
{
	printf(KYEL "test_arg_hu_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -65537;
	fp_arg_hu_write(&data, &tags, fp_arg_hu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hu\n", (unsigned short)data.i);
}

void		test_arg_hhu_write_case1(void)
{
	printf(KYEL "test_arg_hhu_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 255;
	fp_arg_hhu_write(&data, &tags, fp_arg_hhu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hhu\n", (unsigned char)data.i);
}

void		test_arg_hhu_write_case2(void)
{
	printf(KYEL "test_arg_hhu_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -256;
	fp_arg_hhu_write(&data, &tags, fp_arg_hhu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hhu\n", (unsigned char)data.i);
}

void		test_arg_hhu_write_case3(void)
{
	printf(KYEL "test_arg_hhu_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 256;
	fp_arg_hhu_write(&data, &tags, fp_arg_hhu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hhu\n", (unsigned char)data.i);
}

void		test_arg_hhu_write_case4(void)
{
	printf(KYEL "test_arg_hhu_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -257;
	fp_arg_hhu_write(&data, &tags, fp_arg_hhu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %hhu\n", (unsigned char)data.i);
}

void		test_arg_lu_write_case1(void)
{
	printf(KYEL "test_arg_lu_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xffffffffffffffff;
	fp_arg_lu_write(&data, &tags, fp_arg_lu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %lu\n", (unsigned long)data.i);
}

void		test_arg_lu_write_case2(void)
{
	printf(KYEL "test_arg_lu_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -0xffffffffffffffff;
	fp_arg_lu_write(&data, &tags, fp_arg_lu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %lu\n", (unsigned long)data.i);
}

void		test_arg_lu_write_case3(void)
{
	printf(KYEL "test_arg_lu_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xffffffffffffffff + 1;
	fp_arg_lu_write(&data, &tags, fp_arg_lu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %lu\n", (unsigned long)data.i);
}

void		test_arg_lu_write_case4(void)
{
	printf(KYEL "test_arg_lu_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -0xffffffffffffffff - 1;
	fp_arg_lu_write(&data, &tags, fp_arg_lu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %lu\n", (unsigned long)data.i);
}

void		test_arg_llu_write_case1(void)
{
	printf(KYEL "test_arg_llu_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xffffffffffffffff;
	fp_arg_llu_write(&data, &tags, fp_arg_llu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llu\n", (unsigned long long)data.i);
}

void		test_arg_llu_write_case2(void)
{
	printf(KYEL "test_arg_llu_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -0xffffffffffffffff;
	fp_arg_llu_write(&data, &tags, fp_arg_llu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llu\n", (unsigned long long)data.i);
}

void		test_arg_llu_write_case3(void)
{
	printf(KYEL "test_arg_llu_write_case3\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xffffffffffffffff + 1;
	fp_arg_llu_write(&data, &tags, fp_arg_llu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llu\n", (unsigned long long)data.i);
}

void		test_arg_llu_write_case4(void)
{
	printf(KYEL "test_arg_llu_write_case4\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = -0xffffffffffffffff - 1;
	fp_arg_llu_write(&data, &tags, fp_arg_llu_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %llu\n", (unsigned long long)data.i);
}
