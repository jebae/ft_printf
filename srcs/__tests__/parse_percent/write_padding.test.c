#include "ft_printf.test.h"

void		test_write_padding_case1(void)
{
	printf(KYEL "test_write_padding_case1\n" KNRM);
	t_fp_tags		tags;
	t_fp_buffer		buf;
	size_t			length;

	fp_init_buffer(&buf);
	tags.width = 10;
	length = 5;
	fp_write_padding(&tags, length, ' ', &buf);

	test(
		buf.i == 4,
		"write_padding (width : 10, length : 5) : buf.i"
	);

	for (int i=0; i <= buf.i; i++)
		test(
			buf.data[i] == ' ',
			"write_padding (width : 10, length : 5) : buf.data[i]"
		);
}

void		test_write_padding_case2(void)
{
	printf(KYEL "test_write_padding_case2\n" KNRM);
	t_fp_tags		tags;
	t_fp_buffer		buf;
	size_t			length;

	fp_init_buffer(&buf);
	tags.width = 10;
	length = 5;
	fp_write_padding(&tags, length, '0', &buf);

	test(
		buf.i == 4,
		"write_padding (width : 10, length : 5) : buf.i"
	);

	for (int i=0; i <= buf.i; i++)
		test(
			buf.data[i] == '0',
			"write_padding (width : 10, length : 5) : buf.data[i]"
		);
}

// length > width
void		test_write_padding_case3(void)
{
	printf(KYEL "test_write_padding_case3\n" KNRM);
	t_fp_tags		tags;
	t_fp_buffer		buf;
	size_t			length;

	fp_init_buffer(&buf);
	tags.width = 5;
	length = 10;
	fp_write_padding(&tags, length, ' ', &buf);

	test(
		buf.i == -1,
		"write_padding (width : 5, length : 10) : buf.i"
	);
}

// length = width
void		test_write_padding_case4(void)
{
	printf(KYEL "test_write_padding_case4\n" KNRM);
	t_fp_tags		tags;
	t_fp_buffer		buf;
	size_t			length;

	fp_init_buffer(&buf);
	tags.width = 5;
	length = 5;
	fp_write_padding(&tags, length, ' ', &buf);

	test(
		buf.i == -1,
		"write_padding (width : 5, length : 5) : buf.i"
	);
}
