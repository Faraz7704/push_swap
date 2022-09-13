/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 16:13:46 by fkhan            ###   ########.fr       */
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

void	stack_bigsort(t_psinfo *info)
{
	t_setinfo	*setinfo;

	setinfo = create_sets(info, 15);
	divide_conquer(info, setinfo, 20);
	print_combine_inst(info->inst_buff);
	free_sets(setinfo);
}
