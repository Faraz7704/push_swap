/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 21:03:59 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_pivot(t_list *a, int size, int index)
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
