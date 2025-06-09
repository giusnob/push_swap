/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:59 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 21:41:08 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

/* int main(void)
{
    int fd;

    // Scrittura su stdout
    printf("Test 1: Scrittura su stdout -> ");
    ft_putstr_fd("Hello, World!\n", 1);

    // Scrittura su un file
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error: open failed");
        return (1);
    }
    printf("Test 2: Scrittura su file 'output.txt'\n");
    ft_putstr_fd("Ciao, file!\n", fd);
    close(fd);

    // Scrittura con fd negativo
    printf("Test 3: Scrittura con fd negativo -> ");
    ft_putstr_fd("Non dovresti vedere questo!\n", -1);

    // Scrittura con stringa NULL
    printf("Test 4: Scrittura con stringa NULL -> ");
    ft_putstr_fd(NULL, 1);

    return (0);
}
 */