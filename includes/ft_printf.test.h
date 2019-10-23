#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include <stdio.h>
# include <math.h>
# include <limits.h>
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
void		test_parse_flag_case6(void);
void		test_parse_flag_case7(void);
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
void		test_arg_d_length_case5(void);
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
void		test_arg_u_length_case5(void);
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
void		test_ldouble_int_part_length_case1(void);
void		test_ldouble_int_part_length_case2(void);
void		test_ldouble_int_part_length_case3(void);
void		test_ldouble_int_part_length_case4(void);
void		test_ldouble_int_part_length_case5(void);
void		test_ldouble_int_part_length_case6(void);

void		test_arg_f_length_case1(void);
void		test_arg_f_length_case2(void);
void		test_arg_f_length_case3(void);
void		test_arg_f_length_case4(void);
void		test_arg_f_length_case5(void);
void		test_arg_f_length_case6(void);
void		test_arg_f_length_case7(void);
void		test_arg_f_length_case8(void);

void		test_arg_lf_length_case1(void);
void		test_arg_lf_length_case2(void);
void		test_arg_lf_length_case3(void);
void		test_arg_lf_length_case4(void);
void		test_arg_lf_length_case5(void);
void		test_arg_lf_length_case6(void);
void		test_arg_lf_length_case7(void);
void		test_arg_lf_length_case8(void);

void		test_arg_x_length_case1(void);
void		test_arg_x_length_case2(void);
void		test_arg_x_length_case3(void);
void		test_arg_x_length_case4(void);
void		test_arg_x_length_case5(void);

void		test_arg_hx_length_case1(void);
void		test_arg_hx_length_case2(void);
void		test_arg_hx_length_case3(void);

void		test_arg_hhx_length_case1(void);
void		test_arg_hhx_length_case2(void);

void		test_arg_lx_length_case1(void);

void		test_arg_llx_length_case1(void);

void		test_arg_o_length_case1(void);
void		test_arg_o_length_case2(void);
void		test_arg_o_length_case3(void);
void		test_arg_o_length_case4(void);
void		test_arg_o_length_case5(void);

void		test_arg_ho_length_case1(void);
void		test_arg_ho_length_case2(void);

void		test_arg_hho_length_case1(void);
void		test_arg_hho_length_case2(void);

void		test_arg_lo_length_case1(void);

void		test_arg_llo_length_case1(void);

void		test_arg_s_length_case1(void);
void		test_arg_s_length_case2(void);
void		test_arg_s_length_case3(void);
void		test_arg_s_length_case4(void);
void		test_arg_s_length_case5(void);
void		test_arg_s_length_case6(void);
void		test_arg_s_length_case7(void);

void		test_arg_c_length_case1(void);

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
void		test_arg_f_sign_case9(void);
void		test_arg_f_sign_case10(void);
void		test_arg_f_sign_case11(void);
void		test_arg_f_sign_case12(void);

void		test_arg_lf_sign_case1(void);
void		test_arg_lf_sign_case2(void);
void		test_arg_lf_sign_case3(void);
void		test_arg_lf_sign_case4(void);
void		test_arg_lf_sign_case5(void);
void		test_arg_lf_sign_case6(void);
void		test_arg_lf_sign_case7(void);
void		test_arg_lf_sign_case8(void);
void		test_arg_lf_sign_case9(void);
void		test_arg_lf_sign_case10(void);
void		test_arg_lf_sign_case11(void);
void		test_arg_lf_sign_case12(void);

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
void		test_int_write_case7(void);

void		test_uint_write_case1(void);
void		test_uint_write_case2(void);
void		test_uint_write_case3(void);
void		test_uint_write_case4(void);
void		test_uint_write_case5(void);
void		test_uint_write_case6(void);
void		test_uint_write_case7(void);

void		test_uint_upper_write_case1(void);
void		test_uint_upper_write_case2(void);
void		test_uint_upper_write_case3(void);

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
void		test_arg_f_write_case6(void);
void		test_arg_f_write_case7(void);
void		test_arg_f_write_case8(void);
void		test_arg_f_write_case9(void);
void		test_arg_f_write_case10(void);
void		test_arg_f_write_case11(void);

void		test_arg_lf_write_case1(void);
void		test_arg_lf_write_case2(void);
void		test_arg_lf_write_case3(void);
void		test_arg_lf_write_case4(void);
void		test_arg_lf_write_case5(void);
void		test_arg_lf_write_case6(void);
void		test_arg_lf_write_case7(void);
void		test_arg_lf_write_case8(void);
void		test_arg_lf_write_case9(void);
void		test_arg_lf_write_case10(void);
void		test_arg_lf_write_case11(void);

void		test_arg_x_write_case1(void);
void		test_arg_x_write_case2(void);

void		test_arg_hx_write_case1(void);
void		test_arg_hx_write_case2(void);

void		test_arg_hhx_write_case1(void);
void		test_arg_hhx_write_case2(void);

void		test_arg_lx_write_case1(void);
void		test_arg_llx_write_case1(void);

