/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:13:27 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 21:13:24 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
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
	node->content = strdup(str); // Duplica la stringa per il contenuto
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*node;

	// Creazione di un nodo
	node = new_node("Ciao, mondo!");
	if (!node)
	{
		printf("Errore: allocazione nodo fallita\n");
		return (1);
	}

	// Stampa del contenuto del nodo
	printf("Contenuto del nodo: %s\n", (char *)node->content);

	// Eliminazione del nodo
	ft_lstdelone(node, del_content);

	return (0);
}
 */