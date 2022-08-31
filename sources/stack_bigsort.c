/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/31 17:09:50 by fkhan            ###   ########.fr       */
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
	t_set	*sets;

	sets = malloc(sizeof(t_set) * size);
	if (!sets)
		exit(1);
	i = 0;
	while (i < size)
	{
		set_size /= 2;
		// ft_printf("size: %d\n", set_size);
		if (!init_set(&sets[i], i + 1, set_size))
			exit(1);
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

	pivot = get_pivot(info->b.lst, info->b.size, info->b.size / 2);
	// ft_printf("n: %d < p: %d\n", *(int *)info->b.lst->content, pivot);
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
		if (*(int *)info->a.lst->content <= pivot)
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
	add_set(info, set);
	cal_set(set, info);
	if (set->id < last_set_id)
		quicksort_to_b(info, ++set, last_set_id);
}

static int	get_set_size(int size, int min_size)
{
	if (size < min_size)
		return (0);
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

static void	insertsort_to_a(t_psinfo *info, t_setinfo *setinfo)
{
	(void)info;
	(void)setinfo;
	// TODO: implement
}

void	stack_bigsort(t_psinfo *info)
{
	t_setinfo	*setinfo;

	// print_stack(info->a, info->b);
	setinfo = create_sets(info, 15);
	insertsort_to_a(info, setinfo);
	// print_sets(setinfo->sets, setinfo->size);
	// print_stack(info->a, info->b);
	free_sets(setinfo);
}
