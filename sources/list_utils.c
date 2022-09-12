/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 19:11:57 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstnumdel(void *content)
{
	(void)content;
}

void	ft_lstdel(void *content)
{
	free(content);
}

void	ft_lstdellast(t_list *lst)
{
	int		i;
	t_list	*last;
	t_list	*sec_last;

	if (!lst)
		return ;
	last = lst;
	sec_last = NULL;
	i = ft_lstsize(lst) - 1;
	while (i > 0)
	{
		if (i-- == 1)
			sec_last = last;
		last = last->next;
	}
	ft_lstdelone(last, ft_lstdel);
	if (!sec_last)
		sec_last->next = NULL;
}

int	*ft_lst_to_arr(t_list *lst, int n)
{
	int		*new;
	int		i;
	t_list	*curr;

	new = malloc(sizeof(int *) * n);
	if (!new)
		return (0);
	curr = lst;
	i = 0;
	while (i < n)
	{
		new[i] = *(int *)curr->content;
		curr = curr->next;
		i++;
	}
	return (new);
}
