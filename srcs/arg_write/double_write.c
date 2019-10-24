/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:15:05 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:18:54 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_return(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part
)
{
	fxp_del(int_part);
	fxp_del(fraction_part);
}

static void		write_parts(
	t_fixedpoint *int_part,
	t_fixedpoint *fraction_part,
	size_t precision,
	t_fp_buffer *buf
)
{
	int			carry;

	carry = (fraction_part->e >= 0) && (fraction_part->num.occupied != 0);
	fp_double_write_integer_part(int_part, buf);
	if (precision == 0)
		return ;
	fp_write_buffer(buf, '.');
	fp_double_write_fraction_part(fraction_part, precision, buf);
}

void			fp_double_write(
	double num,
	size_t precision,
	t_fp_buffer *buf
)
{
	short				exponent;
	int					carry;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;

	ft_extract_double(num, &exponent, &mantissa);
	fxp_init(&int_part);
	fxp_init(&fraction_part);
	if (!(exponent == 0 && mantissa == 0))
	{
		mantissa |= 0x10000000000000;
		exponent -= 0x3ff;
		if (fp_double_get_fraction_part(
			exponent, mantissa, precision, &fraction_part) == FP_FAIL)
			return (handle_return(NULL, &fraction_part));
		carry = (fraction_part.e >= 0 && fraction_part.num.occupied != 0);
		if (carry)
			bi_erase(&fraction_part.num);
		if (fp_double_get_integer_part(
			exponent, mantissa, carry, &int_part) == FP_FAIL)
			return (handle_return(NULL, &fraction_part));
	}
	write_parts(&int_part, &fraction_part, precision, buf);
	return (handle_return(&int_part, &fraction_part));
}

void			fp_ldouble_write(
	long double num,
	size_t precision,
	t_fp_buffer *buf
)
{
	short				exponent;
	int					carry;
	unsigned long long	mantissa;
	t_fixedpoint		int_part;
	t_fixedpoint		fraction_part;

	ft_extract_ldouble(num, &exponent, &mantissa);
	fxp_init(&int_part);
	fxp_init(&fraction_part);
	if (!(exponent == 0 && mantissa == 0))
	{
		exponent -= 0x3fff;
		if (fp_ldouble_get_fraction_part(
			exponent, mantissa, precision, &fraction_part) == FP_FAIL)
			return (handle_return(&int_part, &fraction_part));
		carry = (fraction_part.e >= 0 && fraction_part.num.occupied != 0);
		if (carry)
			bi_erase(&fraction_part.num);
		if (fp_ldouble_get_integer_part(
			exponent, mantissa, carry, &int_part) == FP_FAIL)
			return (handle_return(&int_part, &fraction_part));
	}
	write_parts(&int_part, &fraction_part, precision, buf);
	return (handle_return(&int_part, &fraction_part));
}
