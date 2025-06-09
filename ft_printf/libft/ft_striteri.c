/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:10 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 22:06:19 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/* // Funzione per convertire i caratteri in maiuscolo
void	to_uppercase(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

// Funzione per aggiungere l'indice come valore ASCII al carattere
void	add_index(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char str1[] = "ciao mondo";
	char str2[] = "abcdef";

	printf("Stringa originale 1: \"%s\"\n", str1);
	ft_striteri(str1, to_uppercase);
	printf("Dopo ft_striteri con to_uppercase: \"%s\"\n", str1);

	printf("\nStringa originale 2: \"%s\"\n", str2);
	ft_striteri(str2, add_index);
	printf("Dopo ft_striteri con add_index: \"%s\"\n", str2);

	// Con s NULL
	ft_striteri(NULL, to_uppercase);
	printf("\nTest con stringa NULL completato senza crash.\n");

	return (0);
}
 */