/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:51:03 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/12 15:51:33 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int *A;
    int *B;
    int  n;
    int  lenA;./push_swap 3 2 1 0 | ./checker_linux 3 2 1 0
    int  lenB;

    A = parse_and_index(argc, argv, &n);
    if (is_sorted(A, n))
    {
        free(A);
        return (0);
    }
    B = malloc(sizeof(int) * n);
    if (!B)
        print_error_and_exit();
    lenA = n;
    lenB = 0;
    if (n <= 5)
    {
        handle_small(A, B, &lenA, &lenB);
        free(B);
        free(A);
        return (0);
    }
    radix_sort(A, n);
    free(B);
    free(A);
    return (0);
}

