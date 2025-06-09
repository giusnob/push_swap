#include "push_swap.h"

void    sort_int_array(int *arr, int n)
{
    int i = 0;
    while (i < n - 1)
    {
        int min_idx = i;
        int j = i + 1;

        while (j < n)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            j++;
        }
        if (min_idx != i)
        {
            int tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
        i++;
    }
}
