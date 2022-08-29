/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/29 19:43:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	fill_items(t_st_item *items, t_stack *a, int *value, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		items[i].value = value[i];
// 		items[i].stack_type = a->stack_type;
// 		i++;
// 	}
// }

// t_set	*create_sets(t_psinfo *info, int *set_size, int min_size)
// {
// 	int		i;
// 	int		size;
// 	int		index;
// 	t_set	*sets;
// 	int		*sort;

// 	sort = lstnew_quicksort(info->a.lst, info->a.size);
// 	*set_size = get_set_size(info->a.size, min_size);
// 	sets = malloc(sizeof(t_set) * *set_size);
// 	if (!sets)
// 		return (0);
// 	index = 0;
// 	size = info->a.size;
// 	i = 0;
// 	while (i < *set_size)
// 	{
// 		size /= 2;
// 		if (i == *set_size - 1)
// 			size = info->a.size - index;
// 		if (!init_set(&sets[i], i + 1, size))
// 			return (0);
// 		fill_items(sets[i].items, &info->a, &sort[index], size);
// 		cal_set(&sets[i], info);
// 		index += size;
// 		i++;
// 	}
// 	return (sets);
// }
