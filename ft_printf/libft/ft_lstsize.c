/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:42 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:22:50 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* // Funzione per creare un nuovo nodo (semplificata)
t_list	*new_node(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Creazione di una lista con 3 nodi
	node1 = new_node("Nodo 1");
	node2 = new_node("Nodo 2");
	node3 = new_node("Nodo 3");

	// Collegamento dei nodi
	node1->next = node2;
	node2->next = node3;
	head = node1;

	// Test della funzione ft_lstsize
	printf("Numero di nodi nella lista: %d\n", ft_lstsize(head));

	// Test con una lista vuota
	printf("Lista vuota: %d\n", ft_lstsize(NULL));

	// Libera la memoria allocata
	free(node1);
	free(node2);
	free(node3);

	return (0);
}
  */