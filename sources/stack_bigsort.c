/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/29 19:51:30 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_set(t_set	*set, int id, int size)
{
	set->id = id;
	set->size = 0;
	set->total_moves = 0;
	set->items = malloc(sizeof(t_st_item) * size);
	if (!set->items)
		return (0);
	return (1);
}

static t_set	*init_sets(int size)
{
	int		i;
	int		set_size;
	t_set	*sets;

	sets = malloc(sizeof(t_set) * size);
	if (!sets)
		exit(1);
	i = 0;
	set_size = size;
	while (i < size)
	{
		set_size /= 2;
		init_set(&sets[i], i + 1, set_size);
		i++;
	}
	return (sets);
}

static int	get_pivot(t_list *a, int size, int index)
{
	int	pivot;
	int	*sorted;

	sorted = lstnew_quicksort(a, size);
	pivot = sorted[index];
	free(sorted);
	return (pivot);
}

static void	optimize_b(t_psinfo *info, t_set *set, int set_size)
{
	int	pivot;

	pivot = get_pivot(info->b.lst, info->b.size, set_size);
	if (set->id == 1)
	{
		if (*(int *)info->b.lst->content < pivot)
			run_inst("rb", info, 0);
		else if (info->b.size > 1 && *(int *)info->b.lst->content
			< *(int *)info->b.lst->next->content)
			run_inst("sb", info, 0);
	}
	else if (info->b.size > 1 && *(int *)info->b.lst->content
		< *(int *)info->b.lst->next->content)
		run_inst("sb", info, 0);
}

static void	stack_subset(t_psinfo *info, t_set *set, int set_size, int min_set_size)
{
	int	i;
	int	pivot;

	pivot = get_pivot(info->a.lst, info->a.size, set_size);
	i = 0;
	while (i < info->a.size && set->size < set_size)
	{
		if (*(int *)info->a.lst->content <= pivot)
		{
			run_inst("pb", info, 0);
			set->items[i].value = *(int *)info->b.lst->content;
			set->items[i].stack_type = info->b.stack_type;
			set->size++;
			optimize_b(info, set, set_size);
		}
		else
			run_inst("ra", info, 0);
		i++;
	}
	cal_set(set, info);
	set_size /= 2;
	if (set_size >= min_set_size)
		stack_subset(info, set++, set_size, min_set_size);
}

static int	get_set_size(int size, int min_size)
{
	if (size < min_size)
		return (0);
	return (get_set_size(size / 2, min_size) + 1);
}

static t_setinfo	*quicksort_to_b(t_psinfo *info, int min_set_size)
{
	t_setinfo	*new;

	new = malloc(sizeof(t_setinfo));
	if (!new)
		exit(1);
	new->size = get_set_size(info->a.size, min_set_size);
	new->sets = init_sets(new->size);
	stack_subset(info, new->sets, info->a.size / 2, min_set_size);
	return (new);
}

static void	insertsort_to_a(t_psinfo *info, t_setinfo *setinfo)
{
	(void)info;
	(void)setinfo;
	// TODO: implement
}

void	stack_bigsort(t_psinfo *info)
{
	t_setinfo	*setinfo;

	setinfo = quicksort_to_b(info, 15);
	insertsort_to_a(info, setinfo);
	free_sets(setinfo);
}
