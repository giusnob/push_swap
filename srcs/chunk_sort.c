/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:46:21 by ginobile          #+#    #+#             */
/*   Updated: 2025/06/12 16:49:41 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
** Calcola e ritorna l'array di pivot per 'chunk_count' suddivisioni.
** Crea 𝑘 pivot in base a 𝑛/𝑘, cost O(n·log n) per il sorting di copia.
*/
static int	*get_pivots(int *A, int n, int chunk_count)
{
	int	*i, *pivots, size, k;

	pivots = malloc(sizeof(int) * chunk_count);
	if (!pivots)
		print_error_and_exit();
	size = n / chunk_count;
	i = sort_int_copy(A, n); /* copia+ordina A */
	k = 1;
	while (k < chunk_count)
	{
		pivots[k - 1] = i[size * k - 1];
		k++;
	}
	pivots[k - 1] = i[n - 1];
	free(i);
	return (pivots);
}

/*
** Spinge da A a B tutti gli elementi ≤ pivot,
** scegliendo sempre la rotazione minima (ra vs rra).
** Spinge un singolo elemento ≤ pivot, scegliendo sempre la rottazione più corta.
*/
static void	push_chunk(int *A, int *B, int *lenA, int *lenB, int pivot)
{
	int	i, pos;

	pos = find_pos_leq(A, *lenA, pivot);
	if (pos <= *lenA / 2)
		while (pos-- > 0)
			ra(A, *lenA);
	else
	{
		pos = *lenA - pos;
		while (pos-- > 0)
			rra(A, *lenA);
	}
	push(A, lenA, B, lenB, "pb");
}

/*
** Riporta tutti gli elementi da B ad A, scegliendo sempre il max
** con rotazione minima su B e poi 'pa'.
** Riporta in cima a A gli elementi di B, partendo dal massimo, usando rotazioni minime.
*/
static void	push_back(int *A, int *B, int *lenA, int *lenB)
{
	int	maxpos;

	while (*lenB > 0)
	{
		maxpos = find_max_idx(B, *lenB);
		if (maxpos <= *lenB / 2)
			while (maxpos-- > 0)
				rb(B, *lenB);
		else
		{
			maxpos = *lenB - maxpos;
			while (maxpos-- > 0)
				rrb(B, *lenB);
		}
		push(B, lenB, A, lenA, "pa");
	}
}

/*
** chunk_sort: suddivide in 'chunk_count' parti, le spinge su B
** e poi le riporta ordinate in A.
** Per ciascun pivot svuota la “fetta” corrispondente di A in B, poi rimonta tutto in ordine.
*/
void	chunk_sort(int *A, int *B, int *lenA, int *lenB, int n, int chunk_count)
{
	int	*pivots;
	int	i;

	pivots = get_pivots(A, n, chunk_count);
	i = 0;
	while (i < chunk_count)
	{
		while (exists_leq(A, *lenA, pivots[i]))
			push_chunk(A, B, lenA, lenB, pivots[i]);
		i++;
	}
	free(pivots);
	push_back(A, B, lenA, lenB);
}
