/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/01 23:11:57 by fkhan            ###   ########.fr       */
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
