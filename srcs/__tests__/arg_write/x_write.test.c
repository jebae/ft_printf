#include "ft_printf.test.h"

void		test_arg_x_write_case1(void)
{
	printf(KYEL "test_arg_x_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0x12345678;
	fp_arg_x_write(&data, NULL, fp_arg_x_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "12345678") == 0,
		"arg_x_write : buf.data"
	);
}

// case overflow
void		test_arg_x_write_case2(void)
{
	printf(KYEL "test_arg_x_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0x12345678ab;
	fp_arg_x_write(&data, NULL, fp_arg_x_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "345678ab") == 0,
		"arg_x_write : buf.data"
	);
}

void		test_arg_hx_write_case1(void)
{
	printf(KYEL "test_arg_hx_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0xfeda;
	fp_arg_hx_write(&data, NULL, fp_arg_hx_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "feda") == 0,
		"arg_hx_write : buf.data"
	);
}

// case overflow
void		test_arg_hx_write_case2(void)
{
	printf(KYEL "test_arg_hx_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0xfeda2;
	fp_arg_hx_write(&data, NULL, fp_arg_hx_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "eda2") == 0,
		"arg_hx_write : buf.data"
	);
}

void		test_arg_hhx_write_case1(void)
{
	printf(KYEL "test_arg_hhx_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0xfe;
	fp_arg_hhx_write(&data, NULL, fp_arg_hhx_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "fe") == 0,
		"arg_hhx_write : buf.data"
	);
}

// case overflow
void		test_arg_hhx_write_case2(void)
{
	printf(KYEL "test_arg_hhx_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0xfed;
	fp_arg_hhx_write(&data, NULL, fp_arg_hhx_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "ed") == 0,
		"arg_hhx_write : buf.data"
	);
}

void		test_arg_lx_write_case1(void)
{
	printf(KYEL "test_arg_lx_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0x12345678abcdef01;
	fp_arg_lx_write(&data, NULL, fp_arg_lx_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "12345678abcdef01") == 0,
		"arg_lx_write : buf.data"
	);
}

void		test_arg_llx_write_case1(void)
{
	printf(KYEL "test_arg_llx_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0x12345678abcdef01;
	fp_arg_llx_write(&data, NULL, fp_arg_llx_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "12345678abcdef01") == 0,
		"arg_llx_write : buf.data"
	);
}
