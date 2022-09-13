/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:57:52 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 16:10:39 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_set(t_set set)
{
	int			i;

	i = 0;
	while (i < set.size)
	{
		ft_printf("%d, ", set.values[i]);
		i++;
	}
	ft_printf("\n----------------\n");
}

void	print_sets(t_set *sets, int set_size)
{
	int			i;

	i = 0;
	while (i < set_size)
	{
		ft_printf("id: %d size: %d\n", sets[i].id, sets[i].size);
		print_set(sets[i]);
		i++;
	}
}

void	print_stack(t_stack a, t_stack b)
{
	ft_printf("a: ");
	print_stackarr(a);
	ft_printf("b: ");
	print_stackarr(b);
}

void	print_numarr(int *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_printf("%-5d", a[i++]);
	ft_printf("\n");
}

void	print_stackarr(t_stack a)
{
	t_list	*curr;

	curr = a.lst;
	while (curr)
	{
		ft_printf("%-5d", *(int *)curr->content);
		curr = curr->next;
	}
	ft_printf("\n");
}
