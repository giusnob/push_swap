/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:52 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 22:02:52 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// int main(void)
// {
//     int fd;

//     // Scrittura su stdout
//     printf("Test 1: Scrittura su stdout -> ");
//     ft_putendl_fd("Hello, World!", 1);

//     // Scrittura su un file
//     fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd == -1)
//     {
//         perror("Error: open failed");
//         return (1);
//     }
//     printf("Test 2: Scrittura su file 'output.txt'\n");
//     ft_putendl_fd("Ciao, file!", fd);
//     close(fd);

//     // Scrittura con fd negativo
//     printf("Test 3: Scrittura con fd negativo -> ");
//     ft_putendl_fd("Non dovresti vedere questo!", -1);

//     // Scrittura con stringa NULL
//     printf("Test 4: Scrittura con stringa NULL -> ");
//     ft_putendl_fd(NULL, 1);

//     return (0);
// }
