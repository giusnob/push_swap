/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:32 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 19:28:49 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* // Funzione per creare un nuovo nodo
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
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last;

	// Creazione di una lista con 3 nodi
	node1 = new_node("Nodo 1");
	node2 = new_node("Nodo 2");
	node3 = new_node("Nodo 3");

	// Collegamento dei nodi
	node1->next = node2;
	node2->next = node3;

	// Test della funzione ft_lstlast
	last = ft_lstlast(node1);
	if (last)
		printf("L'ultimo nodo contiene: %s\n", (char *)last->content);
	else
		printf("La lista è vuota.\n");

	// Test con una lista vuota
	last = ft_lstlast(NULL);
	if (!last)
		printf("Test lista vuota: restituisce NULL correttamente.\n");

	// Pulizia della memoria
	free(node1);
	free(node2);
	free(node3);

	return (0);
}
 */