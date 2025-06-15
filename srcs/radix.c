/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:43 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/15 15:16:53 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(int *a, int n)
{
	int	*b;
	int	len_a;
	int	len_b;
	int	max_rank;
	int	bit;
	int	i;

	b = malloc(n * sizeof(int));
	if (!b)
		print_error_and_exit();
	len_a = n;
	len_b = 0;
	max_rank = 0;
	i = 0;
	while (i < n)
	{
		if (a[i] > max_rank)
			max_rank = a[i];
		i++;
	}
	bit = 0;
	while ((max_rank >> bit) != 0)
	{
		int	count;
		int	j;

		count = len_a;
		j = 0;
		while (j < count)
		{
			if (((a[0] >> bit) & 1) == 0)
				push(a, &len_a, b, &len_b, "pb");
			else
				ra(a, len_a);
			j++;
		}
		while (len_b > 0)
			push(b, &len_b, a, &len_a, "pa");
		if (is_sorted(a, len_a))
			break ;
		bit++;
	}
	free(b);
}
