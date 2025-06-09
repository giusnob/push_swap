#include "push_swap.h"

static void sort_three(int *A)
{
    if (A[0] > A[1] && A[1] < A[2] && A[0] < A[2])
        sa(A);
    else if (A[0] > A[1] && A[1] > A[2])
    {
        sa(A);
        rra(A, 3);
    }
    else if (A[0] > A[1] && A[1] < A[2])
        ra(A, 3);
    else if (A[0] < A[1] && A[1] > A[2] && A[0] < A[2])
    {
        sa(A);
        ra(A, 3);
    }
    else if (A[0] < A[1] && A[1] > A[2])
        rra(A, 3);
}

void handle_small(int *A, int *B, int *lenA, int *lenB)
{
    int idx;
    int	orig;

    /* se per sbaglio venisse chiamata su array già sorted */
    if (is_sorted(A, *lenA))
        return;

    /* spingi i minimi finché rimangono 3 in A */
    while (*lenA > 3)
    {
        idx = find_min_idx(A, *lenA);
        if (idx <= *lenA / 2)
        {
            while (idx-- > 0)
                ra(A, *lenA);
        }
        else
        {
            orig = *lenA - idx;
            while (orig-- > 0)
                rra(A, *lenA);
        }
        push(A, lenA, B, lenB, "pb");
    }
    /* ordina i 3 restanti */
    sort_three(A);

    /* rimetti indietro tutto da B */
    while (*lenB > 0)
        push(B, lenB, A, lenA, "pa");
}

