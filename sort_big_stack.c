/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/29 17:41:45 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_sets_a(t_sset *set, t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	int	*sort;
	int	pivot;

	sort = new_quicksort(set->values, set->size);
	pivot = sort[set->size / 2];
	i = 0;
	while (i < set->size)
	{
		index = min_index_set(set, 0, set->size);
		index = set->index[index];
		move_top_stack(index, a, b, 0);
		run_inst("pb", a, b, 0);
		cal_set(set, a);
		if (set->id == 1 && b->size > 1 && b->value[0] < pivot)
			run_inst("rb", a, b, 0);
		i++;
	}
	set->in_b = 1;
}

static int	can_swap(t_stack *a)
{
	if (a->size < 2)
		return (0);
	if (a->value[0] > a->value[1])
		return (1);
	return (0);
}

static void	partition_b(t_sset *set, t_stack *a, t_stack *b, int pivot)
{
	int	i;
	int	*sort;

	sort = new_quicksort(set->index, set->size);
	i = 0;
	while (i < set->size)
	{
		if (sort[i] != -1 && b->value[sort[i]] > pivot)
		{
			move_top_stack(sort[i], a, b, 1);
			run_inst("pa", a, b, 0);
			cal_set(set, b);
			if (can_swap(a))
				run_inst("sa", a, b, 0);
		}
		i++;
	}
	free(sort);
}

static void	partition_a(t_sset *set, t_stack *a, t_stack *b, int pivot)
{
	int	i;
	int	*sort;

	sort = new_quicksort(set->index, set->size);
	i = 0;
	while (i < set->size)
	{
		if (sort[i] != -1 && a->value[sort[i]] < pivot)
		{
			move_top_stack(sort[i], a, b, 0);
			run_inst("pb", a, b, 0);
			cal_set(set, a);
			if (can_swap(b))
				run_inst("sb", a, b, 0);
		}
		i++;
	}
	free(sort);
}

static int	is_valid_index(t_sset *set)
{
	int	i;

	i = 0;
	while (i < set->size)
	{
		if (set->index[i] == -1)
			return (0);
	}
	return (1);
}

static void	sort_sets_b(t_sset *set, t_stack *a, t_stack *b)
{
    int i;
	int	*sort;
	int	pivot;
	int	true_size;

    i = 0;
	while (i < 30)
	{
		sort = new_quicksort(set->values, set->size);
		true_size = sets_true_size(set);
		pivot = sort[true_size / 2];
		cal_set(set, b);
		partition_b(set, a, b, pivot);
		cal_set(set, a);
		if (is_valid_index(set) && issorted(set->index, set->size))
			break ;
		partition_a(set, a, b, pivot);
		free(sort);
        i++;
	}
	set->in_b = 0;
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		*sort;
	t_sset	*sets;
	int		set_size;

	sort = new_quicksort(a->value, a->size);
	sets = create_sets(a, sort, &set_size);
	i = 0;
	while (i < set_size - 1)
	{
		sort_sets_a(&sets[i], a, b);
		cal_sets(sets, a, b, set_size);
		i++;
	}
	sort_stack(a, b);
	i = set_size - 2;
	while (i >= 0)
	{
		sort_sets_b(&sets[i], a, b);
		cal_sets(sets, a, b, set_size);
		i--;
	}
	free_sets(sets, set_size);
	free(sort);
}
