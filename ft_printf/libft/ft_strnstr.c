/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:26 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 22:19:29 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_length;

	if (!(*little))
		return ((char *)big);
	little_length = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && (i + little_length) <= len)
	{
		if (ft_strncmp(big + i, little, little_length) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/* int main(void)
{
    const char big[] = "Hello, sono una pera cotta";
    const char little[] = "pe";
    size_t len = 20;

    char *result_ft = ft_strnstr(big, little, len);
    char *result_std = ft_strnstr(big, little, len);

    printf("Stringa: \"%s\"\n", big);
    printf("Sottostringa: \"%s\"\n", little);
    printf("Numero massimo di caratteri: %zu\n\n", len);

    if (result_ft)
        printf("Risultato ft_strnstr: \"%s\"\n", result_ft);
    else
        printf("Risultato ft_strnstr: NULL\n");

    if (result_std)
        printf("Risultato strnstr: \"%s\"\n", result_std);
    else
        printf("Risultato strnstr: NULL\n");

    return (0);
} */