/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:18 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/19 19:37:58 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
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

// Funzione per stampare la lista
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*new;

	// Creazione dei nodi iniziali
	node1 = new_node("Node 1");
	node2 = new_node("Node 2");

	// Collegamento dei nodi
	node1->next = node2;
	head = node1;

	// Stampa della lista iniziale
	printf("Lista iniziale:\n");
	print_list(head);

	// Creazione del nuovo nodo da aggiungere
	new = new_node("Node 3");

	// Aggiunta del nodo alla fine
	ft_lstadd_back(&head, new);

	// Stampa della lista dopo l'aggiunta
	printf("Lista dopo ft_lstadd_back:\n");
	print_list(head);

	// Test con una lista vuota
	printf("Aggiunta a una lista vuota:\n");
	t_list *empty = NULL;
	ft_lstadd_back(&empty, new_node("First Node"));
	print_list(empty);

	// Libera la memoria allocata
	free(node1);
	free(node2);
	free(new);
	free(empty);

	return (0);
} */