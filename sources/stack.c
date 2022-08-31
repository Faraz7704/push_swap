/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/31 16:46:05 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int *a, int n, t_e_stack type)
{
	int			i;
	t_list		*lst;
	t_stack		new;

	if (n > 0 && a)
	{
		lst = ft_lstnew(&a[0]);
		i = 1;
		while (i < n)
		{
			ft_lstadd_back(&lst, ft_lstnew(&a[i]));
			i++;
		}
		new.lst = lst;
	}
	else
		new.lst = NULL;
	new.size = n;
	new.stack_type = type;
	return (new);
}

void	free_stack(t_stack *a)
{
	if (a->lst)
		ft_lstclear(&a->lst, ft_lstdel);
}
