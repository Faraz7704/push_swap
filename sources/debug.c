/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:57:52 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 15:41:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_inst(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		ft_printf("%s\n", (char *)curr->content);
		curr = curr->next;
	}
}

void	print_combine_inst(t_list *lst)
{
	t_list	*new;

	new = combine_inst_lst(lst);
	if (!new)
		return ;
	print_inst(new);
	ft_lstclear(&new, ft_lstdel);
}

void	print_set(t_set set)
{
	int			i;
	t_st_item	item;

	i = 0;
	while (i < set.size)
	{
		item = set.items[i];
		ft_printf("(%d) %d %d, ", item.index, item.value, item.stack_type);
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
		ft_printf("id: %d size: %d total_moves: %d", sets[i].id, sets[i].size);
		ft_printf(" total_moves: %d\n", sets[i].total_moves);
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
