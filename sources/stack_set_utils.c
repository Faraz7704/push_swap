/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/27 17:52:28 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves(t_stack *a, int index)
{
	if (index < 0 || index >= a->size)
		return (0);
	if (index <= a->size / 2)
		return (index);
	return (a->size - index);
}

void	cal_sets(t_set *sets, t_stack *a, t_stack *b, int set_size)
{
	int	i;

	i = 0;
	while (i < set_size)
	{
		cal_set(&sets[i], a, b);
		i++;
	}
}

void	cal_set(t_set *set, t_stack *a, t_stack *b)
{
	int			i;
	t_st_item	*item;
	t_stack		*temp;

	i = 0;
	set->total_moves = 0;
	while (i < set->size)
	{
		item = &set->items[i];
		if (item->stack_type == A_STACK || !b)
			temp = a;
		else
			temp = b;
		item->index = find_index_stack(temp->lst, item->value, temp->size);
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

int	*new_item_values(t_st_item *items, int n)
{
	int	i;
	int	*values;

	values = malloc(sizeof(int) * n);
	if (!values)
		return (0);
	i = 0;
	while (i < n)
	{
		values[i] = items[i].value;
		i++;
	}
	return (values);
}

int	min_index_set(t_st_item *items, t_e_stack type, int n)
{
	int	i;
	int	min;
	int	allowed;

	i = 0;
	min = -1;
	while (i < n)
	{
		allowed = (type == ALL_STACK || items[i].stack_type == type);
		if (allowed && (min == -1 || items[i].index < items[min].index))
			min = i;
		i++;
	}
	return (min);
}

void	free_sets(t_set *sets, int set_size)
{
	int	i;

	i = 0;
	while (i < set_size)
	{
		free(sets[i].items);
		i++;
	}
	free(sets);
}
