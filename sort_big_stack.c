/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/21 17:53:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_sets_a(t_sset *set, t_stack *a, t_stack *b)
{
	int	i;
	int	index;

	i = 0;
	while (i < set->size)
	{
		index = set->index[min_moves_stack(set)];
		move_top_stack(index, a, b, 0);
		run_inst("pb", a, b, 0);
		cal_set(set, a);
		i++;
	}
	set->in_b = 1;
}

static void	sort_sets_b(t_sset *set, t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	int	*sort;
	int	pivot;
	int	temp;

	sort = ft_numdup(b->value, b->size);
	quicksort(sort, 0, b->size - 1);
	i = set->size - 1;
	temp = b->size;
	while (i >= 0)
	{
		temp /= 2;
		pivot = sort[b->size - temp];
		index = set->index[min_moves_stack(set)];
		move_top_stack(index, a, b, 1);
		run_inst("pa", a, b, 0);
		cal_set(set, a);
		i--;
	}
	set->in_b = 0;
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		*sort;
	t_sset	*sets;
	int		set_size;
	int		max_index;

	sort = ft_numdup(a->value, a->size);
	quicksort(sort, 0, a->size - 1);
	sets = create_sets(a, sort, &set_size);
	i = 0;
	while (i < set_size - 1)
	{
		// int j = 0;
		// ft_printf("\n------------------\n");
		// ft_printf("set ID: %d size %d\n", sets[i].id, sets[i].size);
		// while (j < sets[i].size)
		// {
		// 	ft_printf("[%3d, %3d, %3d] ", sets[i].index[j], sets[i].values[j], sets[i].moves[j]);
		// 	j++;
		// }
		// ft_printf("\n------------------\n");
		sort_sets_a(&sets[i], a, b);
		cal_sets(sets, a, b, set_size);
		i++;
	}
	sort_stack(a, b);
	i = 0;
	while (i < set_size - 1)
	{
		sort_sets_b(&sets[i], a, b);
		cal_sets(sets, a, b, set_size);
		i++;
	}
	free_sets(sets, set_size);
}
