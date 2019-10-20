#include "ft_printf.test.h"

// case simple
void		test_arg_c_write_case1(void)
{
	printf(KYEL "test_arg_c_write_case1\n" KNRM);
	t_fp_arg_data	data;
	t_fp_buffer		buf;
	t_fp_tags		tags;

	fp_init_buffer(&buf);
	fp_init_tags(&tags);
	data.i = 'h';
	fp_arg_c_write(&data, &tags, fp_arg_c_length(&data, &tags), &buf);
	printf("result : %s\n", buf.data);
	printf("expect : %c\n", (char)data.i);
}
