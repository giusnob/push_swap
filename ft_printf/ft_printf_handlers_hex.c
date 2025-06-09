/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:24:36 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 23:10:11 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static int	get_total_len(unsigned long n, t_flags flags)
{
	int	len_hex;
	int	prec_padding;
	int	prefix_len;
	int	total_len;

	len_hex = count_hex(n);
	if (n == 0 && flags.precision == 0)
		len_hex = 0;
	prec_padding = 0;
	if (flags.precision > len_hex)
		prec_padding = flags.precision - len_hex;
	prefix_len = 0;
	if (flags.hash && n != 0)
		prefix_len = 2;
	total_len = prefix_len + prec_padding + len_hex;
	return (total_len);
}

int	handle_hex_first_part(int total_len, t_flags flags)
{
	int	printed;

	printed = 0;
	if (!flags.minus && !flags.ovo)
		printed += apply_width(flags.width, total_len, ' ');
	if (!flags.minus && flags.ovo && flags.precision == -1)
		printed += apply_width(flags.width, total_len, '0');
	return (printed);
}

int	handle_hex(va_list *args, t_flags flags, char type)
{
	unsigned int	n;
	int				len_hex_orig;
	int				total_len;
	int				printed;

	n = va_arg(*args, unsigned int);
	len_hex_orig = count_hex(n);
	total_len = get_total_len(n, flags);
	printed = 0;
	printed += handle_hex_first_part(total_len, flags);
	if (flags.hash && n != 0 && type == 'x')
		printed += ft_putstr("0x");
	else if (flags.hash && n != 0 && type == 'X')
		printed += ft_putstr("0X");
	if (n == 0 && flags.precision == 0)
		printed += apply_precision(flags.precision, 0);
	else
		printed += apply_precision(flags.precision, len_hex_orig);
	if (!(n == 0 && flags.precision == 0))
		printed += ft_puthex(n, type);
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}

int	handle_pointer(va_list *args, t_flags flags)
{
	const unsigned long	ptr = va_arg(*args, unsigned long);
	int					printed;
	int					hex_count;
	int					total_len;

	printed = 0;
	hex_count = count_hex(ptr);
	if (!ptr)
		hex_count = ft_strlen("(nil)");
	total_len = hex_count;
	if (ptr)
		total_len += 2;
	if (!flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	if (!ptr)
		printed += ft_putstr("(nil)");
	if (ptr)
	{
		printed += ft_putstr("0x");
		printed += ft_puthex(ptr, 'x');
	}
	if (flags.minus)
		printed += apply_width(flags.width, total_len, ' ');
	return (printed);
}
