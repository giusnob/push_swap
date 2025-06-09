/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:12:55 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:26:30 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	buffer1 = (unsigned char *)s1;
	buffer2 = (unsigned char *)s2;
	while (n)
	{
		if (*buffer1 != *buffer2)
			return ((int)(*buffer1 - *buffer2));
		n--;
		buffer1++;
		buffer2++;
	}
	return (0);
}

/* int main(void)
{
    char s1[] = "Hello, world!";
    char s2[] = "Hello, wOrld!";
    size_t n = 10;

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Blocchi di memoria: \"%s\" e \"%s\"\n", s1, s2);
    printf("Numero di byte confrontati: %zu\n", n);
    printf("Risultato ft_memcmp: %d\n", result_ft);
    printf("Risultato memcmp: %d\n", result_std);

    return 0;
}
 */