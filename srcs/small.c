/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:54 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 20:47:25 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(int *a)
{
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(a);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		sa(a);
		rra(a, 3);
	}
	else if (a[0] > a[1] && a[1] < a[2])
		ra(a, 3);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(a);
		ra(a, 3);
	}
	else if (a[0] < a[1] && a[1] > a[2])
		rra(a, 3);
}

static void	push_min_to_b(t_stack stack_a, t_stack stack_b)
{
	int	idx;
	int	orig;

	while (*stack_a.len > 3)
	{
		idx = find_min_idx(stack_a.arr, *stack_a.len);
		if (idx <= *stack_a.len / 2)
		{
			while (idx-- > 0)
				ra(stack_a.arr, *stack_a.len);
		}
		else
		{
			orig = *stack_a.len - idx;
			while (orig-- > 0)
				rra(stack_a.arr, *stack_a.len);
		}
		push(stack_a, stack_b, "pb");
	}
}

static void	finish_small(t_stack stack_a, t_stack stack_b)
{
	sort_three(stack_a.arr);
	while (*stack_b.len > 0)
		push(stack_b, stack_a, "pa");
}

void	handle_small(int *a, int *b, int *len_a, int *len_b)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.arr = a;
	stack_a.len = len_a;
	stack_b.arr = b;
	stack_b.len = len_b;
	if (is_sorted(a, *len_a))
		return ;
	if (*(len_a) == 2)
	{
		sa(a);
		return ;
	}
	push_min_to_b(stack_a, stack_b);
	finish_small(stack_a, stack_b);
}
