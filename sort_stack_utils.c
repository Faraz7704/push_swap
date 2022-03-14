/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/14 18:19:21 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index_stack(t_stack *a)
{
	int	i;
	int	min;

	i = 1;
	min = 0;
	while (i < a->size)
	{
		if (a->value[i] < a->value[min])
			min = i;
		i++;
	}
	return (min);
}

int	max_index_stack(t_stack *a)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i < a->size)
	{
		if (a->value[i] > a->value[max])
			max = i;
		i++;
	}
	return (max);
}

void	move_top_stack(int index, t_stack *a, t_stack *b)
{
	int	i;

	if (index <= (a->size / 2))
	{
		i = 0;
		while (i++ < index)
			run_inst("ra", a, b);
	}
	else
	{
		i = a->size - 1;
		while (i-- >= index)
			run_inst("rra", a, b);
	}
}
