#include "ft_printf.test.h"

void		test(int res, const char *msg)
{
	if (!res)
		printf(KRED "%s\n" KNRM, msg);
}
