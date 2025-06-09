#include "push_swap.h"

int main(int argc, char **argv)
{
    int *A;
    int *B;
    int  n;
    int  lenA;
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

