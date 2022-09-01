/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/01 22:30:11 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_set(t_set	*set, int id, int size)
{
	set->id = id;
	set->size = size;
	set->total_moves = 0;
	set->items = malloc(sizeof(t_st_item) * size);
	if (!set->items)
		return (0);
	return (1);
}

static t_set	*init_sets(int size, int set_size)
{
	int		i;
	int		total_size;
	int		curr_size;
	t_set	*sets;

	sets = malloc(sizeof(t_set) * size);
	if (!sets)
		exit(1);
	total_size = set_size;
	i = 0;
	curr_size = 0;
	while (i < size)
	{
		if (i == size - 1)
			set_size = total_size - curr_size;
		else
			set_size /= 2;
		if (!init_set(&sets[i], i + 1, set_size))
			exit(1);
		curr_size += set_size;
		i++;
	}
	return (sets);
}

static int	get_pivot(t_list *a, int size, int index)
{
	int	pivot;
	int	*sorted;

	sorted = lstnew_quicksort(a, size);
	if (!sorted)
		exit(1);
	pivot = sorted[index];
	free(sorted);
	return (pivot);
}

static void	optimize_b(t_psinfo *info, t_set *set)
{
	int	pivot;

	if (set->id == 1)
	{
		pivot = get_pivot(info->b.lst, info->b.size, info->b.size / 2);
		if (*(int *)info->b.lst->content < pivot)
			run_inst("rb", info, 0);
		// else if (info->b.size > 1 && *(int *)info->b.lst->content
		// 	< *(int *)info->b.lst->next->content)
		// 	run_inst("sb", info, 0);
	}
	// else if (info->b.size > 1 && *(int *)info->b.lst->content
	// 	< *(int *)info->b.lst->next->content)
	// 	run_inst("sb", info, 0);
}

static void	add_set(t_psinfo *info, t_set *set)
{
	int	i;
	int	j;
	int	pivot;

	pivot = get_pivot(info->a.lst, info->a.size, set->size);
	i = 0;
	j = 0;
	while (i < info->a.size && j < set->size)
	{
		if (*(int *)info->a.lst->content < pivot)
		{
			run_inst("pb", info, 0);
			set->items[j].value = *(int *)info->b.lst->content;
			set->items[j].stack_type = info->b.stack_type;
			optimize_b(info, set);
			j++;
		}
		else
		{
			run_inst("ra", info, 0);
			i++;
		}
	}
}

static void	quicksort_to_b(t_psinfo *info, t_set *set, int last_set_id)
{
	int		i;
	t_list	*curr;

	add_set(info, set);
	cal_set(set, info);
	if (set->id < last_set_id - 1)
		quicksort_to_b(info, ++set, last_set_id);
	else
	{
		set++;
		i = 0;
		curr = info->a.lst;
		while (curr)
		{
			set->items[i].value = *(int *)curr->content;
			set->items[i].stack_type = A_STACK;
			curr = curr->next;
			i++;
		}
		cal_set(set, info);
	}
}

static int	get_set_size(int size, int min_size)
{
	if (size < min_size)
		return (1);
	return (get_set_size(size / 2, min_size) + 1);
}

static t_setinfo	*create_sets(t_psinfo *info, int min_set_size)
{
	t_setinfo	*new;

	new = malloc(sizeof(t_setinfo));
	if (!new)
		exit(1);
	new->size = get_set_size(info->a.size, min_set_size);
	new->sets = init_sets(new->size, info->a.size);
	quicksort_to_b(info, new->sets, new->size);
	return (new);
}

static void optimize_move_on_a(t_psinfo *info, int index)
{
	int	size;

	size = info->a.size;
	if (index < size / 2)
		run_inst("ra", info, 0);
	else
		run_inst("rra", info, 0);
	// if (info->a.size > 1 && *(int *)info->a.lst->content
	// 	> *(int *)info->a.lst->next->content)
	// 	run_inst("sa", info, 0);
}

