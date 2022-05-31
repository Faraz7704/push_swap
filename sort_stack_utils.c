/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/31 14:21:59 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_stack(t_list *lst, int value, int n)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = lst;
	while (i < n)
	{
		if (*(int *)curr->content == value)
			return (i);
		curr = curr->next;
		i++;
	}
	return (-1);
}

int	min_index_stack(t_list *lst, int n)
{
	int		i;
	t_list	*curr;
	t_list	*min;
	int		index;

	i = 1;
	curr = lst->next;
	min = lst;
	index = 0;
	while (i < n)
	{
		if (*(int *)curr->content < *(int *)min->content)
		{
			min = curr;
			index = i;
		}
		curr = curr->next;
		i++;
	}
	return (index);
}

int	max_index_stack(t_list *lst, int n)
{
	int		i;
	t_list	*curr;
	t_list	*max;
	int		index;

	i = 1;
	curr = lst->next;
	max = lst;
	index = 0;
	while (i < n)
	{
		if (*(int *)curr->content > *(int *)max->content)
		{
			max = curr;
			index = i;
		}
		curr = curr->next;
		i++;
	}
	return (index);
}

t_set_item	*min_move_stack(t_sset *set, t_e_stack type)
{
	int			i;
	t_set_item	*min;
	t_set_item	item;
	int			allowed;

	i = 0;
	min = NULL;
	while (i < set->size)
	{
		item = set->items[i];
		allowed = (type == ALL_STACK || item.stack_type == type);
		if (allowed && (!min || item.move < min->move))
			min = &item;
		i++;
	}
	return (min);
}

t_set_item	*max_move_stack(t_sset *set, t_e_stack type)
{
	int			i;
	t_set_item	*max;
	t_set_item	item;
	int			allowed;

	i = 0;
	max = NULL;
	while (i < set->size)
	{
		item = set->items[i];
		allowed = (type == ALL_STACK || item.stack_type == type);
		if (allowed && (!max || item.move > max->move))
			max = &item;
		i++;
	}
	return (max);
}
