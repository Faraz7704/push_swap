/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/27 22:21:36 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_set(t_sset *set, t_stack *a, t_stack *b)
{
	int		i;
	int		min_index;
	int		max_index;

	i = 0;
	while (i < set->size)
	{
		min_index = min_moves_stack(set);
		min_index = set->index[min_index];
		if (set->id > 1)
		{
			max_index = max_index_stack(b->value, 0, b->size);
			run_multi_inst(min_index, max_index, a, b);
		}
		else
			move_top_stack(min_index, a, b, 0);
		run_inst("pb", a, b);
		cal_set(set, a);
		i++;
	}
	set->used = 1;
}

void	sort_big(t_stack *a, t_stack *b, int *sort, int set_size)
{
	int		i;
	int		max_index;
	int		actual_set_size;
	t_sset	*sets;

	sets = create_sets(a, sort, set_size, &actual_set_size);
	// print_sets(sets, sort, actual_set_size);
	i = 0;
	while (i < actual_set_size)
	{
		// ft_printf("set selected: %d\n", min_set->id);
		sort_set(&sets[i], a, b);
		// ft_printf("\nb: ");
		// print_numarr(*b);
		cal_sets(sets, a, actual_set_size);
		// print_sets(sets, sort, actual_set_size);
		i++;
	}
	while (b->size)
	{
		max_index = max_index_stack(b->value, 0, b->size);
		move_top_stack(max_index, a, b, 1);
		run_inst("pa", a, b);
	}
	free_sets(sets, actual_set_size);
}
