/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:43:59 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/08 20:49:16 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

/* Parsing, validazione, compressione dei valori in A[0..n-1] */
int    *parse_and_index(int argc, char **argv, int *n);

/* Utility functions */
void    print_error_and_exit(void);
bool    is_integer(const char *str);
bool    is_sorted(int *arr, int n);
int     find_min_idx(int *arr, int n);

/* Primitive operations */
void    sa(int *arr);
void    ra(int *arr, int n);
void    rra(int *arr, int n);
void    push(int *src, int *slen, int *dst, int *dlen, char *op);

/* Small-case handler */
void    handle_small(int *A, int *B, int *lenA, int *lenB);

/* Selection sort for coordinate compression */
void    sort_int_array(int *arr, int n);
void    radix_sort(int *A, int n);

#endif // PUSH_SWAP_H
