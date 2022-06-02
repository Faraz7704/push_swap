/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/02 19:51:46 by fkhan            ###   ########.fr       */
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
	sort = ft_lstdup(a, n);
	quicksort(sort, 0, n - 1);
	return (sort);
}

int	lst_issorted(t_list *lst, int n)
{
	int		i;
	int		*sort;
	t_list	*curr;

	sort = lstnew_quicksort(lst, n);
	i = 0;
	curr = lst;
	while (i < n)
	{
		if (*(int *)curr->content != sort[i])
		{
			free(sort);
			return (0);
		}
		i++;
		curr = curr->next;
	}
	free(sort);
	return (1);
}

int	issorted(int *a, int n)
{
	int	i;
	int	*sort;

	sort = new_quicksort(a, n);
	i = 0;
	while (i < n)
	{
		if (a[i] != sort[i])
		{
			free(sort);
			return (0);
		}
		i++;
	}
	free(sort);
	return (1);
}
