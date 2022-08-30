/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/30 19:01:57 by fkhan            ###   ########.fr       */
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
		ft_printf("size: %d\n", set_size);
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
	if (!sorted)
		exit(1);
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

static void	stack_subset(t_psinfo *info, t_set *set, int min_set_size)
{
	int	i;
	int	j;
	int	pivot;
	int	set_size;

	set_size = set->size;
	pivot = get_pivot(info->a.lst, info->a.size, set_size);
	i = 0;
	j = 0;
	ft_printf("size: %d, set_size: %d\n", info->a.size, set_size);
	while (i < info->a.size && j < set_size)
	{
		if (*(int *)info->a.lst->content <= pivot)
		{
			run_inst("pb", info, 0);
			set->items[i].value = *(int *)info->b.lst->content;
			set->items[i].stack_type = info->b.stack_type;
			optimize_b(info, set, set_size);
			j++;
		}
		else
			run_inst("ra", info, 0);
		i++;
		// ft_printf("i: %d, j: %d\n", i, j);
	}
	cal_set(set, info);
	set_size /= 2;
	ft_printf("********************************************\n");
	if (set_size >= min_set_size)
	{
		set++;
		stack_subset(info, set, min_set_size);
	}
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
	new->sets = init_sets(new->size, info->a.size);
	stack_subset(info, new->sets, min_set_size);
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

	print_stack(info->a, info->b);
	setinfo = quicksort_to_b(info, 15);
	insertsort_to_a(info, setinfo);
	free_sets(setinfo);
}
