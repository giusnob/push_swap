/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:03 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 20:55:31 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	n;
	int	len_a;
	int	len_b;

	a = parse_and_index(argc, argv, &n);
	if (is_sorted(a, n))
		return (free(a), 0);
	b = malloc(sizeof(int) * n);
	if (!b)
	{
		free(a);
		print_error_and_exit();
	}
	len_a = n;
	len_b = 0;
	if (n <= 5)
		return (handle_small(a, b, &len_a, &len_b), free(b), free(a), 0);
	radix_sort(a, n);
	return (free(b), free(a), 0);
}