void		test_arg_upper_x_write_case1(void);
void		test_arg_upper_x_write_case2(void);

void		test_arg_h_upper_x_write_case1(void);
void		test_arg_h_upper_x_write_case2(void);

void		test_arg_hh_upper_x_write_case1(void);
void		test_arg_hh_upper_x_write_case2(void);

void		test_arg_l_upper_x_write_case1(void);
void		test_arg_ll_upper_x_write_case1(void);

void		test_arg_o_write_case1(void);
void		test_arg_o_write_case2(void);

void		test_arg_ho_write_case1(void);
void		test_arg_ho_write_case2(void);

void		test_arg_hho_write_case1(void);
void		test_arg_hho_write_case2(void);

void		test_arg_lo_write_case1(void);
void		test_arg_llo_write_case1(void);

void		test_arg_s_write_case1(void);
void		test_arg_s_write_case2(void);
void		test_arg_s_write_case3(void);
void		test_arg_s_write_case4(void);
void		test_arg_s_write_case5(void);
void		test_arg_s_write_case6(void);
void		test_arg_s_write_case7(void);
void		test_arg_s_write_case8(void);

void		test_arg_c_write_case1(void);

/*
** parse_percent test
*/
void		test_parse_d_case1(void);
void		test_parse_d_case2(void);
void		test_parse_d_case3(void);
void		test_parse_d_case4(void);
void		test_parse_d_case5(void);
void		test_parse_d_case6(void);

void		test_parse_u_case1(void);
void		test_parse_u_case2(void);
void		test_parse_u_case3(void);
void		test_parse_u_case4(void);
void		test_parse_u_case5(void);
void		test_parse_u_case6(void);

void		test_parse_x_case1(void);
void		test_parse_x_case2(void);
void		test_parse_x_case3(void);
void		test_parse_x_case4(void);
void		test_parse_x_case5(void);
void		test_parse_x_case6(void);

void		test_parse_upper_x_case1(void);
void		test_parse_upper_x_case2(void);
void		test_parse_upper_x_case3(void);
void		test_parse_upper_x_case4(void);
void		test_parse_upper_x_case5(void);
void		test_parse_upper_x_case6(void);

void		test_parse_o_case1(void);
void		test_parse_o_case2(void);
void		test_parse_o_case3(void);
void		test_parse_o_case4(void);
void		test_parse_o_case5(void);
void		test_parse_o_case6(void);

void		test_parse_f_case1(void);
void		test_parse_f_case2(void);
void		test_parse_f_case3(void);
void		test_parse_f_case4(void);
void		test_parse_f_case5(void);
void		test_parse_f_case6(void);
void		test_parse_f_case7(void);
void		test_parse_f_case8(void);

void		test_parse_s_case1(void);

void		test_parse_c_case1(void);

void		test_parse_p_case1(void);
void		test_parse_p_case2(void);

void		test_parse_percent_case1(void);
void		test_parse_percent_case2(void);
void		test_parse_percent_case3(void);
void		test_parse_percent_case4(void);
void		test_parse_percent_case5(void);
void		test_parse_percent_case6(void);
void		test_parse_percent_case7(void);
void		test_parse_percent_case8(void);
void		test_parse_percent_case9(void);
void		test_parse_percent_case10(void);
void		test_parse_percent_case11(void);
void		test_parse_percent_case12(void);
void		test_parse_percent_case13(void);
void		test_parse_percent_case14(void);
void		test_parse_percent_case15(void);
void		test_parse_percent_case16(void);
void		test_parse_percent_case17(void);
void		test_parse_percent_case18(void);
void		test_parse_percent_case19(void);
void		test_parse_percent_case20(void);
void		test_parse_percent_case21(void);
void		test_parse_percent_case22(void);
void		test_parse_percent_case23(void);
void		test_parse_percent_case24(void);
void		test_parse_percent_case25(void);
void		test_parse_percent_case26(void);
void		test_parse_percent_case27(void);
void		test_parse_percent_case28(void);
void		test_parse_percent_case29(void);
void		test_parse_percent_case30(void);
void		test_parse_percent_case31(void);
void		test_parse_percent_case32(void);
void		test_parse_percent_case33(void);
void		test_parse_percent_case34(void);
void		test_parse_percent_case35(void);
void		test_parse_percent_case36(void);
void		test_parse_percent_case37(void);
void		test_parse_percent_case38(void);
void		test_parse_percent_case39(void);
void		test_parse_percent_case40(void);
void		test_parse_percent_case41(void);
void		test_parse_percent_case42(void);
void		test_parse_percent_case43(void);
void		test_parse_percent_case44(void);
void		test_parse_percent_case45(void);
void		test_parse_percent_case46(void);
void		test_parse_percent_case47(void);
void		test_parse_percent_case48(void);
void		test_parse_percent_case49(void);
void		test_parse_percent_case50(void);
void		test_parse_percent_case51(void);
void		test_parse_percent_case52(void);
void		test_parse_percent_case53(void);
void		test_parse_percent_case54(void);
void		test_parse_percent_case55(void);
void		test_parse_percent_case56(void);
void		test_parse_percent_case57(void);
void		test_parse_percent_case58(void);
void		test_parse_percent_case59(void);
void		test_parse_percent_case60(void);
void		test_parse_percent_case61(void);
void		test_parse_percent_case62(void);
void		test_parse_percent_case63(void);
void		test_parse_percent_case64(void);
void		test_parse_percent_case65(void);
void		test_parse_percent_case66(void);
void		test_parse_percent_case67(void);
void		test_parse_percent_case68(void);
void		test_parse_percent_case69(void);
void		test_parse_percent_case70(void);
void		test_parse_percent_case71(void);
void		test_parse_percent_case72(void);
void		test_parse_percent_case73(void);
void		test_parse_percent_case74(void);
void		test_parse_percent_case75(void);
void		test_parse_percent_case76(void);
void		test_parse_percent_case77(void);
void		test_parse_percent_case78(void);
void		test_parse_percent_case79(void);
void		test_parse_percent_case80(void);
void		test_parse_percent_case81(void);
void		test_parse_percent_case82(void);
void		test_parse_percent_case83(void);
void		test_parse_percent_case84(void);
void		test_parse_percent_case85(void);
void		test_parse_percent_case86(void);
void		test_parse_percent_case87(void);
void		test_parse_percent_case88(void);
void		test_parse_percent_case89(void);
void		test_parse_percent_case90(void);
void		test_parse_percent_case91(void);
void		test_parse_percent_case92(void);
void		test_parse_percent_case93(void);
void		test_parse_percent_case94(void);
void		test_parse_percent_case95(void);
void		test_parse_percent_case96(void);
void		test_parse_percent_case97(void);
void		test_parse_percent_case98(void);
void		test_parse_percent_case99(void);
void		test_parse_percent_case100(void);
void		test_parse_percent_case101(void);
void		test_parse_percent_case102(void);

