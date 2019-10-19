#include "ft_printf.test.h"

void		test_arg_o_write_case1(void)
{
	printf(KYEL "test_arg_o_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 01234567;
	fp_arg_o_write(&data, NULL, fp_arg_o_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "1234567") == 0,
		"arg_o_write : buf.data"
	);
}

// case overflow
void		test_arg_o_write_case2(void)
{
	printf(KYEL "test_arg_o_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 040000000000;
	fp_arg_o_write(&data, NULL, fp_arg_o_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "0") == 0,
		"arg_o_write : buf.data"
	);
}

void		test_arg_ho_write_case1(void)
{
	printf(KYEL "test_arg_ho_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0157777;
	fp_arg_ho_write(&data, NULL, fp_arg_ho_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "157777") == 0,
		"arg_ho_write : buf.data"
	);
}

// case overflow
void		test_arg_ho_write_case2(void)
{
	printf(KYEL "test_arg_ho_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 02023400;
	fp_arg_ho_write(&data, NULL, fp_arg_ho_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "23400") == 0,
		"arg_ho_write : buf.data"
	);
}

void		test_arg_hho_write_case1(void)
{
	printf(KYEL "test_arg_hho_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0234;
	fp_arg_hho_write(&data, NULL, fp_arg_hho_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "234") == 0,
		"arg_hho_write : buf.data"
	);
}

// case overflow
void		test_arg_hho_write_case2(void)
{
	printf(KYEL "test_arg_hho_write_case2\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 0401;
	fp_arg_hho_write(&data, NULL, fp_arg_hho_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "1") == 0,
		"arg_hho_write : buf.data"
	);
}

void		test_arg_lo_write_case1(void)
{
	printf(KYEL "test_arg_lo_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 01777777777777777777777;
	fp_arg_lo_write(&data, NULL, fp_arg_lo_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "1777777777777777777777") == 0,
		"arg_lo_write : buf.data"
	);
}

void		test_arg_llo_write_case1(void)
{
	printf(KYEL "test_arg_llo_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	data.i = 01777777777777777777777;
	fp_arg_llo_write(&data, NULL, fp_arg_llo_length(&data, NULL), &buf);

	test(
		ft_strcmp(buf.data, "1777777777777777777777") == 0,
		"arg_llo_write : buf.data"
	);
}
