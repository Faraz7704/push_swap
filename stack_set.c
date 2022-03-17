/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/17 13:21:25 by fkhan            ###   ########.fr       */
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

t_sset	*create_sets(t_stack *a, int *sort, int set_size)
{
	int		i;
	int		j;
	t_sset	*sets;
	int		temp;

	sets = malloc(sizeof(t_sset) * set_size);
	if (!sets)
		return (0);
	i = 0;
	while (i < set_size)
	{
		sets[i].stack = a;
		sets[i].size = a->size / set_size;
		sets[i].total_moves = 0;
		j = 0;
		while (j < sets[i].size)
		{
			temp = find_index_stack(a, sort[j], a->size);
			if (temp >= 0)
				sets[i].total_moves += setval_moves(a, temp);
			j++;
		}
		i++;
	}
}

void	find_set(t_stack *a, t_stack *b, int *sort, int set_size)
{
	
}
