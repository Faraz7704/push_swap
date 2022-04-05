/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:57:52 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/05 14:27:58 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sets(t_sset *sets, int *sort, int set_size)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	while (i < set_size)
	{
		ft_printf("id: %d total_moves: %d\n", sets[i].id, sets[i].total_moves);
		j = 0;
		while (j < sets[i].size)
		{
			ft_printf("(%d) %d, ", sets[i].index[j], sort[c]);
			j++;
			c++;
		}
		ft_printf("\n----------------\n");
		i++;
	}
}

void	print_stack(t_stack a, t_stack b)
{
	ft_printf("a: ");
	print_numarr(a);
	ft_printf("b: ");
	print_numarr(b);
}

void	print_numarr(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.size)
		ft_printf("%-5d", a.value[i++]);
	ft_printf("\n");
}
