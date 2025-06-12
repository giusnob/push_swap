/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:52:13 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/12 15:52:15 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	print_error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

bool	is_integer(const char *str)
{
	long	n;
	int		i;

	if (!str || !*str)
		return (false);
	i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	n = ft_atoi(str);
	if (n < INT_MIN || n > INT_MAX)
		return (false);
	return (true);
}

bool	is_sorted(int *arr, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (arr[i - 1] > arr[i])
			return (false);
		i++;
	}
	return (true);
}

int	find_min_idx(int *arr, int n)
{
	int	min_idx;
	int	i;

	min_idx = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

int	*parse_and_index(int argc, char **argv, int *n)
{
	int	*A;
	int	*S;
	int	i;
	int	j;

	if (argc < 2)
		exit(0);
	*n = argc - 1;
	A = malloc(sizeof(int) * (*n));
	if (!A)
		print_error_and_exit();
	i = 0;
	while (i < *n)
	{
		if (!is_integer(argv[i + 1]))
			print_error_and_exit();
		A[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	S = malloc(sizeof(int) * (*n));
	if (!S)
		print_error_and_exit();
	i = 0;
	while (i < *n)
	{
		S[i] = A[i];
		i++;
	}
	sort_int_array(S, *n);
	i = 0;
	while (i < *n)
	{
		j = 0;
		while (j < *n)
		{
			if (A[i] == S[j])
			{
				A[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	free(S);
	return (A);
}
