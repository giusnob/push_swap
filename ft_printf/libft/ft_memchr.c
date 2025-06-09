/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:12:50 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:25:50 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	unscha;
	size_t			i;

	buff = (unsigned char *)s;
	unscha = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (buff[i] == unscha)
			return ((void *)&buff[i]);
		i++;
	}
	return (NULL);
}

/* int main(void)
{
    char str[] = "Hello, world!";
    char c = 'o';
    size_t n = 10;

    char *result_ft = (char *)ft_memchr(str, c, n);
    char *result_std = (char *)memchr(str, c, n);

    printf("Stringa: \"%s\"\n", str);
    printf("Carattere cercato: '%c', Numero di byte: %zu\n\n", c, n);

    if (result_ft)
        printf("ft_memchr: '%c' posizione: %ld\n", *result_ft, result_ft - str);
    else
        printf("Risultato ft_memchr: Carattere non trovato\n");

    if (result_std)
        printf("memchr: '%c' posizione: %ld\n", *result_std, result_std - str);
    else
        printf("Risultato memchr: Carattere non trovato\n");

    return 0;
}
 */