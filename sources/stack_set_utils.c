/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/04 19:05:35 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves(t_stack a, int index)
{
	if (index < 0 || index >= a.size)
		return (0);
	if (index <= a.size / 2)
		return (index);
	return (a.size - index);
}

void	cal_sets(t_set *sets, t_psinfo *info, int set_size)
{
	int	i;

	i = 0;
	while (i < set_size)
	{
		cal_set(&sets[i], info);
		i++;
	}
}

void	cal_set(t_set *set, t_psinfo *info)
{
	int			i;
	t_st_item	*item;
	t_stack		temp;

	i = 0;
	set->total_moves = 0;
	while (i < set->size)
	{
		item = &set->items[i];
		if (item->stack_type == A_STACK)
			temp = info->a;
		else
			temp = info->b;
		item->index = find_index_stack(temp.lst, item->value, temp.size);
		if (item->index >= 0)
		{
			item->move = get_moves(temp, item->index);
			set->total_moves += item->move;
		}
		else
			item->move = 0;
		i++;
	}
}

int	type_size_set(t_set *set, t_e_stack type)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < set->size)
	{
		if (set->items[i].stack_type == type)
			len++;
		i++;
	}
	return (len);
}

int	*items_to_arr(t_st_item *items, int size)
{
	int	i;
	int	*new;

	new = malloc(sizeof(t_st_item) * size);
	if (!new)
		exit(1);
	i = 0;
	while (i < size)
	{
		new[i] = items[i].value;
		i++;
	}
	return (new);
}

int	*set_sort(t_set *set)
{
	int	*values;
	int	*sorted;

	values = items_to_arr(set->items, set->size);
	sorted = new_quicksort(values, set->size);
	if (!sorted)
		exit(1);
	free(values);
	return (sorted);
}

int	*num_sort(int *a, int n)
{
	int	*sorted;

	sorted = new_quicksort(a, n);
	if (!sorted)
		exit(1);
	return (sorted);
}

int	*num_rsort(int *a, int n)
{
	int	i;
	int	j;
	int	*sorted;
	int	*rsorted;

	sorted = num_sort(a, n);
	rsorted = malloc(sizeof(int *) * n);
	if (!rsorted)
		exit(1);
	i = n - 1;
	j = 0;
	while (i >= 0)
		rsorted[j++] = sorted[i--];
	free(sorted);
	return (rsorted);
}

int	*set_rsort(t_set *set)
{
	int	i;
	int	j;
	int	*values;
	int	*sorted;
	int	*rsorted;

	values = items_to_arr(set->items, set->size);
	sorted = new_quicksort(values, set->size);
	if (!sorted)
		exit(1);
	rsorted = malloc(sizeof(int *) * set->size);
	if (!rsorted)
		exit(1);
	i = set->size - 1;
	j = 0;
	while (i >= 0)
		rsorted[j++] = sorted[i--];
	free(values);
	free(sorted);
	return (rsorted);
}

void	free_sets(t_setinfo *info)
{
	int	i;

	i = 0;
	while (i < info->size)
	{
		free(info->sets[i].items);
		i++;
	}
	free(info->sets);
	free(info);
}
