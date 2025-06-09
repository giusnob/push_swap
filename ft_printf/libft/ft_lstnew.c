/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:39 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:22:26 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(*new_node));
	if (!(new_node))
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* int main(void)
{
	t_list *node;

	// Creazione di un nodo con una stringa come contenuto
	node = ft_lstnew("Hello, World!");
	if (node)
	{
		printf("Test 1:\n");
		printf("Content: %s\n", (char *)node->content);
		printf("Next: %p\n\n", (void *)node->next);
	}
	else
		printf("Errore: allocazione fallita\n");

	// Creazione di un nodo con un intero (passato come puntatore)
	int value = 42;
	node = ft_lstnew(&value);
	if (node)
	{
		printf("Test 2:\n");
		printf("Content: %d\n", *(int *)node->content);
		printf("Next: %p\n", (void *)node->next);
	}
	else
		printf("Errore: allocazione fallita\n");

	return (0);
}
 */