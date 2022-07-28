/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/02 14:32:43 by fkhan            ###   ########.fr       */
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
	a->size++;
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
	a->lst = temp->next;
	last->next = temp;
	temp->next = NULL;
	return (1);
}

int	rrot_stack(t_stack *a)
{
	int		i;
	t_list	*second_last;
	t_list	*last;

	if (a->size < 2)
		return (0);
	i = 0;
	second_last = a->lst;
	while (i++ < a->size - 2)
		second_last = second_last->next;
	last = second_last->next;
	last->next = a->lst;
	a->lst = last;
	second_last->next = NULL;
	return (1);
}
