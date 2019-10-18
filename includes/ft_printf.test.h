#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include <stdio.h>
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
void		test_long_double_int_part_length_case1(void);
void		test_long_double_int_part_length_case2(void);
void		test_long_double_int_part_length_case3(void);
void		test_long_double_int_part_length_case4(void);
void		test_long_double_int_part_length_case5(void);
void		test_long_double_int_part_length_case6(void);

void		test_arg_f_length_case1(void);
void		test_arg_f_length_case2(void);
void		test_arg_f_length_case3(void);
void		test_arg_f_length_case4(void);
void		test_arg_f_length_case5(void);

void		test_arg_lf_length_case1(void);
void		test_arg_lf_length_case2(void);
void		test_arg_lf_length_case3(void);
void		test_arg_lf_length_case4(void);
void		test_arg_lf_length_case5(void);

/*
** arg_sign test
*/
void		test_num_sign_case1(void);
void		test_num_sign_case2(void);
void		test_num_sign_case3(void);
void		test_num_sign_case4(void);
void		test_num_sign_case5(void);

void		test_arg_d_sign_case1(void);
void		test_arg_d_sign_case2(void);
void		test_arg_d_sign_case3(void);
void		test_arg_d_sign_case4(void);
void		test_arg_d_sign_case5(void);
void		test_arg_d_sign_case6(void);
void		test_arg_d_sign_case7(void);
void		test_arg_d_sign_case8(void);
void		test_arg_d_sign_case9(void);
void		test_arg_d_sign_case10(void);
void		test_arg_hd_sign_case1(void);
void		test_arg_hhd_sign_case1(void);
void		test_arg_ld_sign_case1(void);
void		test_arg_lld_sign_case1(void);

void		test_arg_no_sign_case1(void);
void		test_arg_no_sign_case2(void);
void		test_arg_no_sign_case3(void);

void		test_arg_f_sign_case1(void);
void		test_arg_f_sign_case2(void);
void		test_arg_f_sign_case3(void);
void		test_arg_f_sign_case4(void);
void		test_arg_f_sign_case5(void);
void		test_arg_f_sign_case6(void);
void		test_arg_f_sign_case7(void);
void		test_arg_f_sign_case8(void);

void		test_arg_lf_sign_case1(void);
void		test_arg_lf_sign_case2(void);
void		test_arg_lf_sign_case3(void);
void		test_arg_lf_sign_case4(void);
void		test_arg_lf_sign_case5(void);
void		test_arg_lf_sign_case6(void);
void		test_arg_lf_sign_case7(void);
void		test_arg_lf_sign_case8(void);

/*
** buffer test
*/
void		test_init_buffer_case1(void);
void		test_write_buffer_case1(void);
void		test_write_buffer_case2(void);
void		test_flush_buffer_case1(void);
void		test_flush_buffer_case2(void);

/*
** arg_write test
*/
void		test_int_write_case1(void);
void		test_int_write_case2(void);
void		test_int_write_case3(void);
void		test_int_write_case4(void);
void		test_int_write_case5(void);
void		test_int_write_case6(void);

void		test_uint_write_case1(void);
void		test_uint_write_case2(void);
void		test_uint_write_case3(void);
void		test_uint_write_case4(void);

void		test_arg_d_write_case1(void);
void		test_arg_d_write_case2(void);
void		test_arg_d_write_case3(void);
void		test_arg_d_write_case4(void);

void		test_arg_hd_write_case1(void);

void		test_arg_hhd_write_case1(void);

void		test_arg_ld_write_case1(void);

void		test_arg_lld_write_case1(void);

void		test_arg_u_write_case1(void);
void		test_arg_u_write_case2(void);
void		test_arg_u_write_case3(void);
void		test_arg_u_write_case4(void);

void		test_arg_hu_write_case1(void);
void		test_arg_hu_write_case2(void);
void		test_arg_hu_write_case3(void);
void		test_arg_hu_write_case4(void);

void		test_arg_hhu_write_case1(void);
void		test_arg_hhu_write_case2(void);
void		test_arg_hhu_write_case3(void);
void		test_arg_hhu_write_case4(void);

void		test_arg_lu_write_case1(void);
void		test_arg_lu_write_case2(void);
void		test_arg_lu_write_case3(void);
void		test_arg_lu_write_case4(void);

void		test_arg_llu_write_case1(void);
void		test_arg_llu_write_case2(void);
void		test_arg_llu_write_case3(void);
void		test_arg_llu_write_case4(void);

void		test_arg_f_write_case1(void);
void		test_arg_f_write_case2(void);
void		test_arg_f_write_case3(void);
void		test_arg_f_write_case4(void);
void		test_arg_f_write_case5(void);

/*
** parse_percent test
*/
void		test_write_sign_case1(void);
void		test_write_sign_case2(void);

