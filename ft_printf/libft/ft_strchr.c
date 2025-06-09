/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:50:03 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 20:29:20 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* #include <string.h>
int	main(void)
{
	printf("Trova 'o' in 'Hello': %s\n", ft_strchr("Hello", 'o'));
	printf("Trova 'z' in 'Hello': %s\n", ft_strchr("Hello", 'z'));
} */
