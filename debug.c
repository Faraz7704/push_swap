/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:57:52 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/31 14:10:00 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_inst(t_list *abuff)
{
	t_list	*curr_buff;

	curr_buff = abuff;
	while (curr_buff)
	{
		ft_printf("%s ", curr_buff->content);
		curr_buff = curr_buff->next;
	}
	ft_printf("\n");
}

void	print_sets(t_sset *sets, int set_size)
{
	int			i;
	int			j;
	int			c;
	t_set_item	item;

	c = 0;
	i = 0;
	while (i < set_size)
	{
		ft_printf("id: %d total_moves: %d\n", sets[i].id, sets[i].total_moves);
		j = 0;
		while (j < sets[i].size)
		{
			item = sets[i].items[j];
			ft_printf("(%d) %d, ", item.index, item.value);
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
