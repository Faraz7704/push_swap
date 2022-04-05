/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/05 16:49:47 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a, t_stack *b)
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

static void	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	len;
	int	min_index;

	i = 0;
	len = a->size - 3;
	while (i++ < len)
	{
		min_index = min_index_stack(a->value, 0, a->size);
		move_top_stack(min_index, a, b);
		run_inst("pb", a, b);
	}
	sort_three(a, b);
	i = 0;
	while (i++ < len)
		run_inst("pa", a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	*sorta;
	int	set_size;

	if (a->size == 2)
		run_inst("sa", a, b);
	else if (a->size == 3)
		sort_three(a, b);
	else if (a->size <= 5)
		sort_five(a, b);
	else
	{
		sorta = ft_numdup(a->value, a->size);
		quicksort(sorta, 0, a->size - 1);
		if (a->size <= 500)
			set_size = 5;
		else
			set_size = 11;
		sort_big(a, b, sorta, set_size);
	}
}
