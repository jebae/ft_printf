#include "ft_printf.test.h"

void		test_write_sign_case1(void)
{
	printf(KYEL "test_write_sign_case1\n" KNRM);
	t_fp_buffer		buf;
	char			sign;

	fp_init_buffer(&buf);
	sign = '-';
	fp_write_sign(sign, &buf);
	test(
		buf.data[buf.i] == sign,
		"write_sign (-) : buf.data"
	);
}

// case no sign
void		test_write_sign_case2(void)
{
	printf(KYEL "test_write_sign_case2\n" KNRM);
	t_fp_buffer		buf;
	char			sign;

	fp_init_buffer(&buf);
	sign = -1;
	fp_write_sign(sign, &buf);
	test(
		buf.i == -1,
		"write_sign (-1) : buf.i"
	);
}
