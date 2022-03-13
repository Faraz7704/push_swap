/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/13 13:16:33 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	maxnum;
	int	maxbits;

	maxnum = a->size - 1;
	maxbits = 0;
	while ((maxnum >> maxbits) != 0)
		++maxbits;
	i = 0;
	while (i < maxbits)
	{
		j = 0;
		while (j < a->size)
		{
			if (((a->value[0] >> i) & 1) == 1)
				run_inst("ra", a, b);
			else
				run_inst("pb", a, b);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		run_inst("pa", a, b);
		i++;
	}
}
