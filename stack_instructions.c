/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/30 17:06:49 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_stack *a)
{
	t_list	*temp;

	if (a->size < 2)
		return (0);
	temp = a->lst->next;
	a->lst->next = temp->next;
	temp->next = a->lst;
	a->lst = temp;
	return (1);
}

int	push_stack(t_stack *a, t_stack *b)
{
	t_list	*temp;

	if (!b->size)
		return (0);
	temp = b->lst;
	b->lst = b->lst->next;
	temp->next = a->lst;
	a->lst = temp;
	b->size--;
	return (1);
}

int	rot_stack(t_stack *a)
{
	t_list	*temp;
	t_list	*last;

	if (a->size < 2)
		return (0);
	last = ft_lstlast(a->lst);
	temp = a->lst;
	a->lst = a->lst->next;
	last->next = temp;
	return (1);
}

int	rrot_stack(t_stack *a)
{
	int		i;
	t_list	*temp;
	t_list	*last;

	if (a->size < 2)
		return (0);
	last = ft_lstlast(a->lst);
	i = 0;
	temp = a->lst;
	while (i < a->size - 1)
		temp = temp->next;
	temp->next = NULL;
	last->next = a->lst;
	a->lst = last;
	return (1);
}
