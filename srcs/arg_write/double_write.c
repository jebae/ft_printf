#include "ft_printf.h"

static void		handle_return(t_fixedpoint *int_part, t_fixedpoint *fraction_part)
{
	if (int_part != NULL)
		ft_memdel((void **)&int_part->num.data);
	ft_memdel((void **)&fraction_part->num.data);
}

static int		handle_inf_nan(double num, t_fp_buffer *buf)
{
	static char		*inf = "inf";
	static char		*nan = "nan";
	char			*word;
	int				i;

	word = NULL;
	if (ft_is_inf(num))
		word = inf;
	else if (ft_is_nan(num))
		word = nan;
	else
		return (0);
	i = 0;
	while (i < 3)
	{
		fp_write_buffer(buf, word[i]);
		i++;
	}
	return (1);
}

static int		write_parts(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part,
	size_t precision,
	t_fp_buffer *buf
)
{
	int			carry;

	carry = (fraction_part->e >= 0) && (fraction_part->num.occupied != 0);
	if (fp_double_write_integer_part(int_part, carry, buf) == FP_FAIL)
		return (FP_FAIL);
	if (precision == 0)
		return (FP_SUCCESS);
	fp_write_buffer(buf, '.');
	if (fp_double_write_fraction_part(fraction_part, precision, buf) == FP_FAIL)
		return (FP_FAIL);
	return (FP_SUCCESS);
}

void			fp_double_write(
	double num,
	size_t precision,
	t_fp_buffer *buf
)
{
	short				exponent;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;

	if (handle_inf_nan(num, buf))
		return ;
	ft_extract_double(num, &exponent, &mantissa);
	mantissa |= 0x10000000000000;
	fxp_init(&int_part);
	fxp_init(&fraction_part);
	if (exponent != 0x000 && fp_double_fraction_part(
		exponent - 0x3ff, mantissa, precision, &fraction_part) == FP_FAIL)
		return (handle_return(NULL, &fraction_part));
	if (fp_double_integer_part(
		exponent - 0x3ff, mantissa, &int_part) == FP_FAIL)
		return (handle_return(NULL, &fraction_part));
	write_parts(&int_part, &fraction_part, precision, buf);
	return (handle_return(&int_part, &fraction_part));
}
