/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/04 18:30:54 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_set(t_sset	*set, int id, int size)
{
	set->id = id;
	set->size = size;
	set->used = 0;
	set->total_moves = 0;
	set->index = malloc(sizeof(int) * size);
	if (!set->index)
		return (0);
	return (1);
}

t_sset	*create_sets(t_stack *a, int *sort, int set_size)
{
	int		i;
	int		index;
	t_sset	*sets;

	sets = malloc(sizeof(t_sset) * set_size);
	if (!sets)
		return (0);
	index = 0;
	i = 0;
	while (i < set_size)
	{
		if (!init_set(&sets[i], i + 1, a->size / set_size))
			return (0);
		cal_set_moves(&sets[i], a, sort[index]);
		index += sets[i].size;
		i++;
	}
	return (sets);
}

int	find_min_set(t_sset *sets, int set_size, t_sset **res)
{
	int		i;
	int		min_index;

	if (set_size < 0)
		return (0);
	min_index = 0;
	i = 1;
	while (i < set_size)
	{
		if (sets[min_index].total_moves > sets[i].total_moves && !sets[i].used)
			min_index = i;
		i++;
	}
	if (!min_index && set_size >= 1 && sets[i].used)
		return (0);
	res[0] = &sets[min_index];
	return (1);
}
