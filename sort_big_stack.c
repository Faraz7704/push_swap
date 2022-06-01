/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/01 15:01:33 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_values(t_set_item *items, int n)
{
	int	*values;
	int	*sort;

	values = new_item_values(items, n);
	sort = new_quicksort(values, n);
	free(values);
	return (sort);
}

static void	set_to_b(t_sset *set, int set_size, t_stack *a, t_stack *b)
{
	int			i;
	int			index;
	int			*sort;
	int			pivot;

	sort = sort_values(set->items, set->size);
	pivot = sort[set->size / 2];
	i = 0;
	// ft_printf("set id: %d, size: %d, item value: %d, pivot: %d\n", set->id, set->size, set->items[0].value, pivot);
	while (i < set->size)
	{
		if (set->id == set_size - 1 && b->size > 1 && set->items[0].value > pivot)
		{
			i++;
			continue ;
		}
		index = min_index_set(set->items, A_STACK, set->size);
		if (index == -1)
		{
			i++;
			continue ;
		}
		set->items[index].stack_type = B_STACK;
		index = set->items[index].index;
		move_top_stack(index, a, b, 0);
		run_inst("pb", a, b, 0);
		cal_set(set, a, b);
		if (set->id == 1 && b->size > 1 && *(int *)b->lst->content < pivot)
			run_inst("rb", a, b, 0);
		i++;
	}
}

// static int	can_swap(t_stack *a)
// {
// 	if (a->size < 2)
// 		return (0);
// 	if (a->value[0] > a->value[1])
// 		return (1);
// 	return (0);
// }

// static void	partition_b(t_sset *set, t_stack *a, t_stack *b, int pivot)
// {
// 	int	i;
// 	int	*sort;

// 	sort = new_quicksort(set->index, set->size);
// 	i = 0;
// 	while (i < set->size)
// 	{
// 		if (sort[i] != -1 && b->value[sort[i]] > pivot)
// 		{
// 			smart_move_stack(sort[i], a, b, 1);
// 			run_inst("pa", a, b, 0);
// 			cal_set(set, b);
// 		}
// 		i++;
// 	}
// 	free(sort);
// }

// static void	partition_a(t_sset *set, t_stack *a, t_stack *b, int pivot)
// {
// 	int	i;
// 	int	*sort;

// 	sort = new_quicksort(set->index, set->size);
// 	i = 0;
// 	while (i < set->size)
// 	{
// 		if (sort[i] != -1 && a->value[sort[i]] < pivot)
// 		{
// 			move_top_stack(sort[i], a, b, 0);
// 			run_inst("pb", a, b, 0);
// 			cal_set(set, a);
// 			if (can_swap(b))
// 				run_inst("sb", a, b, 0);
// 		}
// 		i++;
// 	}
// 	free(sort);
// }

// static int	is_valid_index(t_sset *set)
// {
// 	int	i;

// 	i = 0;
// 	while (i < set->size)
// 	{
// 		if (set->index[i] == -1)
// 			return (0);
// 	}
// 	return (1);
// }

// static void	sort_sets(t_sset *set, t_stack *a, t_stack *b)
// {
// 	int	*sort;
// 	int	pivot;
// 	int	true_size;

// 	sort = new_quicksort(set->values, set->size);
// 	pivot = sort[set->size / 2];
// 	while (1)
// 	{
// 		true_size = sets_true_size(set);
// 		cal_set(set, b);
// 		partition_b(set, a, b, pivot);
// 		cal_set(set, a);
// 		if (is_valid_index(set) && issorted(set->index, set->size))
// 			break ;
// 		partition_a(set, a, b, pivot);
// 		free(sort);
// 	}
// 	set->in_b = 0;
// }

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	t_sset	*sets;
	int		set_size;

	sets = create_sets(a, &set_size);
	i = 0;
	while (i < set_size - 1)
	{
		set_to_b(&sets[i], set_size, a, b);
		cal_sets(sets, a, b, set_size);
		i++;
	}
	// sort_stack(a, b);
	// i = set_size - 2;
	// while (i >= 0)
	// {
	// 	sort_sets(&sets[i], a, b);
	// 	cal_sets(sets, a, b, set_size);
	// 	i--;
	// }
	free_sets(sets, set_size);
}
