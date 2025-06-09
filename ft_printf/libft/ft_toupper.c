/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:06:51 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 19:58:14 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

/* int	main(void)
{
	printf("toupper('a'):%c\n", ft_toupper('a'));
	printf("toupper('A'):%c\n", ft_toupper('A'));
	printf("toupper('b'):%c\n", ft_toupper('b'));
}
 */