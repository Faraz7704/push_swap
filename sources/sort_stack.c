/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/31 14:19:42 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *a, t_stack *b)
{
	if (*(int *)a->lst->content > *(int *)a->lst->next->content)
		run_inst("sa", a, b, 0);
}

static void	sort_three(t_stack *a, t_stack *b)
{
	int	*lst;

	lst = ft_lstdup(a->lst, a->size);
	if (lst[0] > lst[1] && lst[1] < lst[2] && lst[2] > lst[0])
		run_inst("sa", a, b, 0);
	else if (lst[0] < lst[1] && lst[1] > lst[2] && lst[2] > lst[0])
		run_inst("sa", a, b, 0);
	else if (lst[0] > lst[1] && lst[1] > lst[2] && lst[2] < lst[0])
		run_inst("sa", a, b, 0);
	if (lst[0] < lst[1] && lst[1] > lst[2] && lst[2] < lst[0])
		run_inst("rra", a, b, 0);
	else if (lst[0] > lst[1] && lst[1] < lst[2] && lst[2] < lst[0])
		run_inst("ra", a, b, 0);
	free(lst);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	len;
	int	min_index;

	i = 0;
	len = a->size - 3;
	while (i++ < len)
	{
		min_index = min_index_stack(a->lst, a->size);
		move_top_stack(min_index, a, b, 0);
		run_inst("pb", a, b, 0);
	}
	sort_three(a, b);
	i = 0;
	while (i++ < len)
		run_inst("pa", a, b, 0);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a, b);
	else if (a->size == 3)
		sort_three(a, b);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}
