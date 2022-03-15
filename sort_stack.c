/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/15 19:22:47 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_stack(t_stack *a, t_stack *b)
{
	int	*lst;

	lst = a->value;
	if (lst[0] > lst[1] && lst[1] < lst[2] && lst[2] > lst[0])
		run_inst("sa", a, b);
	else if (lst[0] < lst[1] && lst[1] > lst[2] && lst[2] > lst[0])
		run_inst("sa", a, b);
	else if (lst[0] > lst[1] && lst[1] > lst[2] && lst[2] < lst[0])
		run_inst("sa", a, b);
	if (lst[0] < lst[1] && lst[1] > lst[2] && lst[2] < lst[0])
		run_inst("rra", a, b);
	else if (lst[0] > lst[1] && lst[1] < lst[2] && lst[2] < lst[0])
		run_inst("ra", a, b);
}

static void	sort_five_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	len;

	i = 0;
	len = a->size - 3;
	while (i++ < len)
	{
		move_top_stack(min_index_stack(a), a, b);
		run_inst("pb", a, b);
	}
	sort_three_stack(a, b);
	run_inst("pa", a, b);
	run_inst("pa", a, b);
}

static void	sort_big_stack(t_stack *a, t_stack *b)
{
	a->value[0] = 1;
	b->value[0] = 1;
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		run_inst("sa", a, b);
	else if (a->size == 3)
		sort_three_stack(a, b);
	else if (a->size <= 5)
		sort_five_stack(a, b);
	else
		sort_big_stack(a, b);
}
