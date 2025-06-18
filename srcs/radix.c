/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:43 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 21:09:54 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_loop(t_stack a, t_stack b, int n)
{
	int	bit;
	int	i;

	bit = 0;
	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (((a.arr[0] >> bit) & 1) == 0)
				push(a, b, "pb");
			else
				ra(a.arr, *a.len);
			i++;
		}
		while (*b.len > 0)
			push(b, a, "pa");
		if (is_sorted(a.arr, *a.len))
			break ;
		bit++;
	}
}

void	radix_sort(int *a, int n)
{
	int		*b;
	int		len_a;
	int		len_b;
	t_stack	stack_a;
	t_stack	stack_b;

	b = malloc(n * sizeof(int));
	if (!b)
	{
		free(a);
		print_error_and_exit();
	}
	len_a = n;
	len_b = 0;
	stack_a.arr = a;
	stack_a.len = &len_a;
	stack_b.arr = b;
	stack_b.len = &len_b;
	radix_loop(stack_a, stack_b, n);
	free(b);
}
