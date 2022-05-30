// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   stack_set.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
// /*   Updated: 2022/05/01 21:03:41 by fkhan            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// static int	init_set(t_sset	*set, int id, int size)
// {
// 	set->id = id;
// 	set->size = size;
// 	set->used = 0;
// 	set->total_moves = 0;
// 	set->index = malloc(sizeof(int) * size);
// 	if (!set->index)
// 		return (0);
// 	set->moves = malloc(sizeof(int) * size);
// 	if (!set->moves)
// 		return (0);
// 	return (1);
// }

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
