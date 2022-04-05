/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/05 23:07:04 by fkhan            ###   ########.fr       */
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
	set->moves = malloc(sizeof(int) * size);
	if (!set->moves)
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
		sets[i].values = &sort[index];
		cal_set(&sets[i], a);
		index += sets[i].size;
		i++;
	}
	return (sets);
}

int	find_min_set(t_sset *s, int set_size, t_sset **res)
{
	int		i;
	int		m;

	if (set_size <= 0)
		return (0);
	m = -1;
	i = 0;
	while (i < set_size)
	{
		if (!s[i].used && (m == -1 || s[m].total_moves > s[i].total_moves))
			m = i;
		i++;
	}
	if (m == -1)
		return (0);
	res[0] = &s[m];
	return (1);
}
