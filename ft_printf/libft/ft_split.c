/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:02 by ginobile          #+#    #+#             */
/*   Updated: 2024/12/17 22:04:47 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_next_word(char const *s, char c, size_t *start)
{
	size_t	end;

	while (s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	return (ft_substr(s, *start, end - *start));
}

static void	free_all(char **result, size_t i)
{
	i--;
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	size_t	start;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(s, c, &start);
		if (!result[i++])
		{
			free_all(result, i);
			return (NULL);
		}
		start += ft_strlen(result[i - 1]);
	}
	result[word_count] = NULL;
	return (result);
}

/* void	print_result(char **result)
{
	int i = 0;

	if (!result)
	{
		printf("Errore: result è NULL\n");
		return;
	}
	while (result[i])
	{
		printf("Parola %d: \"%s\"\n", i, result[i]);
		i++;
	}
}

int main(void)
{
	char **result;

	// Stringa normale con spazi
	result = ft_split("Ciao come stai?", ' ');
	printf("Test 1:\n");
	print_result(result);

	// Libera la memoria
	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	// Stringa con delimitatori consecutivi
	result = ft_split("   Hello    World   !   ", ' ');
	printf("\nTest 2:\n");
	print_result(result);

	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	// Nessuna parola
	result = ft_split("      ", ' ');
	printf("\nTest 3:\n");
	print_result(result);
	free(result);

	// Stringa vuota
	result = ft_split("", ' ');
	printf("\nTest 4:\n");
	print_result(result);
	free(result);

	// Delimitatore che non compare
	result = ft_split("SoloUnaParola", ',');
	printf("\nTest 5:\n");
	print_result(result);

	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	return (0);
}
 */