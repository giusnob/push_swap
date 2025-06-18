/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:23:18 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 20:30:50 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsign(int c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

long	ft_atol(const char *nptr)
{
	long	i;
	int		z;
	int		sign;

	i = 0;
	z = 0;
	sign = 1;
	while (ft_isspace(nptr[z]))
		z++;
	if (nptr[z] == '-' || nptr[z] == '+')
	{
		sign = ft_getsign(nptr[z]);
		z++;
	}
	while (nptr[z] >= '0' && nptr[z] <= '9')
	{
		i = i * 10 + (nptr[z] - '0');
		z++;
	}
	return (i * sign);
}
