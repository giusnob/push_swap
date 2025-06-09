/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:24:36 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 22:02:22 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_without_minus(int negative, int total_len,
		t_flags flags)
{
	int	printed;

	printed = 0;
	if (flags.ovo && flags.precision == -1)
	{
		if (negative)
			printed += ft_putchar('-');
		else if (flags.plus)
			printed += ft_putchar('+');
		else if (flags.space)
			printed += ft_putchar(' ');
		printed += apply_width(flags.width, total_len, '0');
	}
	else
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}

int	handle_zero_without_precision(int negative, t_flags flags)
{
	int	printed;

	printed = 0;
	if (negative)
		printed += ft_putchar('-');
	else if (flags.plus)
		printed += ft_putchar('+');
	else if (flags.space)
		printed += ft_putchar(' ');
	return (printed);
}

int	count_total_len(t_flags flags, int num)
{
	int			len_num;
	int			effective_precision;
	int			total_len;

	if (num == 0 && flags.precision == 0)
		len_num = 0;
	else
		len_num = count_digits(num);
	effective_precision = len_num;
	if (flags.precision > len_num)
		effective_precision = flags.precision;
	total_len = effective_precision;
	if (num < 0 || flags.plus || flags.space)
		total_len += 1;
	return (total_len);
}

int	handle_decimal(va_list *args, t_flags flags)
{
	const int	num = va_arg(*args, int);
	int			printed;
	long		n;
	int			total_len;
	int			digits;

	total_len = count_total_len(flags, num);
	printed = 0;
	n = num;
	if (n < 0)
		n = -n;
	if (!flags.minus)
		printed += handle_without_minus(num < 0, total_len, flags);
	if (!(flags.ovo && flags.precision == -1))
		printed += handle_zero_without_precision(num < 0, flags);
	if (num == 0 && flags.precision == 0)
		digits = 0;
	else
		digits = count_digits(n);
	printed += apply_precision(flags.precision, digits);
	if (!(num == 0 && flags.precision == 0))
		printed += ft_putnbr(n);
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}

int	handle_unsigned(va_list *args, t_flags flags)
{
	const unsigned int	n = va_arg(*args, unsigned int);
	const int			len_num_orig = count_unsigned(n);
	int					len_num;
	int					total_len;
	int					printed;

	len_num = len_num_orig;
	if (n == 0 && flags.precision == 0)
		len_num = 0;
	total_len = calc_total_len(len_num, flags);
	printed = 0;
	if (!flags.minus && !flags.ovo)
		printed += apply_width(flags.width, total_len, ' ');
	if (!flags.minus && flags.ovo && flags.precision == -1)
		printed += apply_width(flags.width, total_len, '0');
	printed += apply_precision(flags.precision, len_num);
	if (!(n == 0 && flags.precision == 0))
		printed += ft_putnbr_unsigned(n);
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}