/*
** double write test
*/
void		test_double_get_integer_part_case1(void);
void		test_double_get_integer_part_case2(void);
void		test_double_get_integer_part_case3(void);
void		test_double_get_integer_part_case4(void);
void		test_double_get_integer_part_case5(void);
void		test_double_get_integer_part_case6(void);

void		test_double_get_fraction_part_case1(void);
void		test_double_get_fraction_part_case2(void);
void		test_double_get_fraction_part_case3(void);
void		test_double_get_fraction_part_case4(void);
void		test_double_get_fraction_part_case5(void);
void		test_double_get_fraction_part_case6(void);
void		test_double_get_fraction_part_case7(void);
void		test_double_get_fraction_part_case8(void);
void		test_double_get_fraction_part_case9(void);

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

void		test_ldouble_get_integer_part_case1(void);
void		test_ldouble_get_integer_part_case2(void);
void		test_ldouble_get_integer_part_case3(void);
void		test_ldouble_get_integer_part_case4(void);
void		test_ldouble_get_integer_part_case5(void);
void		test_ldouble_get_integer_part_case6(void);

void		test_ldouble_get_fraction_part_case1(void);
void		test_ldouble_get_fraction_part_case2(void);
void		test_ldouble_get_fraction_part_case3(void);
void		test_ldouble_get_fraction_part_case4(void);
void		test_ldouble_get_fraction_part_case5(void);
void		test_ldouble_get_fraction_part_case6(void);
void		test_ldouble_get_fraction_part_case7(void);
void		test_ldouble_get_fraction_part_case8(void);

void		test_ldouble_write_case1(void);
void		test_ldouble_write_case2(void);
void		test_ldouble_write_case3(void);
void		test_ldouble_write_case4(void);
void		test_ldouble_write_case5(void);
void		test_ldouble_write_case6(void);
void		test_ldouble_write_case7(void);
void		test_ldouble_write_case8(void);
void		test_ldouble_write_case9(void);
void		test_ldouble_write_case10(void);
void		test_ldouble_write_case11(void);

/*
** arg_prefix test
*/
void		test_arg_o_prefix_case1(void);
void		test_arg_o_prefix_case2(void);
void		test_arg_o_prefix_case3(void);

void		test_arg_x_prefix_case1(void);
void		test_arg_x_prefix_case2(void);
void		test_arg_x_prefix_case3(void);

void		test_arg_upper_x_prefix_case1(void);
void		test_arg_upper_x_prefix_case2(void);
void		test_arg_upper_x_prefix_case3(void);

void		test_arg_p_prefix_case1(void);
void		test_arg_p_prefix_case2(void);

/*
** arg_leading_zero test
*/
void		test_arg_leading_zero_case1(void);
void		test_arg_leading_zero_case2(void);
void		test_arg_leading_zero_case3(void);

void		test_arg_o_leading_zero_case1(void);
void		test_arg_o_leading_zero_case2(void);
void		test_arg_o_leading_zero_case3(void);
void		test_arg_o_leading_zero_case4(void);
void		test_arg_o_leading_zero_case5(void);

#endif
