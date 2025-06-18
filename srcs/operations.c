/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:17 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 15:18:29 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *arr)
{
	int	tmp;

	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	ft_putendl_fd("sa", 1);
}

void	ra(int *arr, int n)
{
	int	tmp;
	int	i;

	if (n <= 1)
		return ;
	tmp = arr[0];
	i = 0;
	while (i < n - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[n - 1] = tmp;
	ft_putendl_fd("ra", 1);
}

void	rra(int *arr, int n)
{
	int	tmp;
	int	i;

	tmp = arr[n - 1];
	i = n - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = tmp;
	ft_putendl_fd("rra", 1);
}

void	push(t_stack src, t_stack dst, char *op)
{
	int	i;

	if (*src.len <= 0)
		return ;
	i = *dst.len;
	while (i > 0)
	{
		dst.arr[i] = dst.arr[i - 1];
		i--;
	}
	dst.arr[0] = src.arr[0];
	(*dst.len)++;
	i = 0;
	while (i < *src.len - 1)
	{
		src.arr[i] = src.arr[i + 1];
		i++;
	}
	(*src.len)--;
	ft_putendl_fd(op, 1);
}
