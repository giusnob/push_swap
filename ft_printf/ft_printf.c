/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:27:11 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 14:33:38 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_case(char end, va_list *args, t_flags flags)
{
	if (end == 'c')
		return (handle_char(args, flags));
	else if (end == 's')
		return (handle_string(args, flags));
	else if (end == 'd' || end == 'i')
		return (handle_decimal(args, flags));
	else if (end == 'u')
		return (handle_unsigned(args, flags));
	else if (end == 'x' || end == 'X')
		return (handle_hex(args, flags, end));
	else if (end == 'p')
		return (handle_pointer(args, flags));
	else if (end == '%')
		return (handle_percent(flags));
	else
		return (ft_putchar(end));
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	t_flags		flags;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = (t_flags){0, -1, 0, 0, 0, 0, 0};
			parse_flags(&format, &args, &flags);
			len += handle_case(*format, &args, flags);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
