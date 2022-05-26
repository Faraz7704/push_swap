/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/26 15:02:08 by fkhan            ###   ########.fr       */
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

static int	sets_true_size(t_sset *set)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < set->size)
	{
		if (set->index[i] != -1)
			len++;
		i++;
	}
	return (len);
}

static void	partition(t_sset *set, t_stack *a, t_stack *b, int pivot)
{
	int	i;

	i = set->size - 1;
	while (i >= 0)
	{
		if (set->index[i] != -1 && set->values[i] > pivot)
		{
			move_top_stack(set->index[i], a, b, 1);
			run_inst("pa", a, b, 0);
			cal_set(set, b);
		}
		i--;
	}
}

static void	sort_sets_b(t_sset *set, t_stack *a, t_stack *b)
{
	int	i;
	int	*sort;
	int	pivot;
	int	true_size;

	sort = ft_numdup(set->values, set->size);
	quicksort(sort, 0, set->size - 1);
	true_size = sets_true_size(set);
	while (set->total_moves && true_size > 2)
	{
		pivot = sort[true_size / 2];
		partition(set, a, b, pivot);
		true_size = sets_true_size(set);
	}
	i = set->size - 1;
	while (i >= 0)
	{
		if (set->index[i] != -1)
		{
			move_top_stack(set->index[i], a, b, 1);
			run_inst("pa", a, b, 0);
			cal_set(set, b);
		}
		i--;
	}
	set->in_b = 0;
	free(sort);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		*sort;
	t_sset	*sets;
	int		set_size;

	sort = ft_numdup(a->value, a->size);
	quicksort(sort, 0, a->size - 1);
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
