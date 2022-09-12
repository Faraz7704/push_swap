/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 20:46:13 by fkhan            ###   ########.fr       */
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

int	*new_quicksort(int *a, int n)
{
	int	*sort;

	if (!a || n <= 0)
		return (0);
	sort = ft_numdup(a, n);
	quicksort(sort, 0, n - 1);
	return (sort);
}

int	*lstnew_quicksort(t_list *a, int n)
{
	int	*sort;

	if (!a || n <= 0)
		return (0);
	sort = ft_lst_to_arr(a, n);
	quicksort(sort, 0, n - 1);
	return (sort);
}
