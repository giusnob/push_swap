/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:49:58 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/08 20:37:45 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

static void    print_error_and_exit(void)
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

static bool    is_integer(const char *str)
{
    long    val;
    int     sign;
    size_t  i;

    val = 0;
    sign = 1;
    i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        return (false);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        val = val * 10 + (str[i] - '0');
        if ((sign == 1 && val > INT_MAX) ||
            (sign == -1 && val > (long)INT_MAX + 1))
            return (false);
        i++;
    }
    return (true);
}

static void    sa(int *arr)
{
    int tmp;

    tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
    ft_putendl_fd("sa", 1);
}

static void    ra(int *arr, int n)
{
    int tmp;
    int i;

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

static void    rra(int *arr, int n)
{
    int tmp;
    int i;

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

static void    push(int *src, int *slen, int *dst, int *dlen, char *op)
{
    int i;

    dst[*dlen] = src[0];
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

static int    find_min_idx(int *arr, int n)
{
    int min_idx;
    int i;

    min_idx = 0;
    i = 1;
    while (i < n)
    {
        if (arr[i] < arr[min_idx])
            min_idx = i;
        i++;
    }
    return (min_idx);
}

static void    handle_small(int *A, int n)
{
    int *B;
    int nb;

    B = malloc(n * sizeof(int));
    if (!B)
        print_error_and_exit();
    nb = 0;
    if (n == 2)
    {
        if (A[0] > A[1])
            sa(A);
    }
    else if (n == 3)
    {
        int a = A[0], b = A[1], c = A[2];

        if (a > b && b < c && a < c)
            sa(A);
        else if (a > b && b > c)
        {
            sa(A);
            rra(A, 3);
        }
        else if (a > b && b < c && a > c)
            ra(A, 3);
        else if (a < b && b > c && a < c)
        {
            sa(A);
            ra(A, 3);
        }
        else if (a < b && b > c && a > c)
            rra(A, 3);
    }
    else
    {
        while (n > 3)
        {
            int idx = find_min_idx(A, n);

            if (idx <= n / 2)
                while (idx--)
                    ra(A, n);
            else
                while (idx++ < n)
                    rra(A, n);
            push(A, &n, B, &nb, "pb");
        }
        handle_small(A, 3);
        while (nb--)
            push(B, &nb, A, &n, "pa");
    }
    free(B);
}

static void    sort_int_array(int *arr, int n)
{
    int i;
    int min_idx;
    int j;
    int tmp;

    i = 0;
    while (i < n - 1)
    {
        min_idx = i;
        j = i + 1;
        while (j < n)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            j++;
        }
        if (min_idx != i)
        {
            tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
        i++;
    }
}

int    main(int argc, char **argv)
{
    int n;
    int *A;
    int i;

    if (argc < 2)
        return (0);
    n = argc - 1;
    A = malloc(n * sizeof(int));
    if (!A)
        print_error_and_exit();
    i = 0;
    while (i < n)
    {
        if (!is_integer(argv[i + 1]))
        {
            free(A);
            print_error_and_exit();
        }
        A[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        int j;

        j = i + 1;
        while (j < n)
        {
            if (A[i] == A[j])
            {
                free(A);
                print_error_and_exit();
            }
            j++;
        }
        i++;
    }
    {
        int *S;

        S = malloc(n * sizeof(int));
        if (!S)
        {
            free(A);
            print_error_and_exit();
        }
        i = 0;
        while (i < n)
        {
            S[i] = A[i];
            i++;
        }
        sort_int_array(S, n);
        i = 0;
        while (i < n)
        {
            int j;

            j = 0;
            while (j < n)
            {
                if (A[i] == S[j])
                {
                    A[i] = j;
                    break;
                }
                j++;
            }
            i++;
        }
        free(S);
    }
    if (n <= 5)
    {
        handle_small(A, n);
        free(A);
        return (0);
    }
    {
        int *B;
        int lenA;
        int lenB;
        int max_bits;
        int tmp;
        int bit;
        int count;
        int j;

        lenA = n;
        lenB = 0;
        tmp = n - 1;
        max_bits = 0;
        while ((tmp >> max_bits) != 0)
            max_bits++;
        B = malloc(n * sizeof(int));
        if (!B)
        {
            free(A);
            print_error_and_exit();
        }
        bit = 0;
        while (bit <= max_bits)
        {
            count = lenA;
            j = 0;
            while (j < count)
            {
                if (((A[0] >> bit) & 1) == 0)
                    push(A, &lenA, B, &lenB, "pb");
                else
                    ra(A, lenA);
                j++;
            }
            while (lenB > 0)
                push(B, &lenB, A, &lenA, "pa");
            bit++;
        }
        free(B);
    }
    free(A);
    return (0);
}
