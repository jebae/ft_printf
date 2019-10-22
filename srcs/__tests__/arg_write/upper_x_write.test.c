#include "ft_printf.test.h"

void		test_arg_upper_x_write_case1(void)
{
	printf(KYEL "test_arg_upper_x_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0x12345678;
	fp_arg_upper_x_write(&data, &tags, fp_arg_x_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "12345678") == 0,
		"arg_upper_x_write : buf.data"
	);
}

// case overflow
void		test_arg_upper_x_write_case2(void)
{
	printf(KYEL "test_arg_upper_x_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0x12345678AB;
	fp_arg_upper_x_write(&data, &tags, fp_arg_x_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "345678AB") == 0,
		"arg_upper_x_write : buf.data"
	);
}

void		test_arg_h_upper_x_write_case1(void)
{
	printf(KYEL "test_arg_h_upper_x_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xFEDA;
	fp_arg_h_upper_x_write(&data, &tags, fp_arg_hx_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "FEDA") == 0,
		"arg_h_upper_x_write : buf.data"
	);
}

// case overflow
void		test_arg_h_upper_x_write_case2(void)
{
	printf(KYEL "test_arg_h_upper_x_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xFEDA2;
	fp_arg_h_upper_x_write(&data, &tags, fp_arg_hx_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "EDA2") == 0,
		"arg_h_upper_x_write : buf.data"
	);
}

void		test_arg_hh_upper_x_write_case1(void)
{
	printf(KYEL "test_arg_hh_upper_x_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xfe;
	fp_arg_hh_upper_x_write(&data, &tags, fp_arg_hhx_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "FE") == 0,
		"arg_hh_upper_x_write : buf.data"
	);
}

// case overflow
void		test_arg_hh_upper_x_write_case2(void)
{
	printf(KYEL "test_arg_hh_upper_x_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0xfed;
	fp_arg_hh_upper_x_write(&data, &tags, fp_arg_hhx_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "ED") == 0,
		"arg_hh_upper_x_write : buf.data"
	);
}

void		test_arg_l_upper_x_write_case1(void)
{
	printf(KYEL "test_arg_l_upper_x_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0x12345678abcdef01;
	fp_arg_l_upper_x_write(&data, &tags, fp_arg_lx_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "12345678ABCDEF01") == 0,
		"arg_l_upper_x_write : buf.data"
	);
}

void		test_arg_ll_upper_x_write_case1(void)
{
	printf(KYEL "test_arg_ll_upper_x_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_tags(&tags);
	fp_init_buffer(&buf);
	data.i = 0x12345678abcdef01;
	fp_arg_ll_upper_x_write(&data, &tags, fp_arg_llx_length(&data, &tags), &buf);

	test(
		ft_strcmp(buf.data, "12345678ABCDEF01") == 0,
		"arg_ll_upper_x_write : buf.data"
	);
}
