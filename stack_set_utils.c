/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/30 13:59:23 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves(t_stack *a, int index)
{
	if (index < 0 || index >= a->size)
		return (0);
	if (index <= a->size / 2)
		return (index);
	return (a->size - index);
}

void	cal_sets(t_sset *sets, t_stack *a, t_stack *b, int set_size)
{
	int	i;

	i = 0;
	while (i < set_size)
	{
		if (sets[i].in_b)
			cal_set(&sets[i], b);
		else
			cal_set(&sets[i], a);
		i++;
	}
}

void	cal_set(t_sset *set, t_stack *a)
{
	int			i;
	t_list		curr;
	t_set_item	item;

	i = 0;
	set->total_moves = 0;
	curr = i;
	while (i < set->size)
	{
		item = set->items[i];
		item.index = find_index_stack(a->lst, set->values[i], a->size);
		if (set->index[i] >= 0)
		{
			set->moves[i] = get_moves(a, set->index[i]);
			set->total_moves += set->moves[i];
		}
		else
			set->moves[i] = 0;
		i++;
	}
}

int	min_index_set(t_sset *set, int start, int n)
{
	int	i;
	int	min;

	i = start;
	min = start;
	while (i < n && set->index[min] == -1)
		min++;
	i = start + 1;
	while (i < n)
	{
		if (set->index[i] != -1 && set->index[i] < set->index[min])
			min = i;
		i++;
	}
	return (min);
}

void	free_sets(t_sset *sets, int set_size)
{
	int	i;

	i = 0;
	while (i < set_size)
	{
		free(sets[i].index);
		free(sets[i].moves);
		i++;
	}
	free(sets);
}
