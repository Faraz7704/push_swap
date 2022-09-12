/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 20:45:18 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_issorted(t_list *lst, int n)
{
	int		i;
	int		*sort;
	t_list	*curr;

	sort = lstnew_quicksort(lst, n);
	i = 0;
	curr = lst;
	while (i < n)
	{
		if (*(int *)curr->content != sort[i])
		{
			free(sort);
			return (0);
		}
		i++;
		curr = curr->next;
	}
	free(sort);
	return (1);
}

int	issorted(int *a, int n)
{
	int	i;
	int	*sort;

	sort = new_quicksort(a, n);
	i = 0;
	while (i < n)
	{
		if (a[i] != sort[i])
		{
			free(sort);
			return (0);
		}
		i++;
	}
	free(sort);
	return (1);
}
