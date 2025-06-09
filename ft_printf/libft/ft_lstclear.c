/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:24 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:12:44 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/* // Funzione per liberare il contenuto (stringa)
void	del_content(void *content)
{
	free(content);
	printf("Contenuto liberato\n");
}

// Funzione per creare un nuovo nodo con una stringa
t_list	*new_node(const char *str)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = strdup(str);
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
	t_list	*node3;

	// Creazione di una lista con 3 nodi
	node1 = new_node("Nodo 1");
	node2 = new_node("Nodo 2");
	node3 = new_node("Nodo 3");

	// Collegamento dei nodi
	node1->next = node2;
	node2->next = node3;
	head = node1;

	// Stampa della lista
	printf("Lista iniziale:\n");
	print_list(head);

	// Chiamata a ft_lstclear
	printf("Eliminazione della lista:\n");
	ft_lstclear(&head, del_content);

	// Verifica che la lista sia vuota
	if (!head)
		printf("La lista è stata eliminata correttamente.\n");

	return (0);
}
 */