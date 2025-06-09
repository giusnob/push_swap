/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:07 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:03:30 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tot = nmemb * size;
	if (tot / nmemb != size)
		return (NULL);
	ptr = malloc(tot);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, tot);
	return (ptr);
}

/* int main(void)
{
    size_t nmemb = 5;
    size_t size = sizeof(int);

    int *ft_array = (int *)ft_calloc(nmemb, size);
    if (ft_array == NULL)
        printf("ft_calloc: Allocazione fallita!\n");
    else
    {
        printf("ft_calloc: Memoria allocata e azzerata:\n");
        for (size_t i = 0; i < nmemb; i++)
            printf("Elemento %zu: %d\n", i, ft_array[i]);
    }
    free(ft_array);

    int *std_array = (int *)calloc(nmemb, size);
    if (std_array == NULL)
        printf("calloc: Allocazione fallita!\n");
    else
    {
        printf("\ncalloc: Memoria allocata e azzerata:\n");
        for (size_t i = 0; i < nmemb; i++)
            printf("Elemento %zu: %d\n", i, std_array[i]);
    }
    free(std_array);

    return 0;
}
 */