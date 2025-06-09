/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:49 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 20:44:25 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/* int main(void)
{
    int fd;

    // Scrittura su stdout
    printf("Test 1: Scrittura su stdout -> ");
    ft_putchar_fd('A', 1);
    printf("\n");

    // Scrittura su un file
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error: open failed");
        return (1);
    }
    printf("Test 2: Scrittura su file 'output.txt'\n");
    ft_putchar_fd('B', fd);
    close(fd);

    // File descriptor negativo
    printf("Test 3: File descriptor negativo -> ");
    ft_putchar_fd('C', -1);
    printf("Nessuna scrittura effettuata.\n");

    // Scrittura con fd chiuso
    printf("Test 4: Scrittura con fd chiuso -> ");
    ft_putchar_fd('D', fd); // fd è già stato chiuso
    printf("Se 'write' fallisce, stampa un messaggio di errore.\n");

    return (0);
}
 */