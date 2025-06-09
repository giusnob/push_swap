/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:27:30 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/18 20:01:09 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	width;
	int	precision;
	int	ovo;
	int	minus;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(const char *format, ...);

int		handle_char(va_list *args, t_flags flags);
int		handle_string(va_list *args, t_flags flags);
int		handle_decimal(va_list *args, t_flags flags);
int		handle_unsigned(va_list *args, t_flags flags);
int		handle_hex(va_list *args, t_flags flags, char type);
int		handle_pointer(va_list *args, t_flags flags);
int		handle_percent(t_flags flags);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putstr_precision(char *str, int precision);
int		ft_putnbr(long n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex(unsigned long n, char type);
int		ft_putptr(unsigned long ptr);
int		calc_total_len(int len_num, t_flags flags);

int		apply_width(int width, int content_len, char pad);
int		apply_precision(int precision, int num_len);

void	parse_flags(const char **format, va_list *args, t_flags *flags);

int		count_unsigned(unsigned int n);
int		count_digits(long n);

#endif
