/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:34 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 22:37:50 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (len < sub_len)
		sub_len = len;
	substr = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, sub_len + 1);
	return (substr);
}
/* 
#include <stdio.h>

int main(void)
{
    const char *str = "42 Firenze!";
    char *result;

    // Sottostringa valida
    result = ft_substr(str, 3, 7);
    printf("Test 1: \"%s\" -> \"%s\"\n", str, result);
    free(result);

    // Start oltre la lunghezza della stringa
    result = ft_substr(str, 20, 5);
    printf("Test 2: \"%s\" -> \"%s\"\n", str, result);
    free(result);

    // Estrarre un'intera stringa
    result = ft_substr(str, 0, ft_strlen(str));
    printf("Test 3: \"%s\" -> \"%s\"\n", str, result);
    free(result);

    // Estrarre con len maggiore dei caratteri disponibili
    result = ft_substr(str, 5, 20);
    printf("Test 4: \"%s\" -> \"%s\"\n", str, result);
    free(result);

    // Stringa vuota
    result = ft_substr("", 0, 5);
    printf("Test 5: \"%s\" -> \"%s\"\n", "", result);
    free(result);

    return 0;
}
 */