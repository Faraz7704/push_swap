/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 20:22:00 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quicksort_to_b(t_psinfo *info, t_set *set, int last_set_id)
{
	if (set->id == last_set_id)
	{
		add_set(info, set);
		return ;
	}
	if (set->id == 1)
	{
		add_two_set(info, &set[0], &set[1]);
		set++;
	}
	else
		add_one_set(info, set);
	set++;
	quicksort_to_b(info, set, last_set_id);
}

t_setinfo	*create_sets(t_psinfo *info, int min_set_size)
{
	t_setinfo	*new;

	new = malloc(sizeof(t_setinfo));
	if (!new)
		exit(1);
	new->size = get_set_size(info->a.size, min_set_size);
	if (new->size < 3)
		exit(1);
	new->sets = init_sets(new->size, info->a.size);
	quicksort_to_b(info, new->sets, new->size);
	return (new);
}

int	*num_sort(int *values, int size)
{
	int	*sorted;

	sorted = new_quicksort(values, size);
	if (!sorted)
		exit(1);
	return (sorted);
}

int	*num_rsort(int *values, int size)
{
	int	i;
	int	j;
	int	*sorted;
	int	*rsorted;

	sorted = num_sort(values, size);
	rsorted = malloc(sizeof(int *) * size);
	if (!rsorted)
		exit(1);
	i = size - 1;
	j = 0;
	while (i >= 0)
		rsorted[j++] = sorted[i--];
	free(sorted);
	return (rsorted);
}
