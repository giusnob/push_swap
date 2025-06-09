/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:29 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:13:46 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* // Funzione per stampare il contenuto
void	print_content(void *content)
{
	printf("Contenuto: %s\n", (char *)content);
}

// Funzione per creare un nuovo nodo
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

// Funzione per stampare la lista (debug)
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

	// Stampa della lista iniziale
	printf("Lista iniziale:\n");
	print_list(head);

	// Applicazione di ft_lstiter
	printf("\nApplicazione di ft_lstiter (stampa contenuto):\n");
	ft_lstiter(head, print_content);

	// Libera la memoria
	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);

	return (0);
}
 */