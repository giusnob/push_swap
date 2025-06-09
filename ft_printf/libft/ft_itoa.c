/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:14 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:10:22 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;
	int		sign;

	num = n;
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (num % 10);
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

/* int main(void)
{
    int test_values[] = {0, 123, -123, 2147483647, -2147483648};
    char *result;
    int i;

    printf("Testing ft_itoa:\n");
    for (i = 0; i < 5; i++)
    {
        result = ft_itoa(test_values[i]);
        if (result)
        {
            printf("Input: %d -> Output: \"%s\"\n", test_values[i], result);
            free(result);
        }
        else
            printf("Input: %d -> Error: allocation failed\n", test_values[i]);
    }
    return (0);
}
 */