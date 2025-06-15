/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:17 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/15 15:15:10 by ginobile         ###   ########.fr       */
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

void	push(int *src, int *slen, int *dst, int *dlen, char *op)
{
	int	i;

	if (*slen <= 0)
		return ;
	i = *dlen;
	while (i > 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = src[0];
	(*dlen)++;
	i = 0;
	while (i < *slen - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*slen)--;
	ft_putendl_fd(op, 1);
}
