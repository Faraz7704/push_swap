/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/16 18:33:01 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_distri(t_stack *a, t_stack *b)
{

}

void	sort_big(t_stack *a, t_stack *b, int *sort, int set_size)
{
	int	i;
	int	elem_size;
	int	min_index;
	int	temp;

	elem_size = a->size / set_size;
	i = 0;
	while (i < set_size)
	{
		while (b->size < elem_size * (i + 1))
		{
			min_index = min_index_stack(a->value[0], 0, a->size);
		}
		i++;
	}
}
