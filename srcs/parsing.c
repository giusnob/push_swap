/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:35:39 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/18 21:17:37 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*parse_args(int argc, char **argv, int *n)
{
	int	*a;
	int	i;

	if (argc < 2)
		print_error_and_exit();
	*n = argc - 1;
	a = malloc(sizeof(int) * (*n));
	if (!a)
		print_error_and_exit();
	i = 0;
	while (i < *n)
	{
		if (!is_integer(argv[i + 1]))
		{
			free(a);
			print_error_and_exit();
		}
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (a);
}

static void	check_duplicates(int *a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[i] == a[j])
				print_error_and_exit();
			j++;
		}
		i++;
	}
}

static void	compress_indices(int *a, int n)
{
	int	*s;
	int	i;
	int	j;

	s = malloc(sizeof(int) * n);
	if (!s)
		print_error_and_exit();
	i = 0;
	while (i < n)
	{
		s[i] = a[i];
		i++;
	}
	sort_int_array(s, n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n && a[i] != s[j])
			j++;
		if (j != n)
			a[i] = j;
		i++;
	}
	free(s);
}

int	*parse_and_index(int argc, char **argv, int *n)
{
	int	*a;

	a = parse_args(argc, argv, n);
	check_duplicates(a, *n);
	compress_indices(a, *n);
	return (a);
}
