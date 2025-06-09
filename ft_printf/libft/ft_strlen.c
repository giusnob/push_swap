/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:34:14 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 21:42:36 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		++len;
	return (len);
}

/* int main(int ac, char **av)
{
	if (ac == 1)
	{}
	printf("%ld", ft_strlen(av[1]));
}
 */