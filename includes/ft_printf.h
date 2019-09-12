#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

/*
** bit_flags macros
*/
# define PRTF_BIT_MASK_FLAG				(1 << 0)
# define PRTF_BIT_MASK_WIDTH			(1 << 1)
# define PRTF_BIT_MASK_PRECISION		(1 << 2)
# define PRTF_BIT_MASK_LENGTH			(1 << 3)

/*
** flag macros
*/
# define PRTF_FLAG_MINUS				0
# define PRTF_FLAG_PLUS					1
# define PRTF_FLAG_SPACE				2
# define PRTF_FLAG_ZERO					3

typedef struct	s_tags
{
	char	bit_mask;
	int		flag;
	int		length;
	size_t	width;
	size_t	precision;
}				t_tags;

size_t			handle_flag(const char *format, t_tags *tags);

#endif
