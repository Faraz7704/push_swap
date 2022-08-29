/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/29 19:48:29 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_sort_two(t_psinfo *info)
{
	if (*(int *)info->a.lst->content > *(int *)info->a.lst->next->content)
		run_inst("sa", info, 0);
}

static void	stack_sort_three(t_psinfo *info)
{
	int	*lst;

	lst = ft_lst_to_arr(info->a.lst, info->a.size);
	if (lst[0] > lst[1] && lst[1] < lst[2] && lst[2] > lst[0])
		run_inst("sa", info, 0);
	else if (lst[0] < lst[1] && lst[1] > lst[2] && lst[2] > lst[0])
		run_inst("sa", info, 0);
	else if (lst[0] > lst[1] && lst[1] > lst[2] && lst[2] < lst[0])
		run_inst("sa", info, 0);
	if (lst[0] < lst[1] && lst[1] > lst[2] && lst[2] < lst[0])
		run_inst("rra", info, 0);
	else if (lst[0] > lst[1] && lst[1] < lst[2] && lst[2] < lst[0])
		run_inst("ra", info, 0);
	free(lst);
}

static void	stack_sort_five(t_psinfo *info)
{
	int	i;
	int	len;
	int	min_index;

	i = 0;
	len = info->a.size - 3;
	while (i++ < len)
	{
		min_index = min_index_stack(info->a.lst, info->a.size);
		move_top_stack(min_index, info, 0);
		run_inst("pb", info, 0);
	}
	stack_sort_three(info);
	i = 0;
	while (i++ < len)
		run_inst("pa", info, 0);
}

void	stack_sort(t_psinfo	*info)
{
	if (info->a.size < 2)
		return ;
	if (info->a.size == 2)
		stack_sort_two(info);
	else if (info->a.size == 3)
		stack_sort_three(info);
	else if (info->a.size <= 5)
		stack_sort_five(info);
	else
		stack_bigsort(info);
}
