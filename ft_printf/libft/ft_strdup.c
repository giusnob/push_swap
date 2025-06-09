/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:07 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 20:08:29 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
    const char *test_cases[] = {
        "Hello, World!",
        "",
        "42 Firenze!",
        "A string with spaces",
        "1234567890",
        NULL
    };

    int i = 0;
    while (test_cases[i] != NULL)
    {
        char *ft_result = ft_strdup(test_cases[i]);
        char *std_result = strdup(test_cases[i]);

        printf("Input: \"%s\"\n", test_cases[i]);
        printf("ft_strdup: \"%s\"\n", ft_result);
        printf("strdup: \"%s\"\n\n", std_result);

        free(ft_result);
        free(std_result);
        i++;
    }
    return (0);
}
 */