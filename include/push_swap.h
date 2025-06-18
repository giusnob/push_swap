/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:43:59 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 21:10:04 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*arr;
	int	*len;
}				t_stack;

/* typedef struct s_iter
{
	int			i;
	int			sign;
	long long	num;
}				t_iter; */

// Parsing, validazione, compressione dei valori in A[0..n-1]
int		*parse_and_index(int argc, char **argv, int *n);

// Utility functions
void	print_error_and_exit(void);
bool	is_integer(const char *str);
bool	is_sorted(int *arr, int n);
int		find_min_idx(int *arr, int n);

// Primitive operations
void	sa(int *arr);
void	ra(int *arr, int n);
void	rra(int *arr, int n);
void	push(t_stack src, t_stack dst, char *op);

// Small-case handler
void	handle_small(int *a, int *b, int *len_a, int *len_b);

// Selection sort for coordinate compression
void	sort_int_array(int *arr, int n);
void	radix_sort(int *a, int n);

// void	radix_loop(t_stack a, t_stack b);

#endif