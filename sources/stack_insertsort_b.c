/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertsort_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 20:15:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_move_on_b(t_psinfo *info, int *sorted, int size, int index)
{
	int	stack_size;
	int	first;
	int	second;

	stack_size = info->b.size;
	if (index < stack_size / 2)
		run_buff_inst("rb", info, 1);
	else
		run_buff_inst("rrb", info, 1);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, *(int *)info->b.lst->content, size);
	second = find_index_arr(sorted, *(int *)info->b.lst->next->content, size);
	if (first != -1 && second != -1 && first - 1 == second)
		run_buff_inst("sb", info, 1);
}

static int	move_to_a(t_psinfo *info, int *sorted, int size, int index)
{
	int	counter;

	if (!size || !info->a.size)
		return (0);
	counter = 0;
	while (*(int *)info->b.lst->content != sorted[0])
	{
		if (size > 1 && *(int *)info->b.lst->content == sorted[1])
		{
			run_buff_inst("pa", info, 1);
			counter++;
		}
		else
			optimize_move_on_b(info, sorted, size, index);
	}
	run_buff_inst("pa", info, 1);
	if (counter)
		run_buff_inst("sa", info, 1);
	return (++counter);
}

void	insertsort_on_b(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;

	i = 0;
	while (i < size)
	{
		index = max_index_stack(info->b.lst, info->b.size);
		i += move_to_a(info, &sorted[i], size, index);
	}
}
