/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:54 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/15 15:18:02 by ginobile         ###   ########.fr       */
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

void	handle_small(int *a, int *b, int *len_a, int *len_b)
{
	int	idx;
	int	orig;

	if (is_sorted(a, *len_a))
		return ;
	while (*len_a > 3)
	{
		idx = find_min_idx(a, *len_a);
		if (idx <= *len_a / 2)
		{
			while (idx-- > 0)
				ra(a, *len_a);
		}
		else
		{
			orig = *len_a - idx;
			while (orig-- > 0)
				rra(a, *len_a);
		}
		push(a, len_a, b, len_b, "pb");
	}
	sort_three(a);
	while (*len_b > 0)
		push(b, len_b, a, len_a, "pa");
}
