/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/02 19:53:41 by fkhan            ###   ########.fr       */
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

static void	set_to_b(t_sset *set, t_stack *a, t_stack *b)
{
	int			i;
	int			index;
	int			*sort;
	int			pivot;

	sort = sort_values(set->items, set->size);
	pivot = sort[set->size / 2];
	i = 0;
	while (i < set->size)
	{
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

static int	find_index_arr(int *a, int value, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	sort_in_a(int *values, int n, t_stack *a, t_stack *b)
{
	int	i;
	int	first_index;
	int	second_index;
	int	*sort;
	int	record;

	sort = new_quicksort(values, n);
	i = 0;
	record = 0;
	while (i < n)
	{
		run_inst("ra", a, b, 0);
		first_index = find_index_arr(sort, *(int *)a->lst->content, n);
		second_index = find_index_arr(sort, *(int *)a->lst->next->content, n);
		if (first_index == second_index - 1)
			run_inst("sa", a, b, 0);
		if (first_index == n - 1 || first_index == n - 2)
		{
			run_inst("pb", a, b, 0);
			record++;
			if (*(int *)b->lst->content < *(int *)b->lst->next->content)
				run_inst("sb", a, b, 0);
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		run_inst("rra", a, b, 0);
		first_index = find_index_arr(sort, *(int *)a->lst->content, n);
		second_index = find_index_arr(sort, *(int *)a->lst->next->content, n);
		if (first_index == second_index - 1)
			run_inst("sa", a, b, 0);
		if (lst_issorted(a->lst, a->size))
			break ;
		i++;
	}
	i = 0;
	while (i++ < record)
		run_inst("pa", a, b, 0);
	free(sort);
}

static void	sort_midpoint(t_sset *sets, int set_size, t_stack *a, t_stack *b)
{
	int	i;
	int	*sort;
	int	pivot;
	int	true_size;

	i = set_size - 1;
	// while (i >= 0)
	// {
		sort = sort_values(sets[i].items, sets[i].size);
		true_size = set_type_size(&sets[i], A_STACK);
		pivot = sort[true_size / 2];
		// if (sets[i].id == set_size)
			sort_in_a(sort, true_size, a, b);
		// else
		// 	sort_in_a(sort, true_size / 2, a, b);
	// 	i--;
	// }
	free (sort);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		set_size;
	t_sset	*sets;

	sets = create_sets(a, &set_size);
	i = 0;
	while (i < set_size - 1)
	{
		set_to_b(&sets[i], a, b);
		cal_sets(sets, a, b, set_size);
		i++;
	}
	sort_midpoint(sets, set_size, a, b);
	free_sets(sets, set_size);
}
