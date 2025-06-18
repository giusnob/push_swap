/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:52:13 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 20:34:12 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

bool	is_integer(const char *str)
{
	long	n;
	int		i;

	if (!str || !*str)
		return (false);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (false);
	return (true);
}

bool	is_sorted(int *arr, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (arr[i - 1] > arr[i])
			return (false);
		i++;
	}
	return (true);
}

int	find_min_idx(int *arr, int n)
{
	int	min_idx;
	int	i;

	min_idx = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}
