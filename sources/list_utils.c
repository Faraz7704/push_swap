/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/30 18:37:55 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdel(void *content)
{
	free(content);
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
