/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:24:36 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 22:03:58 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_negative_width(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
}

static int	handle_dot(t_flags *flags, va_list *args, const char **format)
{
	flags->ovo = 0;
	flags->precision = 0;
	(*format)++;
	if (**format == '*')
	{
		flags->precision = va_arg(*args, int);
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			flags->precision = flags->precision * 10 + (**format - '0');
			(*format)++;
		}
		return (1);
	}
	return (0);
}

static void	handle_wildcard(t_flags *flags, va_list *args)
{
	if (flags->precision != -1)
	{
		flags->precision = va_arg(*args, int);
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else
	{
		flags->width = va_arg(*args, int);
		handle_negative_width(flags);
	}
}

void	handle_digit(t_flags *flags, const char **format)
{
	if (flags->precision != -1)
		flags->precision = flags->precision * 10 + (**format - '0');
	else
		flags->width = flags->width * 10 + (**format - '0');
}

void	parse_flags(const char **format, va_list *args, t_flags *flags)
{
	while (**format)
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0' && flags->width == 0 && flags->minus == 0)
			flags->ovo = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '.')
		{
			if (handle_dot(flags, args, format) == 1)
				continue ;
		}
		else if (**format >= '0' && **format <= '9')
			handle_digit(flags, format);
		else if (**format == '*')
			handle_wildcard(flags, args);
		else
			break ;
		(*format)++;
	}
}
