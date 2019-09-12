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
void		test_handle_flag_case1(void);
void		test_handle_flag_case2(void);
void		test_handle_flag_case3(void);
void		test_handle_flag_case4(void);
void		test_handle_flag_case5(void);

#endif
