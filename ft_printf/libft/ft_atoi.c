/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:02 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:01:51 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsign(int c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	z;
	int	sign;

	i = 0;
	z = 0;
	sign = 1;
	while (ft_isspace(nptr[z]))
		z++;
	if (nptr[z] == '-' || nptr[z] == '+')
	{
		sign = ft_getsign(nptr[z]);
		z++;
	}
	while (nptr[z] >= '0' && nptr[z] <= '9')
	{
		i = i * 10 + (nptr[z] - '0');
		z++;
	}
	return (i * sign);
}

/* int	main(void)
{
    const char *test_cases[] = {
        "42",
        "   -42",
        "   +42",
        "4193 with words",
        "words and 987",
        "-2147483648",
        "2147483647",
        "9223372036854775807", // Overflow
        "",
        "0",
        NULL
    };

    int i = 0;
    while (test_cases[i] != NULL)
    {
        printf("Input: \"%s\"\n", test_cases[i]);
        printf("ft_atoi: %d | atoi: %d\n\n", ft_atoi(test_cases[i]));
        i++;
    }
    return 0;
} */
