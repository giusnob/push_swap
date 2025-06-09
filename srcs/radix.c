#include "push_swap.h"

void    radix_sort(int *A, int n)
{
    int *B = malloc(n * sizeof(int));
    int lenA = n;
    int lenB = 0;
    int max_rank = 0;
    int bit = 0;
    int i;

    if (!B)
        print_error_and_exit();
    i = 0;
    while (i < n)
        if (A[i++] > max_rank)
            max_rank = A[i - 1];
    while ((max_rank >> bit) != 0)
    {
        int count = lenA;
        int j = 0;

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
        if (is_sorted(A, lenA))
            break;
        bit++;
    }
    free(B);
}

