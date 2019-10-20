#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "bigint.h"
# include "fixedpoint.h"
# include <stdarg.h>
# include <stdio.h> // remove later

/*
** bit_flags macros
*/
# define FP_MASK_FLAG_MINUS			(1 << 0)
# define FP_MASK_FLAG_PLUS			(1 << 1)
# define FP_MASK_FLAG_SPACE			(1 << 2)
# define FP_MASK_FLAG_ZERO			(1 << 3)
# define FP_MASK_LENGTH_HH			(1 << 4)
# define FP_MASK_LENGTH_H			(1 << 5)
# define FP_MASK_LENGTH_L			(1 << 6)
# define FP_MASK_LENGTH_LL			(1 << 7)
# define FP_MASK_LENGTH_FL			(1 << 8)
# define FP_MASK_PRECISION			(1 << 9)
# define FP_MASK_IGNORE_ZERO_PAD	(1 << 10)

/*
** buffer macros
*/
# define FP_BUFFER_SIZE				64
# define FP_OUTPUT					1

/*
** parse macros
*/
# define FP_NO_SIGN					-1

/*
** constant macros
*/
# define FP_SUCCESS					0
# define FP_FAIL					1

/*
** math macros
*/
# define ABS_SMALLER_THEN(X, Y) (((X) > -(Y)) && ((X) < (Y)))

typedef struct	s_fp_buffer
{
	char	data[FP_BUFFER_SIZE];
	int		i;
	int		written;
}				t_fp_buffer;

typedef struct	s_fp_tags
{
	int		mask;
	size_t	width;
	size_t	precision;
}				t_fp_tags;

typedef union	u_fp_arg_data
{
	long long		i;
	double			f;
	long double		lf;
	void			*ptr;
}				t_fp_arg_data;

typedef struct	s_fp_arg
{
	t_fp_arg_data	data;
	size_t			(*length)(t_fp_arg_data *data, t_fp_tags *tags);
	char			(*sign)(t_fp_arg_data *data, t_fp_tags *tags);
	void			(*write)(
		t_fp_arg_data *data,
		t_fp_tags *tags,
		size_t length,
		t_fp_buffer *buf
	);
}				t_fp_arg;

typedef struct	s_fp_double_fields
{
	short				exponent;
	unsigned long long	mantissa;
}				t_fp_double_fields;

/*
** parse_tags
*/
void			fp_init_tags(t_fp_tags *tags);
size_t			fp_parse_flag(const char *format, t_fp_tags *tags);
size_t			fp_parse_width(const char *format, t_fp_tags *tags);
size_t			fp_parse_precision(const char *format, t_fp_tags *tags);
size_t			fp_parse_length(const char *format, t_fp_tags *tags);

/*
** arg_length
*/
size_t			fp_int_length(long long num, int base);
size_t			fp_uint_length(unsigned long long num, int base);
size_t			fp_double_int_part_length(double num);
size_t			fp_ldouble_int_part_length(long double num);

size_t			fp_arg_d_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_hd_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_hhd_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_ld_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_lld_length(t_fp_arg_data *data, t_fp_tags *tags);

size_t			fp_arg_u_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_hu_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_hhu_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_lu_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_llu_length(t_fp_arg_data *data, t_fp_tags *tags);

size_t			fp_arg_f_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_lf_length(t_fp_arg_data *data, t_fp_tags *tags);

size_t			fp_arg_x_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_hx_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_hhx_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_lx_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_llx_length(t_fp_arg_data *data, t_fp_tags *tags);

size_t			fp_arg_o_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_ho_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_hho_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_lo_length(t_fp_arg_data *data, t_fp_tags *tags);
size_t			fp_arg_llo_length(t_fp_arg_data *data, t_fp_tags *tags);

size_t			fp_arg_s_length(t_fp_arg_data *data, t_fp_tags *tags);

size_t			fp_arg_c_length(t_fp_arg_data *data, t_fp_tags *tags);

/*
** arg_sign
*/
char			fp_num_sign(int positive, t_fp_tags *tags);

