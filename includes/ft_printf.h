#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

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

/*
** buffer macros
*/
# define FP_BUFFER_SIZE				64

/*
** math macros
*/
# define ABS_SMALLER_THEN(X, Y) (((X) > -(Y)) && ((X) < (Y)))

typedef struct	s_fp_buffer
{
	char	mem[FP_BUFFER_SIZE];
	size_t	i;
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
	void			(*write)(t_fp_arg_data *data, t_fp_buffer *buf);
}				t_fp_arg;

/*
** tags
*/
void			fp_init_tags(t_fp_tags *tags);
size_t			fp_parse_flag(const char *format, t_fp_tags *tags);
size_t			fp_parse_width(const char *format, t_fp_tags *tags);
size_t			fp_parse_precision(const char *format, t_fp_tags *tags);
size_t			fp_parse_length(const char *format, t_fp_tags *tags);

/*
** arg_length
*/
size_t			fp_int_length(long long num);
size_t			fp_uint_length(unsigned long long num);
size_t			fp_double_int_part_length(double num);
size_t			fp_long_double_int_part_length(long double num);

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

#endif
