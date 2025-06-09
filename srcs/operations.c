#include "push_swap.h"

void    sa(int *arr)
{
    int tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
    ft_putendl_fd("sa", 1);
}

void    ra(int *arr, int n)
{
    int tmp;
    int i;

    if (n <= 1)
        return;

    tmp = arr[0];
    i = 0;
    while (i < n - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    while (i + 1 < n)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    arr[n - 1] = tmp;
    ft_putendl_fd("ra", 1);
}

void    rra(int *arr, int n)
{
    int tmp = arr[n - 1];
    int i = n - 1;

    while (i > 0)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[0] = tmp;
    ft_putendl_fd("rra", 1);
}

void    push(int *src, int *slen, int *dst, int *dlen, char *op)
{
    int i;
    int orig;

    if (*slen <= 0)
        return;

    /* spingi il top di src su dst */
    dst[*dlen] = src[0];
    (*dlen)++;

    /* shift dst verso destra e inserisci src[0] in testa */
    i = *dlen;
    while (i > 0)
    {
        dst[i] = dst[i - 1];
        i--;
    }
    dst[0] = src[0];
    (*dlen)++;

    /* shift left di src */
    i = 0;
    while (i < *slen - 1)
    {
        src[i] = src[i + 1];
        i++;
    }
    (*slen)--;
    orig = *slen;
    i = 0;
    while (i + 1 < orig)
    {
        src[i] = src[i +1];
        i++;
    }
    *slen = orig - 1;
    i = 0;
    while (i + 1 < *slen)
    {
        src[i] = src[i + 1];
        i++;
    }
    (*slen)--;

    ft_putendl_fd(op, 1);
}