char			fp_arg_d_sign(t_fp_arg_data *data, t_fp_tags *tags);
char			fp_arg_hd_sign(t_fp_arg_data *data, t_fp_tags *tags);
char			fp_arg_hhd_sign(t_fp_arg_data *data, t_fp_tags *tags);
char			fp_arg_ld_sign(t_fp_arg_data *data, t_fp_tags *tags);
char			fp_arg_lld_sign(t_fp_arg_data *data, t_fp_tags *tags);

char			fp_arg_f_sign(t_fp_arg_data *data, t_fp_tags *tags);
char			fp_arg_lf_sign(t_fp_arg_data *data, t_fp_tags *tags);

char			fp_arg_no_sign(t_fp_arg_data *data, t_fp_tags *tags);

/*
** buffer
*/
void			fp_init_buffer(t_fp_buffer *buf);
void			fp_write_buffer(t_fp_buffer *buf, char value);
void			fp_flush_buffer(t_fp_buffer *buf);

/*
** arg_write
*/
void			fp_int_write(
	long long num,
	size_t length,
	t_fp_buffer *buf
);

void			fp_uint_write(
	unsigned long long num,
	size_t length,
	int base,
	t_fp_buffer *buf
);

void			fp_uint_upper_write(
	unsigned long long num,
	size_t length,
	int base,
	t_fp_buffer *buf
);

void			fp_arg_d_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hd_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hhd_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_ld_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_lld_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_u_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hhu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_lu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_llu_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

int				fp_double_integer_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
);

int				fp_double_fraction_part(
	short exponent,
	unsigned long long mantissa,
	size_t precision,
	t_fixedpoint *fraction_part
);

int				fp_double_write_integer_part(
	t_fixedpoint *int_part,
	int carry,
	t_fp_buffer *buf
);

int				fp_double_write_fraction_part(
	t_fixedpoint *fraction_part,
	size_t precision,
	t_fp_buffer *buf
);

void			fp_double_write(
	double num,
	size_t precision,
	t_fp_buffer *buf
);

int				fp_ldouble_integer_part(
	short exponent,
	unsigned long long mantissa,
	t_fixedpoint *int_part
);

int				fp_ldouble_fraction_part(
	short exponent,
	unsigned long long mantissa,
	size_t precision,
	t_fixedpoint *fraction_part
);

void			fp_ldouble_write(
	long double num,
	size_t precision,
	t_fp_buffer *buf
);

void			fp_arg_f_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_lf_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hhx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_lx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_llx_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_h_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hh_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_l_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_ll_upper_x_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_o_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_ho_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_hho_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_lo_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void			fp_arg_llo_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void		fp_arg_s_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

void		fp_arg_c_write(
	t_fp_arg_data *data,
	t_fp_tags *tags,
	size_t length,
	t_fp_buffer *buf
);

/*
** parse_percent
*/
void			fp_write_sign(char sign, t_fp_buffer *buf);

void			fp_write_padding(
	t_fp_tags *tags,
	size_t content_length,
	char pad,
	t_fp_buffer *buf
);

void			fp_write_percent_format(
	t_fp_arg *arg,
	t_fp_tags *tags,
	t_fp_buffer *buf
);

void			fp_parse_d(va_list ap, t_fp_tags *tags, t_fp_arg *arg);
void			fp_parse_u(va_list ap, t_fp_tags *tags, t_fp_arg *arg);
void			fp_parse_f(va_list ap, t_fp_tags *tags, t_fp_arg *arg);
void			fp_parse_x(va_list ap, t_fp_tags *tags, t_fp_arg *arg);
void			fp_parse_upper_x(va_list ap, t_fp_tags *tags, t_fp_arg *arg);
void			fp_parse_o(va_list ap, t_fp_tags *tags, t_fp_arg *arg);
void			fp_parse_s(va_list ap, t_fp_tags *tags, t_fp_arg *arg);
void			fp_parse_c(va_list ap, t_fp_tags *tags, t_fp_arg *arg);

size_t			fp_parse_specifier(
	const char *format,
	va_list valist,
	t_fp_tags *tags,
	t_fp_arg *arg
);

size_t			fp_parse_percent(
	const char *format,
	va_list ap,
	t_fp_buffer *buf
);

#endif
