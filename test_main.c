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

	return (0);
}
