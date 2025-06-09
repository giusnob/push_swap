/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:36 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:22:03 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*p;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		p = f(lst->content);
		new_elem = ft_lstnew(p);
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			del(p);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

/* // Funzione per trasformare il contenuto (duplica la stringa)
void	*duplicate_content(void *content)
{
	return (strdup((char *)content));
}

// Funzione per liberare il contenuto
void	delete_content(void *content)
{
	free(content);
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
	t_list	*new_list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Creazione di una lista originale
	node1 = new_node("Ciao");
	node2 = new_node("Mondo");
	node3 = new_node("Bella!");

	node1->next = node2;
	node2->next = node3;
	head = node1;

	// Stampa della lista originale
	printf("Lista originale:\n");
	print_list(head);

	// Applicazione di ft_lstmap
	new_list = ft_lstmap(head, duplicate_content, delete_content);

	// Stampa della nuova lista
	printf("\nNuova lista dopo ft_lstmap:\n");
	print_list(new_list);

	// Pulizia della memoria
	ft_lstclear(&head, delete_content);
	ft_lstclear(&new_list, delete_content);

	return (0);
}
 */