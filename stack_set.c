/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/01 12:37:39 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_set(t_sset	*set, int id, int size)
{
	set->id = id;
	set->size = size;
	set->total_moves = 0;
	set->items = malloc(sizeof(t_set_item) * size);
	if (!set->items)
		return (0);
	return (1);
}

int	set_type_size(t_sset *set, t_e_stack type)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < set->size)
	{
		if (set->items[i].stack_type == type)
			len++;
		i++;
	}
	return (len);
}

static void	fill_items(t_set_item *items, t_stack *a, int *value, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		items[i].value = value[i];
		items[i].stack_type = a->stack_type;
		i++;
	}
}

static int	get_set_size(int size)
{
	if (size <= 0)
		return (0);
	return (get_set_size(size / 2) + 1);
}

t_sset	*create_sets(t_stack *a, int *reflen)
{
	int		i;
	int		size;
	int		index;
	t_sset	*sets;
	int		*sort;

	sort = lstnew_quicksort(a->lst, a->size);
	*reflen = get_set_size(a->size);
	sets = malloc(sizeof(t_sset) * *reflen);
	if (!sets)
		return (0);
	index = 0;
	size = a->size;
	i = 0;
	while (i < *reflen)
	{
		size /= 2;
		if (i == *reflen - 1)
			size = a->size - index;
		if (!init_set(&sets[i], i + 1, size))
			return (0);
		fill_items(sets[i].items, a, &sort[index], size);
		cal_set(&sets[i], a, NULL);
		index += size;
		i++;
	}
	return (sets);
}

// t_sset	*create_sets(t_stack *a, int *sort, int set_size, int *reflen)
// {
// 	int		i;
// 	int		temp;
// 	int		index;
// 	t_sset	*sets;

// 	*reflen = set_size;
// 	if (a->size % set_size)
// 		*reflen += 1;
// 	sets = malloc(sizeof(t_sset) * *reflen);
// 	if (!sets)
// 		return (0);
// 	index = 0;
// 	i = 0;
// 	while (i < *reflen)
// 	{
// 		temp = a->size / set_size;
// 		if (i == *reflen - 1 && a->size % set_size)
// 			temp = a->size % set_size;
// 		if (!init_set(&sets[i], i + 1, temp))
// 			return (0);
// 		sets[i].values = &sort[index];
// 		cal_set(&sets[i], a);
// 		index += sets[i].size;
// 		i++;
// 	}
// 	return (sets);
// }

// int	find_min_set(t_sset *s, int set_size, t_sset **res)
// {
// 	int		i;
// 	int		m;

// 	if (set_size <= 0)
// 		return (0);
// 	m = -1;
// 	i = 0;
// 	while (i < set_size)
// 	{
// 		if (!s[i].used && (m == -1 || s[m].total_moves > s[i].total_moves))
// 			m = i;
// 		i++;
// 	}
// 	if (m == -1)
// 		return (0);
// 	res[0] = &s[m];
// 	return (1);
// }
