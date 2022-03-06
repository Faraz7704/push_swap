/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/06 14:46:13 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(int *a, int *b, int n)
{
	int	i;
	int	j;
	int	maxnum;
	int	maxbits;

	maxnum = n - 1;
	maxbits = 0;
	while ((maxnum >> maxbits) != 0)
		++maxbits;
	i = 0;
	while (i < maxbits)
	{
		j = 0;
		while (j < n)
		{
			if (((a[0] >> i) & 1) == 1)
				run_inst("ra", a, b, n);
			else
				run_inst("pb", a, b, n);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		run_inst("pa", a, b, n);
		i++;
	}
}
