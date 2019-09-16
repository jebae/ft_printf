#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

/*
** test utils
*/
void		test(int res, const char *msg);

/*
** parse tags test
*/
void		test_init_tags_case1(void);
void		test_parse_flag_case1(void);
void		test_parse_flag_case2(void);
void		test_parse_flag_case3(void);
void		test_parse_flag_case4(void);
void		test_parse_flag_case5(void);
void		test_parse_width_case1(void);
void		test_parse_width_case2(void);
void		test_parse_precision_case1(void);
void		test_parse_precision_case2(void);
void		test_parse_precision_case3(void);
void		test_parse_length_case1(void);
void		test_parse_length_case2(void);
void		test_parse_length_case3(void);
void		test_parse_length_case4(void);
void		test_parse_length_case5(void);
void		test_parse_length_case6(void);

/*
** arg_length test
*/
void		test_int_length_case1(void);
void		test_int_length_case2(void);
void		test_int_length_case3(void);
void		test_int_length_case4(void);
void		test_int_length_case5(void);
void		test_int_length_case6(void);
void		test_int_length_case7(void);
void		test_int_length_case8(void);

void		test_uint_length_case1(void);
void		test_uint_length_case2(void);
void		test_uint_length_case3(void);
void		test_uint_length_case4(void);
void		test_uint_length_case5(void);
void		test_uint_length_case6(void);
void		test_uint_length_case7(void);
void		test_uint_length_case8(void);

void		test_arg_d_length_case1(void);
void		test_arg_d_length_case2(void);
void		test_arg_d_length_case3(void);
void		test_arg_d_length_case4(void);
void		test_arg_hd_length_case1(void);
void		test_arg_hd_length_case2(void);
void		test_arg_hd_length_case3(void);
void		test_arg_hd_length_case4(void);
void		test_arg_hhd_length_case1(void);
void		test_arg_hhd_length_case2(void);
void		test_arg_hhd_length_case3(void);
void		test_arg_hhd_length_case4(void);
void		test_arg_ld_length_case1(void);
void		test_arg_ld_length_case2(void);
void		test_arg_ld_length_case3(void);
void		test_arg_ld_length_case4(void);
void		test_arg_lld_length_case1(void);
void		test_arg_lld_length_case2(void);
void		test_arg_lld_length_case3(void);
void		test_arg_lld_length_case4(void);

void		test_arg_u_length_case1(void);
void		test_arg_u_length_case2(void);
void		test_arg_u_length_case3(void);
void		test_arg_u_length_case4(void);
void		test_arg_hu_length_case1(void);
void		test_arg_hu_length_case2(void);
void		test_arg_hu_length_case3(void);
void		test_arg_hu_length_case4(void);
void		test_arg_hhu_length_case1(void);
void		test_arg_hhu_length_case2(void);
void		test_arg_hhu_length_case3(void);
void		test_arg_hhu_length_case4(void);
void		test_arg_lu_length_case1(void);
void		test_arg_lu_length_case2(void);
void		test_arg_lu_length_case3(void);
void		test_arg_lu_length_case4(void);
void		test_arg_llu_length_case1(void);
void		test_arg_llu_length_case2(void);
void		test_arg_llu_length_case3(void);
void		test_arg_llu_length_case4(void);

void		test_double_int_part_length_case1(void);
void		test_double_int_part_length_case2(void);
void		test_double_int_part_length_case3(void);
void		test_double_int_part_length_case4(void);
void		test_double_int_part_length_case5(void);
void		test_double_int_part_length_case6(void);

void		test_arg_f_length_case1(void);
void		test_arg_f_length_case2(void);
void		test_arg_f_length_case3(void);
void		test_arg_f_length_case4(void);
void		test_arg_f_length_case5(void);

#endif
