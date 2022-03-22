/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/22 22:15:46 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	setval_moves(t_stack *a, int index)
{
	if (index < 0 || index >= a->size)
		return (0);
	if (index <= a->size / 2)
		return (index);
	return (a->size - index);
}

static int	init_set(t_sset	*set, t_stack *a, int size)
{
	set->stack = a;
	set->size = size;
	set->used = 0;
	set->total_moves = 0;
	set->index = malloc(sizeof(int) * size);
	if (!set->index)
		return (0);
	return (1);
}

static t_sset	*init_sets(t_stack *a, int *sort, int set_size)
{
	int		i;
	int		j;
	t_sset	*sets;

	sets = malloc(sizeof(t_sset) * set_size);
	if (!sets)
		return (0);
	i = 0;
	while (i < set_size)
	{
		if (!init_set(&sets[i], a, 12))
			return (0);
		j = 0;
		while (j < sets[i].size)
		{
			sets[i].index = find_index_stack(a, sort[j], a->size);
			if (sets[i].index >= 0)
				sets[i].total_moves += setval_moves(a, sets[i].index);
			j++;
		}
		i++;
	}
	return (sets);
}

t_sset	find_set(t_stack *a, t_stack *b, int *sort, int set_size)
{
	static t_sset	*sets;
	int				i;
	int				min_index;

	if (!sets)
		sets = init_sets(a, sort, set_size);
	i = 1;
	min_index = 0;
	while (sets[i].stack)
	{
		if (sets[min_index].total_moves > sets[i].total_moves && !sets[i].used)
			min_index = i;
		i++;
	}
	return (sets[min_index]);
}
