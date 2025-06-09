/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:31 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 22:22:46 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	beg;
	unsigned int	s1_length;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	s1_length = ft_strlen(s1);
	while (s1[beg] && chr_in_set(s1[beg], set))
		beg++;
	while (s1_length > beg && chr_in_set(s1[s1_length - 1], set))
		s1_length--;
	return (ft_substr(s1, beg, s1_length - beg));
}

/* int main(void)
{
    char const *s1 = "   Hello, World!   ";
    char const *set = " ";
    char *result;

    // Rimuovere spazi bianchi
    result = ft_strtrim(s1, set);
    printf("Input: \"%s\"\nSet: \"%s\"\nOutput: \"%s\"\n\n", s1, set, result);
    free(result);

    // Nessun carattere da rimuovere
    s1 = "Hello";
    set = " ";
    result = ft_strtrim(s1, set);
    printf("Input: \"%s\"\nSet: \"%s\"\nOutput: \"%s\"\n\n", s1, set, result);
    free(result);

    // Stringa vuota
    s1 = "";
    set = " ";
    result = ft_strtrim(s1, set);
    printf("Input: \"%s\"\nSet: \"%s\"\nOutput: \"%s\"\n\n", s1, set, result);
    free(result);

    // Stringa piena di caratteri da rimuovere
    s1 = "xxxHello, World!xxx";
    set = "x";
    result = ft_strtrim(s1, set);
    printf("Input: \"%s\"\nSet: \"%s\"\nOutput: \"%s\"\n\n", s1, set, result);
    free(result);

    return (0);
}
 */