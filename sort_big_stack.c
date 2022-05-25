/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/25 17:16:34 by fkhan            ###   ########.fr       */
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

// static void	sort_sets_a(t_sset *set, t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	*sort;
// 	int	pivot;
// 	int	true_size;

// 	sort = ft_numdup(set->values, set->size);
// 	quicksort(sort, 0, set->size - 1);
// 	true_size = sets_true_size(set);
// 	// ft_printf("set id: %d set size: %d sets true size: %d\n", set->id, set->size, true_size);
// 	while (set->total_moves && true_size > 2)
// 	{
// 		i = 0;
// 		pivot = sort[true_size / 2];
// 		while (i < set->size)
// 		{
// 			if (set->values[i] > pivot)
// 			{
// 				// ft_printf("value: %d value: %d\n", set->values[i], b->value[set->index[i]]);
// 				move_top_stack(set->index[i], a, b, 0);
// 				run_inst("pb", a, b, 0);
// 				cal_set(set, a);
// 				// swap_stack_a(a, b);
// 			}
// 			i++;
// 		}
// 		true_size = sets_true_size(set);
// 	}
// 	i = sets_true_size(set);
// 	while (i--)
// 	{
// 		pivot = max_index_stack(a->value, 0, a->size);
// 		// ft_printf("value in b: %d\n", b->value[index]);
// 		move_top_stack(pivot, a, b, 0);
// 		run_inst("pb", a, b, 0);
// 		cal_set(set, a);
// 	}
// 	set->in_b = 1;
// 	free(sort);
// }

static void	swap_stack_a(t_stack *a, t_stack *b)
{
	if (a->size < 2)
		return ;
	if (a->value[0] > a->value[1])
	{
		run_inst("sa", a, b, 0);
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
	// ft_printf("set id: %d set size: %d sets true size: %d\n", set->id, set->size, true_size);
	while (set->total_moves && true_size > 2)
	{
		i = 0;
		pivot = sort[true_size / 2];
		while (i < set->size)
		{
			if (set->values[i] > pivot)
			{
				ft_printf("value: %d value: %d\n", set->values[i], b->value[set->index[i]]);
				move_top_stack(set->index[i], a, b, 1);
				run_inst("pa", a, b, 0);
				cal_set(set, b);
				swap_stack_a(a, b);
			}
			i++;
		}
		true_size = sets_true_size(set);
	}
	i = sets_true_size(set);
	while (i--)
	{
		pivot = max_index_stack(b->value, 0, b->size);
		// ft_printf("value in b: %d\n", b->value[index]);
		move_top_stack(pivot, a, b, 1);
		run_inst("pa", a, b, 0);
		cal_set(set, b);
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
		// int j = 0;
		// ft_printf("\n------------------\n");
		// ft_printf("set ID: %d size %d in_b: %d\n", sets[i].id, sets[i].size, sets[i].in_b);
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
	print_stack(*a, *b);
	i = 0;
	while (i < set_size)
	{
		int j = 0;
		ft_printf("\n------------------\n");
		ft_printf("set ID: %d size %d in_b: %d\n", sets[i].id, sets[i].size, sets[i].in_b);
		while (j < sets[i].size)
		{
			ft_printf("[%3d, %3d, %3d] ", sets[i].index[j], sets[i].values[j], sets[i].moves[j]);
			j++;
		}
		ft_printf("\n------------------\n");
		i++;
	}
	i = set_size - 2;
	while (i >= 0)
	{
		int j = 0;
		ft_printf("\n------------------\n");
		ft_printf("set ID: %d size %d in_b: %d\n", sets[i].id, sets[i].size, sets[i].in_b);
		while (j < sets[i].size)
		{
			ft_printf("[%3d, %3d, %3d] ", sets[i].index[j], sets[i].values[j], sets[i].moves[j]);
			j++;
		}
		ft_printf("\n------------------\n");
		sort_sets_b(&sets[i], a, b);
		cal_sets(sets, a, b, set_size);
		print_stack(*a, *b);
		i--;
	}
	free_sets(sets, set_size);
	free(sort);
}
