/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:45:13 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 19:58:20 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

/* int	main(void)
{
	printf("tolower('a'):%c\n", ft_tolower('a'));
	printf("tolower('A'):%c\n", ft_tolower('A'));
	printf("tolower('b'):%c\n", ft_tolower('b'));
}
 */