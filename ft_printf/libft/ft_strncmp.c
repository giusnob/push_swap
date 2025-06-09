/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:41:03 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 19:58:45 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* int main(void)
{
    int result_ft;
    int result_std;

    printf("=== Test 1: Stringhe identiche ===\n");
    result_ft = ft_strncmp("hello", "hello", 5);
    result_std = strncmp("hello", "hello", 5);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 2: Stringhe diverse ===\n");
    result_ft = ft_strncmp("hello", "world", 5);
    result_std = strncmp("hello", "world", 5);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 3: Confronto parziale (n = 3) ===\n");
    result_ft = ft_strncmp("hello", "hellz", 3);
    result_std = strncmp("hello", "hellz", 3);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 4: Prima stringa più corta ===\n");
    result_ft = ft_strncmp("hi", "hello", 5);
    result_std = strncmp("hi", "hello", 5);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 5: Seconda stringa più corta ===\n");
    result_ft = ft_strncmp("hello", "hi", 5);
    result_std = strncmp("hello", "hi", 5);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 6: Una stringa vuota ===\n");
    result_ft = ft_strncmp("hello", "", 5);
    result_std = strncmp("hello", "", 5);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 7: Entrambe le stringhe vuote ===\n");
    result_ft = ft_strncmp("", "", 5);
    result_std = strncmp("", "", 5);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 8: n = 0 (nessun confronto) ===\n");
    result_ft = ft_strncmp("hello", "world", 0);
    result_std = strncmp("hello", "world", 0);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    printf("\n=== Test 9: Caratteri speciali ===\n");
    result_ft = ft_strncmp("hello", "heLlo", 5);
    result_std = strncmp("hello", "heLlo", 5);
    printf("ft_strncmp: %d | strncmp: %d\n", result_ft, result_std);

    return (0);
}
 */