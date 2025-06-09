/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:56:37 by ginobile          #+#    #+#             */
/*   Updated: 2024/11/21 19:22:40 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

/*
int main()
{
    // Test case 1: Moving a string in non-overlapping memory regions
    char str1[20] = "Hello, World!";
    ft_memmove(str1 + 7, str1, 6);  // Move "Hello," to start at index 7
    printf("After ft_memmove (non-overlapping): %s\n", str1);

    // Test case 2: Moving in overlapping memory regions
	(copying part of the string over itself)
    char str2[20] = "Hello, World!";
    ft_memmove(str2 + 5, str2, 6);
	// Overlapping move: "Hello," -> starting at index 5
    printf("After ft_memmove (overlapping): %s\n", str2);

    // Test case 3: No movement, same destination and source
    char str3[20] = "No Move Here!";
    ft_memmove(str3, str3, 0);  // No change
    printf("After ft_memmove (zero length): %s\n", str3);

    // Test case 4: Move from NULL source or destination
    ft_memmove(NULL, NULL, 10);  // Should not crash
    printf("ft_memmove with NULL source/destination executed without crash.\n");

    return 0;
}
 */