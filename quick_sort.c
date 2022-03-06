/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/05 15:04:45 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *a, int start, int end)
{
	int	i;
	int	pindex;
	int	pivot;

	pivot = a[end];
	pindex = start;
	i = start;
	while (i < end)
	{
		if (a[i] < pivot)
		{
			ft_numswap(&a[pindex], &a[i]);
			pindex++;
		}
		i++;
	}
	ft_numswap(&a[pindex], &a[end]);
	return (pindex);
}

void	quicksort(int *a, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(a, start, end);
	quicksort(a, start, pivot - 1);
	quicksort(a, pivot + 1, end);
}

int	issorted(int *a, int n)
{
	int	i;
	int	*sorta;

	sorta = ft_numdup(a, n);
	quicksort(sorta, 0, n - 1);
	i = 0;
	while (i < n)
	{
		if (a[i] != sorta[i])
			return (0);
		i++;
	}
	free(sorta);
	return (1);
}
