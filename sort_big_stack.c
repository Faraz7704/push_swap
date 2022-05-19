/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/19 19:36:39 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(t_stack *a, t_stack *b, int forA)
{
	int	i;
	int	*sorta;

	i = 0;
	while (i < a->size)
	{
		sorta = ft_numdup(a->value, a->size);
		quicksort(sorta, 0, a->size - 1);
	}
}

static void	midpoint(t_stack *a, t_stack *b, int start, int end)
{
	int	pivot;
	int	*sorta;

	while (a->size > 2)
	{
		sorta = ft_numdup(a->value, a->size);
		quicksort(sorta, 0, a->size - 1);
		pivot = sorta[a->size / 2];
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		*sort;
	t_sset	*sets;
	int		set_size;

	sort = ft_numdup(a->value, a->size);
	quicksort(sort, 0, a->size - 1);
	sets = create_sets(a, sort, &set_size);
}
