/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:24:36 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 23:13:31 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_width(int width, int content_len, char pad)
{
	int	count;
	int	pad_len;

	count = 0;
	pad_len = width - content_len;
	while (pad_len-- > 0)
	{
		ft_putchar(pad);
		count++;
	}
	return (count);
}

int	apply_precision(int precision, int num_len)
{
	int	count;
	int	pad_len;

	count = 0;
	pad_len = precision - num_len;
	while (pad_len-- > 0)
	{
		ft_putchar('0');
		count++;
	}
	return (count);
}

int	ft_putstr_precision(char *str, int precision)
{
	int	len;

	len = 0;
	if (!str && precision < 6 && precision != -1)
		return (0);
	if (!str)
		str = "(null)";
	while (*str && (precision < 0 || len < precision))
	{
		ft_putchar(*str);
		len++;
		str++;
	}
	return (len);
}
