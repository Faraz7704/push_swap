/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/27 17:13:45 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_stack(int *a, int value, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	min_index_stack(int *a, int start, int n)
{
	int	i;
	int	min;

	i = start + 1;
	min = start;
	while (i < n)
	{
		if (a[i] < a[min])
			min = i;
		i++;
	}
	return (min);
}

int	min_moves_stack(t_sset *set)
{
	int	i;
	int	m;

	i = 0;
	m = -1;
	while (i < set->size)
	{
		if (set->index[i] != -1 && (m == -1 || set->moves[i] < set->moves[m]))
			m = i;
		i++;
	}
	return (m);
}

int	max_index_stack(int *a, int start, int n)
{
	int	i;
	int	max;

	i = start + 1;
	max = start;
	while (i < n)
	{
		if (a[i] > a[max])
			max = i;
		i++;
	}
	return (max);
}

int	max_moves_stack(t_sset *set)
{
	int	i;
	int	m;

	i = 0;
	m = -1;
	while (i < set->size)
	{
		if (set->index[i] != -1 && (m == -1 || set->moves[i] > set->moves[m]))
			m = i;
		i++;
	}
	return (m);
}
