/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 20:58:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_set(t_set	*set, int id, int size)
{
	set->id = id;
	set->size = size;
	set->values = malloc(sizeof(int) * size);
	if (!set->values)
		return (0);
	return (1);
}

static t_set	*malloc_set(int size)
{
	t_set	*sets;

	sets = malloc(sizeof(t_set) * size);
	if (!sets)
		exit(1);
	return (sets);
}

t_set	*init_sets(int size, int set_size)
{
	int		i;
	int		total_size;
	int		curr_size;
	t_set	*sets;

	sets = malloc_set(size);
	total_size = set_size;
	i = 0;
	curr_size = 0;
	while (i < size)
	{
		if (i == size - 1)
			set_size = total_size - curr_size;
		else if (i == 0)
			set_size /= 4;
		else if (i == 1)
			set_size = (total_size / 2) - curr_size;
		else if (i != 2)
			set_size /= 2;
		if (!init_set(&sets[i], i + 1, set_size))
			exit(1);
		curr_size += set_size;
		i++;
	}
	return (sets);
}

void	free_sets(t_setinfo *info)
{
	int	i;

	i = 0;
	while (i < info->size)
	{
		free(info->sets[i].values);
		i++;
	}
	free(info->sets);
	free(info);
}
