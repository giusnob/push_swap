/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:14 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 22:06:46 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(len_s1 + len_s2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcat(result, s2, len_s1 + len_s2 + 1);
	return (result);
}

/* 
int main(void)
{
    const char *s1 = "Hello, ";
    const char *s2 = "";
    char *result;
	printf("%s", ft_strjoin(s1, s2));

    // Concatenazione normale
    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("Test 1: \"%s\" + \"%s\" = \"%s\"\n", s1, s2, result);
        free(result);
    }
    else
        printf("Test 1: Errore nell'allocazione della memoria\n");

    // s1 vuota
    result = ft_strjoin("", s2);
    if (result)
    {
        printf("Test 2: \"\" + \"%s\" = \"%s\"\n", s2, result);
        free(result);
    }

    // s2 vuota
    result = ft_strjoin(s1, "");
    if (result)
    {
        printf("Test 3: \"%s\" + \"\" = \"%s\"\n", s1, result);
        free(result);
    }

    // Entrambe le stringhe vuote
    result = ft_strjoin("", "");
    if (result)
    {
        printf("Test 4: \"\" + \"\" = \"%s\"\n", result);
        free(result);
    }

    // Uno dei parametri è NULL
    result = ft_strjoin(NULL, s2);
    if (result == NULL)
        printf("Test 5: Uno dei parametri è NULL -> NULL\n");

    result = ft_strjoin(s1, NULL);
    if (result == NULL)
        printf("Test 5: Uno dei parametri è NULL -> NULL\n");

    return (0);
}
 */