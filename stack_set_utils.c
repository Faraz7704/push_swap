/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/05 14:55:13 by fkhan            ###   ########.fr       */
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

void	cal_sets_moves(t_sset *sets, t_stack *a, int set_size)
{
	int	i;

	i = 0;
	while (i < set_size)
	{
		if (!sets[i].used)
			cal_set_moves(&sets[i], a);
		i++;
	}
}

void	cal_set_moves(t_sset *set, t_stack *a)
{
	int	i;

	i = 0;
	set->total_moves = 0;
	while (i < set->size)
	{
		set->index[i] = find_index_stack(a->value, set->values[i], a->size);
		if (set->index[i] >= 0)
			set->total_moves += setval_moves(a, set->index[i]);
		i++;
	}
}

void	free_sets(t_sset *sets, int set_size)
{
	int	i;

	i = 0;
	while (i < set_size)
		free(sets[i++].index);
}
