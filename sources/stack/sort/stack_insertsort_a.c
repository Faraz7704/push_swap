/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertsort_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 20:16:14 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_move_on_a(t_psinfo *info, int *sorted, int size, int index)
{
	int	stack_size;
	int	first;
	int	second;

	stack_size = info->a.size;
	if (index < stack_size / 2)
		run_buff_inst("ra", info, 1);
	else
		run_buff_inst("rra", info, 1);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, *(int *)info->a.lst->content, size);
	second = find_index_arr(sorted, *(int *)info->a.lst->next->content, size);
	if (first != -1 && second != -1 && first - 1 == second)
		run_buff_inst("sa", info, 1);
}

static int	move_to_b(t_psinfo *info, int *sorted, int size, int index)
{
	int	counter;

	if (!size || !info->a.size)
		return (0);
	counter = 0;
	while (*(int *)info->a.lst->content != sorted[0])
	{
		if (size > 1 && *(int *)info->a.lst->content == sorted[1])
		{
			run_buff_inst("pb", info, 1);
			counter++;
		}
		else
			optimize_move_on_a(info, sorted, size, index);
		if (lst_issorted(info->a.lst, info->a.size))
			return (counter);
	}
	run_buff_inst("pb", info, 1);
	if (counter)
		run_buff_inst("sb", info, 1);
	return (++counter);
}

void	insertsort_on_a(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;
	int	add_size;
	int	temp;

	i = 0;
	add_size = 0;
	while (i < size)
	{
		index = min_index_stack(info->a.lst, info->a.size);
		temp = move_to_b(info, &sorted[i], size, index);
		add_size += temp;
		if (lst_issorted(info->a.lst, info->a.size))
			break ;
		i += temp;
	}
	i = 0;
	while (i < add_size)
	{
		run_buff_inst("pa", info, 1);
		if (info->a.size > 1 && *(int *)info->a.lst->content
			> *(int *)info->a.lst->next->content)
			run_buff_inst("sa", info, 1);
		i++;
	}
}
