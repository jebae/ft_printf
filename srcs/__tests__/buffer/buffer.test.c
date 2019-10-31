#include "ft_printf.test.h"

void		test_init_buffer_case1(void)
{
	printf(KYEL "test_init_buffer_case1\n" KNRM);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	for (int i=0; i < FP_BUFFER_SIZE; i++)
		test(
			buf.data[i] == 0,
			"init_buffer : data in buffer"
		);

	test(
		buf.written == 0,
		"init_buffer : buf.written"
	);

	test(
		buf.i == -1,
		"init_buffer : i in buffer"
	);
}

void		test_write_buffer_case1(void)
{
	printf(KYEL "test_write_buffer_case1\n" KNRM);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);

	fp_write_buffer(&buf, 'a');
	test(
		buf.i == 0,
		"write_buffer (a) : buf.i"
	);

	test(
		buf.data[buf.i] == 'a',
		"write_buffer (a) : buf.data"
	);

	fp_write_buffer(&buf, 'b');
	test(
		buf.i == 1,
		"write_buffer (b) : buf.i"
	);

	test(
		buf.data[buf.i] == 'b',
		"write_buffer (a) : buf.data"
	);

	test(
		buf.written == 2,
		"init_buffer : buf.written"
	);
}

void		test_write_buffer_case2(void)
{
	printf(KYEL "test_write_buffer_case2\n" KNRM);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	buf.i = FP_BUFFER_SIZE - 1;
	fp_write_buffer(&buf, 'a');

	test(
		buf.i == 0,
		"write_buffer (full) : buf.i value"
	);

	test(
		buf.data[buf.i] == 'a',
		"write_buffer (full) : buf.data"
	);

	test(
		buf.written == 1,
		"init_buffer : buf.written"
	);
}

void		test_flush_buffer_case1(void)
{
	printf(KYEL "test_flush_buffer_case1\n" KNRM);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	for (int i=0; i < FP_BUFFER_SIZE; i++)
		fp_write_buffer(&buf, '\"' + (char)i);

	fp_flush_buffer(&buf);
	printf("\n");
	for (int i=0; i < FP_BUFFER_SIZE; i++)
		test(
			buf.data[i] == 0,
			"flush_buffer : buf.data"
		);

	test(
		buf.i == -1,
		"flush_buffer : buf.i"
	);
}

void		test_flush_buffer_case2(void)
{
	printf(KYEL "test_flush_buffer_case2\n" KNRM);
	t_fp_buffer		buf;

	fp_init_buffer(&buf);
	for (int i=0; i < FP_BUFFER_SIZE; i++)
		fp_write_buffer(&buf, '\"' + (char)i);

	for (int i=0; i < FP_BUFFER_SIZE / 2; i++)
		fp_write_buffer(&buf, '\"' + (char)i);

	fp_flush_buffer(&buf);
	printf("\n");
	for (int i=0; i < FP_BUFFER_SIZE; i++)
		test(
			buf.data[i] == 0,
			"flush_buffer : buf.data"
		);

	test(
		buf.i == -1,
		"flush_buffer : buf.i"
	);
}
