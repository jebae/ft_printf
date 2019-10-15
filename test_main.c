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

	test_long_double_int_part_length_case1();
	test_long_double_int_part_length_case2();
	test_long_double_int_part_length_case3();
	test_long_double_int_part_length_case4();
	test_long_double_int_part_length_case5();
	test_long_double_int_part_length_case6();

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

	test_arg_lf_length_case1();
	test_arg_lf_length_case2();
	test_arg_lf_length_case3();
	test_arg_lf_length_case4();
	test_arg_lf_length_case5();

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

	test_parse_u_case1();
	test_parse_u_case2();
	test_parse_u_case3();
	test_parse_u_case4();
	test_parse_u_case5();

	test_parse_specifier_case1();
	test_parse_specifier_case2();
	test_parse_specifier_case3();

	test_parse_percent_case1();
	test_parse_percent_case2();
	test_parse_percent_case3();
	test_parse_percent_case4();
	test_parse_percent_case5();
	test_parse_percent_case6();
	test_parse_percent_case7();

	// float write
	test_double_integer_part_case1();
	test_double_integer_part_case2();
	test_double_integer_part_case3();
	test_double_integer_part_case4();
	test_double_integer_part_case5();

	test_double_fraction_part_case1();
	test_double_fraction_part_case2();
	test_double_fraction_part_case3();
	test_double_fraction_part_case4();
	test_double_fraction_part_case5();
	test_double_fraction_part_case6();
	// while (1);
}
