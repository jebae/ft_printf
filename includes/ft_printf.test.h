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
** handle tags test
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

#endif