void		test_write_padding_case1(void);
void		test_write_padding_case2(void);
void		test_write_padding_case3(void);
void		test_write_padding_case4(void);

void		test_write_percent_format_case1(void);
void		test_write_percent_format_case2(void);
void		test_write_percent_format_case3(void);
void		test_write_percent_format_case4(void);
void		test_write_percent_format_case5(void);
void		test_write_percent_format_case6(void);
void		test_write_percent_format_case7(void);
void		test_write_percent_format_case8(void);
void		test_write_percent_format_case9(void);
void		test_write_percent_format_case10(void);
void		test_write_percent_format_case11(void);
void		test_write_percent_format_case12(void);
void		test_write_percent_format_case13(void);
void		test_write_percent_format_case14(void);
void		test_write_percent_format_case15(void);
void		test_write_percent_format_case16(void);
void		test_write_percent_format_case17(void);
void		test_write_percent_format_case18(void);
void		test_write_percent_format_case19(void);
void		test_write_percent_format_case20(void);
void		test_write_percent_format_case21(void);
void		test_write_percent_format_case22(void);
void		test_write_percent_format_case23(void);
void		test_write_percent_format_case24(void);
void		test_write_percent_format_case25(void);
void		test_write_percent_format_case26(void);
void		test_write_percent_format_case27(void);
void		test_write_percent_format_case28(void);
void		test_write_percent_format_case29(void);
void		test_write_percent_format_case30(void);
void		test_write_percent_format_case31(void);
void		test_write_percent_format_case32(void);

void		test_parse_d_case1(void);
void		test_parse_d_case2(void);
void		test_parse_d_case3(void);
void		test_parse_d_case4(void);
void		test_parse_d_case5(void);

void		test_parse_u_case1(void);
void		test_parse_u_case2(void);
void		test_parse_u_case3(void);
void		test_parse_u_case4(void);
void		test_parse_u_case5(void);

void		test_parse_specifier_case1(void);
void		test_parse_specifier_case2(void);
void		test_parse_specifier_case3(void);

void		test_parse_percent_case1(void);
void		test_parse_percent_case2(void);
void		test_parse_percent_case3(void);
void		test_parse_percent_case4(void);
void		test_parse_percent_case5(void);
void		test_parse_percent_case6(void);
void		test_parse_percent_case7(void);

/*
** double write test
*/
void		test_double_write_case1(void);
void		test_double_write_case2(void);
void		test_double_write_case3(void);
void		test_double_write_case4(void);
void		test_double_write_case5(void);
void		test_double_write_case6(void);

void		test_double_integer_part_case1(void);
void		test_double_integer_part_case2(void);
void		test_double_integer_part_case3(void);
void		test_double_integer_part_case4(void);
void		test_double_integer_part_case5(void);
void		test_double_integer_part_case6(void);

void		test_double_fraction_part_case1(void);
void		test_double_fraction_part_case2(void);
void		test_double_fraction_part_case3(void);
void		test_double_fraction_part_case4(void);
void		test_double_fraction_part_case5(void);
void		test_double_fraction_part_case6(void);
void		test_double_fraction_part_case7(void);
void		test_double_fraction_part_case8(void);

void		test_double_write_integer_part_case1(void);
void		test_double_write_integer_part_case2(void);
void		test_double_write_integer_part_case3(void);
void		test_double_write_integer_part_case4(void);
void		test_double_write_integer_part_case5(void);
void		test_double_write_integer_part_case6(void);
void		test_double_write_integer_part_case7(void);

void		test_double_write_fraction_part_case1(void);
void		test_double_write_fraction_part_case2(void);
void		test_double_write_fraction_part_case3(void);
void		test_double_write_fraction_part_case4(void);
void		test_double_write_fraction_part_case5(void);
void		test_double_write_fraction_part_case6(void);
void		test_double_write_fraction_part_case7(void);
void		test_double_write_fraction_part_case8(void);
void		test_double_write_fraction_part_case9(void);
void		test_double_write_fraction_part_case10(void);
void		test_double_write_fraction_part_case11(void);
void		test_double_write_fraction_part_case12(void);
void		test_double_write_fraction_part_case13(void);
void		test_double_write_fraction_part_case14(void);
void		test_double_write_fraction_part_case15(void);
void		test_double_write_fraction_part_case16(void);

void		test_double_write_case1(void);
void		test_double_write_case2(void);
void		test_double_write_case3(void);
void		test_double_write_case4(void);
void		test_double_write_case5(void);
void		test_double_write_case6(void);
void		test_double_write_case7(void);
void		test_double_write_case8(void);
void		test_double_write_case9(void);
void		test_double_write_case10(void);
void		test_double_write_case11(void);
void		test_double_write_case12(void);

#endif
