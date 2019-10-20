#include "ft_printf.test.h"

int		main(void)
{
	// tags
	test_init_tags_case1();

	test_parse_flag_case1();
	test_parse_flag_case2();
	test_parse_flag_case3();
	test_parse_flag_case4();
	test_parse_flag_case5();

	test_parse_width_case1();
	test_parse_width_case2();

	test_parse_precision_case1();
	test_parse_precision_case2();
	test_parse_precision_case3();

	test_parse_length_case1();
	test_parse_length_case2();
	test_parse_length_case3();
	test_parse_length_case4();
	test_parse_length_case5();
	test_parse_length_case6();

	// arg_length
	test_int_length_case1();
	test_int_length_case2();
	test_int_length_case3();
	test_int_length_case4();
	test_int_length_case5();
	test_int_length_case6();
	test_int_length_case7();
	test_int_length_case8();

	test_uint_length_case1();
	test_uint_length_case2();
	test_uint_length_case3();
	test_uint_length_case4();
	test_uint_length_case5();
	test_uint_length_case6();
	test_uint_length_case7();
	test_uint_length_case8();

	test_double_int_part_length_case1();
	test_double_int_part_length_case2();
	test_double_int_part_length_case3();
	test_double_int_part_length_case4();
	test_double_int_part_length_case5();
	test_double_int_part_length_case6();

	test_ldouble_int_part_length_case1();
	test_ldouble_int_part_length_case2();
	test_ldouble_int_part_length_case3();
	test_ldouble_int_part_length_case4();
	test_ldouble_int_part_length_case5();
	test_ldouble_int_part_length_case6();

	test_arg_d_length_case1();
	test_arg_d_length_case2();
	test_arg_d_length_case3();
	test_arg_d_length_case4();

	test_arg_hd_length_case1();
	test_arg_hd_length_case2();
	test_arg_hd_length_case3();
	test_arg_hd_length_case4();

	test_arg_hhd_length_case1();
	test_arg_hhd_length_case2();
	test_arg_hhd_length_case3();
	test_arg_hhd_length_case4();

	test_arg_ld_length_case1();
	test_arg_ld_length_case2();
	test_arg_ld_length_case3();
	test_arg_ld_length_case4();

	test_arg_lld_length_case1();
	test_arg_lld_length_case2();
	test_arg_lld_length_case3();
	test_arg_lld_length_case4();

	test_arg_u_length_case1();
	test_arg_u_length_case2();
	test_arg_u_length_case3();
	test_arg_u_length_case4();

	test_arg_hu_length_case1();
	test_arg_hu_length_case2();
	test_arg_hu_length_case3();
	test_arg_hu_length_case4();

	test_arg_hhu_length_case1();
	test_arg_hhu_length_case2();
	test_arg_hhu_length_case3();
	test_arg_hhu_length_case4();

	test_arg_lu_length_case1();
	test_arg_lu_length_case2();
	test_arg_lu_length_case3();
	test_arg_lu_length_case4();

	test_arg_llu_length_case1();
	test_arg_llu_length_case2();
	test_arg_llu_length_case3();
	test_arg_llu_length_case4();

	test_arg_f_length_case1();
	test_arg_f_length_case2();
	test_arg_f_length_case3();
	test_arg_f_length_case4();
	test_arg_f_length_case5();
	test_arg_f_length_case6();
	test_arg_f_length_case7();

	test_arg_lf_length_case1();
	test_arg_lf_length_case2();
	test_arg_lf_length_case3();
	test_arg_lf_length_case4();
	test_arg_lf_length_case5();
	test_arg_lf_length_case6();
	test_arg_lf_length_case7();

	// arg_sign
	test_num_sign_case1();
	test_num_sign_case2();
	test_num_sign_case3();
	test_num_sign_case4();
	test_num_sign_case5();

	test_arg_d_sign_case1();
	test_arg_d_sign_case2();
	test_arg_d_sign_case3();
	test_arg_d_sign_case4();
	test_arg_d_sign_case5();
	test_arg_d_sign_case6();
	test_arg_d_sign_case7();
	test_arg_d_sign_case8();
	test_arg_d_sign_case9();
	test_arg_d_sign_case10();

	test_arg_hd_sign_case1();
	test_arg_hhd_sign_case1();
	test_arg_ld_sign_case1();
	test_arg_lld_sign_case1();

	test_arg_no_sign_case1();
	test_arg_no_sign_case2();
	test_arg_no_sign_case3();

	test_arg_f_sign_case1();
	test_arg_f_sign_case2();
	test_arg_f_sign_case3();
	test_arg_f_sign_case4();
	test_arg_f_sign_case5();
	test_arg_f_sign_case6();
	test_arg_f_sign_case7();
	test_arg_f_sign_case8();
	test_arg_f_sign_case9();
	test_arg_f_sign_case10();
	test_arg_f_sign_case11();
	test_arg_f_sign_case12();

	test_arg_lf_sign_case1();
	test_arg_lf_sign_case2();
	test_arg_lf_sign_case3();
	test_arg_lf_sign_case4();
	test_arg_lf_sign_case5();
	test_arg_lf_sign_case6();
	test_arg_lf_sign_case7();
	test_arg_lf_sign_case8();

	// buffer
	test_init_buffer_case1();
	test_write_buffer_case1();
	test_write_buffer_case2();
	test_flush_buffer_case1();
	test_flush_buffer_case2();

	// write
	test_int_write_case1();
	test_int_write_case2();
	test_int_write_case3();
	test_int_write_case4();
	test_int_write_case5();
	test_int_write_case6();

	test_uint_write_case1();
	test_uint_write_case2();
	test_uint_write_case3();
	test_uint_write_case4();

	test_arg_d_write_case1();
	test_arg_d_write_case2();
	test_arg_d_write_case3();
	test_arg_d_write_case4();

	test_arg_hd_write_case1();
	test_arg_hhd_write_case1();
	test_arg_ld_write_case1();
	test_arg_lld_write_case1();

	test_arg_u_write_case1();
	test_arg_u_write_case2();
	test_arg_u_write_case3();
	test_arg_u_write_case4();

	test_arg_hu_write_case1();
	test_arg_hu_write_case2();
	test_arg_hu_write_case3();
	test_arg_hu_write_case4();

	test_arg_hhu_write_case1();
	test_arg_hhu_write_case2();
	test_arg_hhu_write_case3();
	test_arg_hhu_write_case4();

	test_arg_lu_write_case1();
	test_arg_lu_write_case2();
	test_arg_lu_write_case3();
	test_arg_lu_write_case4();

	test_arg_llu_write_case1();
	test_arg_llu_write_case2();
	test_arg_llu_write_case3();
	test_arg_llu_write_case4();

	// double write
	test_double_integer_part_case1();
	test_double_integer_part_case2();
	test_double_integer_part_case3();
	test_double_integer_part_case4();
	test_double_integer_part_case5();
	test_double_integer_part_case6();

	test_double_fraction_part_case1();
	test_double_fraction_part_case2();
	test_double_fraction_part_case3();
	test_double_fraction_part_case4();
	test_double_fraction_part_case5();
	test_double_fraction_part_case6();
	test_double_fraction_part_case7();
	test_double_fraction_part_case8();

	test_double_write_integer_part_case1();
	test_double_write_integer_part_case2();
	test_double_write_integer_part_case3();
	test_double_write_integer_part_case4();
	test_double_write_integer_part_case5();
	test_double_write_integer_part_case6();
	test_double_write_integer_part_case7();

	test_double_write_fraction_part_case1();
	test_double_write_fraction_part_case2();
	test_double_write_fraction_part_case3();
	test_double_write_fraction_part_case4();
	test_double_write_fraction_part_case5();
	test_double_write_fraction_part_case6();
	test_double_write_fraction_part_case7();
	test_double_write_fraction_part_case8();
	test_double_write_fraction_part_case9();
	test_double_write_fraction_part_case10();
	test_double_write_fraction_part_case11();
	test_double_write_fraction_part_case12();
	test_double_write_fraction_part_case13();
	test_double_write_fraction_part_case14();
	test_double_write_fraction_part_case15();
	test_double_write_fraction_part_case16();

	test_double_write_case1();
	test_double_write_case2();
	test_double_write_case3();
	test_double_write_case4();
	test_double_write_case5();
	test_double_write_case6();
	test_double_write_case7();
	test_double_write_case8();
	test_double_write_case9();
	test_double_write_case10();
	test_double_write_case11();
	test_double_write_case12();
	test_double_write_case13();

	test_arg_f_write_case1();
	test_arg_f_write_case2();
	test_arg_f_write_case3();
	test_arg_f_write_case4();
	test_arg_f_write_case5();
	test_arg_f_write_case6();
	test_arg_f_write_case7();
	test_arg_f_write_case8();

	test_arg_lf_write_case1();
	test_arg_lf_write_case2();
	test_arg_lf_write_case3();
	test_arg_lf_write_case4();
	test_arg_lf_write_case5();
	test_arg_lf_write_case6();
	test_arg_lf_write_case7();
	test_arg_lf_write_case8();

	// parse percent
	test_write_sign_case1();
	test_write_sign_case2();

	test_write_padding_case1();
	test_write_padding_case2();
	test_write_padding_case3();
	test_write_padding_case4();

	test_write_percent_format_case1();
	test_write_percent_format_case2();
	test_write_percent_format_case3();
	test_write_percent_format_case4();
	test_write_percent_format_case5();
	test_write_percent_format_case6();
	test_write_percent_format_case7();
	test_write_percent_format_case8();
	test_write_percent_format_case9();
	test_write_percent_format_case10();
	test_write_percent_format_case11();
	test_write_percent_format_case12();
	test_write_percent_format_case13();
	test_write_percent_format_case14();
	test_write_percent_format_case15();
	test_write_percent_format_case16();
	test_write_percent_format_case17();
	test_write_percent_format_case18();
	test_write_percent_format_case19();
	test_write_percent_format_case20();
	test_write_percent_format_case21();
	test_write_percent_format_case22();
	test_write_percent_format_case23();
	test_write_percent_format_case24();
	test_write_percent_format_case25();
	test_write_percent_format_case26();
	test_write_percent_format_case27();
	test_write_percent_format_case28();
	test_write_percent_format_case29();
	test_write_percent_format_case30();
	test_write_percent_format_case31();
	test_write_percent_format_case32();

	test_parse_d_case1();
	test_parse_d_case2();
	test_parse_d_case3();
	test_parse_d_case4();
	test_parse_d_case5();
	test_parse_d_case6();

	test_parse_u_case1();
	test_parse_u_case2();
	test_parse_u_case3();
	test_parse_u_case4();
	test_parse_u_case5();
	test_parse_u_case6();

	test_parse_f_case1();
	test_parse_f_case2();
	test_parse_f_case3();
	test_parse_f_case4();
	test_parse_f_case5();
	test_parse_f_case6();
	test_parse_f_case7();
	test_parse_f_case8();

	test_parse_specifier_case1();
	test_parse_specifier_case2();
	test_parse_specifier_case3();
	test_parse_specifier_case4();

	test_parse_percent_case1();
	test_parse_percent_case2();
	test_parse_percent_case3();
	test_parse_percent_case4();
	test_parse_percent_case5();
	test_parse_percent_case6();
	test_parse_percent_case7();
	test_parse_percent_case8();
	test_parse_percent_case9();
	test_parse_percent_case10();
	test_parse_percent_case11();
	test_parse_percent_case12();
	test_parse_percent_case13();
	test_parse_percent_case14();
	test_parse_percent_case15();
	test_parse_percent_case16();
	test_parse_percent_case17();
	test_parse_percent_case18();
	test_parse_percent_case19();
	test_parse_percent_case20();

	test_arg_x_length_case1();
	test_arg_x_length_case2();
	test_arg_x_length_case3();
	test_arg_x_length_case4();

	test_arg_hx_length_case1();
	test_arg_hx_length_case2();
	test_arg_hx_length_case3();

	test_arg_hhx_length_case1();
	test_arg_hhx_length_case2();

	test_arg_lx_length_case1();

	test_arg_llx_length_case1();

	test_arg_x_write_case1();
	test_arg_x_write_case2();

	test_arg_hx_write_case1();
	test_arg_hx_write_case2();

	test_arg_hhx_write_case1();
	test_arg_hhx_write_case2();

	test_arg_lx_write_case1();
	test_arg_llx_write_case1();

	test_parse_x_case1();
	test_parse_x_case2();
	test_parse_x_case3();
	test_parse_x_case4();
	test_parse_x_case5();
	test_parse_x_case6();

	test_parse_specifier_case5();

	test_parse_percent_case21();
	test_parse_percent_case22();
	test_parse_percent_case23();
	test_parse_percent_case24();
	test_parse_percent_case25();
	test_parse_percent_case26();
	test_parse_percent_case27();

	test_arg_o_length_case1();
	test_arg_o_length_case2();
	test_arg_o_length_case3();
	test_arg_o_length_case4();

	test_arg_ho_length_case1();
	test_arg_ho_length_case2();

	test_arg_hho_length_case1();
	test_arg_hho_length_case2();

	test_arg_lo_length_case1();

	test_arg_llo_length_case1();

	test_arg_o_write_case1();
	test_arg_o_write_case2();

	test_arg_ho_write_case1();
	test_arg_ho_write_case2();

	test_arg_hho_write_case1();
	test_arg_hho_write_case2();

	test_arg_lo_write_case1();

	test_arg_llo_write_case1();

	test_parse_o_case1();
	test_parse_o_case2();
	test_parse_o_case3();
	test_parse_o_case4();
	test_parse_o_case5();
	test_parse_o_case6();

	test_parse_specifier_case6();

	test_parse_percent_case28();
	test_parse_percent_case29();
	test_parse_percent_case30();
	test_parse_percent_case31();
	test_parse_percent_case32();
	test_parse_percent_case33();

	test_ldouble_integer_part_case1();
	test_ldouble_integer_part_case2();
	test_ldouble_integer_part_case3();
	test_ldouble_integer_part_case4();
	test_ldouble_integer_part_case5();
	test_ldouble_integer_part_case6();

	test_ldouble_fraction_part_case1();
	test_ldouble_fraction_part_case2();
	test_ldouble_fraction_part_case3();
	test_ldouble_fraction_part_case4();
	test_ldouble_fraction_part_case5();
	test_ldouble_fraction_part_case6();
	test_ldouble_fraction_part_case7();
	test_ldouble_fraction_part_case8();

	test_ldouble_write_case1();
	test_ldouble_write_case2();
	test_ldouble_write_case3();
	test_ldouble_write_case4();
	test_ldouble_write_case5();
	test_ldouble_write_case6();
	test_ldouble_write_case7();
	test_ldouble_write_case8();
	test_ldouble_write_case9();
	test_ldouble_write_case10();
	test_ldouble_write_case11();
	test_ldouble_write_case12();
	test_ldouble_write_case13();

	test_arg_lf_sign_case9();
	test_arg_lf_sign_case10();
	test_arg_lf_sign_case11();
	test_arg_lf_sign_case12();

	test_parse_percent_case34();
	test_parse_percent_case35();
	test_parse_percent_case36();
	test_parse_percent_case37();
	test_parse_percent_case38();
	test_parse_percent_case39();
	test_parse_percent_case40();
	test_parse_percent_case41();
	test_parse_percent_case42();
	test_parse_percent_case43();
	test_parse_percent_case44();

	test_arg_s_length_case1();
	test_arg_s_length_case2();
	test_arg_s_length_case3();
	test_arg_s_length_case4();
	test_arg_s_length_case5();

	test_arg_s_write_case1();
	test_arg_s_write_case2();
	test_arg_s_write_case3();
	test_arg_s_write_case4();
	test_arg_s_write_case5();
	test_arg_s_write_case6();

	test_parse_s_case1();

	test_parse_specifier_case7();

	test_parse_percent_case44();
	test_parse_percent_case45();
	test_parse_percent_case46();
	test_parse_percent_case47();
	test_parse_percent_case48();
	test_parse_percent_case49();
	test_parse_percent_case50();
	test_parse_percent_case51();
	test_parse_percent_case52();
	test_parse_percent_case53();
	test_parse_percent_case54();
	test_parse_percent_case55();

	test_arg_c_length_case1();

	//while (1);
}
