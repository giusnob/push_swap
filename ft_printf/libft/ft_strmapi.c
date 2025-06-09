/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:21 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 22:18:40 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* // Funzione che trasforma maiuscolo se dispari, minuscolo se pari
char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	else
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
	}
	return (c);
}

int main(void)
{
    char *s = "HeLLo WoRLd!";
    char *result;

    printf("Stringa originale: \"%s\"\n", s);

    // Applicazione della funzione di trasformazione
    result = ft_strmapi(s, to_upper_even);
    if (result)
    {
        printf("Stringa trasformata: \"%s\"\n", result);
        free(result);
    }
    else
        printf("Errore: allocazione fallita\n");

    // Input NULL
    result = ft_strmapi(NULL, to_upper_even);
    if (result == NULL)
        printf("Test con s NULL: Funzione ha restituito NULL\n");

    // Funzione NULL
    result = ft_strmapi(s, NULL);
    if (result == NULL)
        printf("Test con f NULL: Funzione ha restituito NULL\n");

    return (0);
}
 */