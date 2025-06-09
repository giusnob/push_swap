/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:55 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 21:58:42 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	if (fd < 0)
		return ;
	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	ft_putchar_fd(c, fd);
}

// int main(void)
// {
//     int fd;

//     // Scrittura su stdout
//     printf("Test 1: Scrittura su stdout -> ");
//     ft_putnbr_fd(12345, 1);
//     ft_putchar_fd('\n', 1);

//     // Scrittura di un numero negativo
//     printf("Test 2: Numero negativo -> ");
//     ft_putnbr_fd(-6789, 1);
//     ft_putchar_fd('\n', 1);

//     // Scrittura di INT_MIN
//     printf("Test 3: INT_MIN -> ");
//     ft_putnbr_fd(INT_MIN, 1);
//     ft_putchar_fd('\n', 1);

//     // Scrittura di INT_MAX
//     printf("Test 4: INT_MAX -> ");
//     ft_putnbr_fd(INT_MAX, 1);
//     ft_putchar_fd('\n', 1);

//     // Scrittura su file
//     fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd == -1)
//     {
//         perror("Error: open failed");
//         return (1);
//     }
//     printf("Test 5: Scrittura su file 'output.txt'\n");
//     ft_putnbr_fd(42, fd);
//     close(fd);

//     // File descriptor negativo
//     printf("Test 6: File descriptor negativo -> ");
//     ft_putnbr_fd(123, -1);
//     printf("Nessuna scrittura effettuata.\n");

//     return (0);
// }