static int	move_to_b(t_psinfo *info, int *sorted, int index)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i <= index)
	{
		if (!sorted[1] && *(int *)info->a.lst->content == sorted[1])
		{
			run_inst("pb", info, 0);
			counter++;
		}
		else if (*(int *)info->a.lst->content == sorted[0])
		{
			run_inst("pb", info, 0);
			if (info->b.size > 1 && *(int *)info->b.lst->content
				< *(int *)info->b.lst->next->content)
				run_inst("sb", info, 0);
			counter++;
			break ;
		}
		else
			optimize_move_on_a(info, index);
		if (lst_issorted(info->a.lst, info->a.size))
			return (counter);
		i++;
	}
	return (counter);
}

static void	insertsort_on_a(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;
	int	add_size;

	i = 0;
	add_size = 0;
	// print_numarr(sorted, size);
	// print_stack(info->a, info->b);
	while (i < size)
	{
		index = min_index_stack(info->a.lst, info->a.size);
		// print_stack(info->a, info->b);
		add_size += move_to_b(info, &sorted[i], index);
		if (lst_issorted(info->a.lst, info->a.size))
			break ;
		i++;
	}
	i = 0;
	while (i < add_size)
	{
		run_inst("pa", info, 0);
		if (info->a.size > 1 && *(int *)info->a.lst->content
			> *(int *)info->a.lst->next->content)
			run_inst("sa", info, 0);
		i++;
	}
}

static void optimize_move_on_b(t_psinfo *info, int index)
{
	int	size;

	size = info->b.size;
	if (index < size / 2)
		run_inst("rb", info, 0);
	else
		run_inst("rrb", info, 0);
	// if (info->b.size > 1 && *(int *)info->b.lst->content
	// 	< *(int *)info->b.lst->next->content)
	// 	run_inst("sb", info, 0);
}

static void	move_to_a(t_psinfo *info, int *sorted, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		if (!sorted[1] && *(int *)info->b.lst->content == sorted[1])
			run_inst("pa", info, 0);
		else if (*(int *)info->b.lst->content == sorted[0])
		{
			run_inst("pa", info, 0);
			if (info->a.size > 1 && *(int *)info->a.lst->content
				> *(int *)info->a.lst->next->content)
				run_inst("sa", info, 0);
			break ;
		}
		else
			optimize_move_on_b(info, index);
		i++;
	}
}

static void	insertsort_on_b(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;

	i = 0;
	while (i < size)
	{
		index = max_index_stack(info->b.lst, info->b.size);
		move_to_a(info, &sorted[i], index);
		i++;
	}
}

static void	divide_on_b(t_psinfo *info, int *sorted, int set_size)
{
	int	i;
	int	j;
	int	pivot;
	int	size;

	size = set_size / 2;
	pivot = sorted[size];
	i = 0;
	j = 0;
	while (i < set_size && j < size)
	{
		if (*(int *)info->b.lst->content > pivot)
		{
			run_inst("pa", info, 0);
			j++;
		}
		else
			run_inst("rb", info, 0);
		i++;
	}
}

static void	insertsort(t_psinfo *info, t_setinfo *setinfo)
{
	int		i;
	int		*sorted;
	t_set	*set;
	int		index;

	i = setinfo->size - 1;
	set = &setinfo->sets[i];
	sorted = set_sort(set);
	insertsort_on_a(info, sorted, set->size);
	free(sorted);
	i--;
	set = &setinfo->sets[i];
	sorted = set_rsort(set);
	insertsort_on_b(info, sorted, set->size);
	free(sorted);
	i--;
	while (i >= 0)
	{
		set = &setinfo->sets[i];
		sorted = set_sort(set);
		divide_on_b(info, sorted, set->size);
		index = (set->size / 2) + 1;
		insertsort_on_a(info, &sorted[index], set->size - index);
		free(sorted);
		sorted = set_rsort(set);
		index = (set->size / 2);
		insertsort_on_b(info, &sorted[index], set->size - index);
		free(sorted);
		i--;
	}
}

void	stack_bigsort(t_psinfo *info)
{
	t_setinfo	*setinfo;

	// print_stack(info->a, info->b);
	setinfo = create_sets(info, 15);
	insertsort(info, setinfo);
	// print_sets(setinfo->sets, setinfo->size);
	// print_stack(info->a, info->b);
	free_sets(setinfo);
}
