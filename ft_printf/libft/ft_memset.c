/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:27:52 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 19:59:34 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr++ = (unsigned char)c;
	}
	return (b);
}

/* int main()
{
	char buffer[10] = "abcdefghi";
	ft_memset(buffer, 'x', 3);
	printf("Buffer dopo memset: %s\n", buffer);
	return (0);
} */