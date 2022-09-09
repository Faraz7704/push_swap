/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/09 23:56:46 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_stack(t_list *lst, int value, int n)
{
	int		i;
	t_list	*curr;

	if (!lst || n <= 0)
		return (-1);
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

int	find_index_arr(int *a, int value, int n)
{
	int		i;

	if (!a || n <= 0)
		return (-1);
	i = 0;
	while (i < n)
	{
		if (a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	min_index_arr(int *a, int n)
{
	int		i;
	int		min;
	int		index;

	if (n <= 0)
		return (-1);
	i = 1;
	min = a[0];
	index = 0;
	while (i < n)
	{
		if (a[i] != -1 && (a[i] < min || min == -1))
		{
			min = a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	min_index_stack(t_list *lst, int n)
{
	int		i;
	t_list	*curr;
	t_list	*min;
	int		index;

	if (!lst || n <= 0)
		return (-1);
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

	if (!lst || n <= 0)
		return (-1);
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

t_st_item	*min_move_stack(t_set *set, t_e_stack type)
{
	int			i;
	t_st_item	*min;
	t_st_item	item;
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

t_st_item	*max_move_stack(t_set *set, t_e_stack type)
{
	int			i;
	t_st_item	*max;
	t_st_item	item;
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

void	move_top_stack(int index, t_psinfo *info, int on_b)
{
	int		i;
	char	*rx;
	char	*rrx;
	t_stack	temp;

	rx = "ra";
	rrx = "rra";
	temp = info->a;
	if (on_b)
	{
		rx = "rb";
		rrx = "rrb";
		temp = info->b;
	}
	if (index <= (temp.size / 2))
	{
		i = 0;
		while (i++ < index)
			run_inst(rx, info, 0);
		return ;
	}
	i = temp.size - 1;
	while (i-- >= index)
		run_inst(rrx, info, 0);
}
