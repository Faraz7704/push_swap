/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/06 12:56:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_lst(void *content)
{
	free(content);
}

t_list	*del_first_lst(t_list **lst)
{
	t_list	*temp;

	temp = lst[0]->next;
	ft_lstdelone(lst[0], del_lst);
	lst[0] = NULL;
	return (temp);
}

void	del_last_lst(t_list *lst)
{
	t_list	*last;
	t_list	*slast;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	if (size == 0)
		return ;
	if (size == 1)
	{
		last = ft_lstlast(lst);
		ft_lstdelone(last, del_lst);
		return ;
	}
	i = 0;
	slast = lst;
	while (i++ < size - 2)
		slast = slast->next;
	last = ft_lstlast(lst);
	ft_lstdelone(last, del_lst);
	slast->next = NULL;
}

int	*ft_lstdup(t_list *lst, int n)
{
	int		*new;
	int		i;
	t_list	*curr;

	new = malloc(sizeof(int) * n);
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

t_list	*ft_lstindex(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		i++;
		lst = lst->next;
	}
	return (0);
}
