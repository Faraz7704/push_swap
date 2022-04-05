/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/05 23:48:45 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_set(t_sset *set, t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	while (i < set->size)
	{
		min_index = min_moves_stack(set);
		ft_printf("\n: ");
		j = 0;
		while (j < set->size)
		{
			ft_printf("%d => %d ", set->index[j], set->moves[j]);
			j++;
		}
		ft_printf("\n");
		move_top_stack(set->index[min_index], a, b);
		ft_printf("set index: %d\n", set->index[min_index]);
		run_inst("pb", a, b);
		cal_set(set, a);
		i++;
	}
	set->used = 1;
}

void	sort_big(t_stack *a, t_stack *b, int *sort, int set_size)
{
	int		i;
	int		max_index;
	t_sset	*sets;

	sets = create_sets(a, sort, set_size);
	// print_sets(sets, sort, set_size);
	i = 0;
	while (i < set_size)
	{
		// ft_printf("set selected: %d\n", min_set->id);
		sort_set(&sets[i], a, b);
		ft_printf("\nb: ");
		print_numarr(*b);
		cal_sets(sets, a, set_size);
		// print_sets(sets, sort, set_size);
		i++;
	}
	while (b->size)
	{
		max_index = max_index_stack(b->value, 0, b->size);
		move_top_stack(max_index, a, b);
		run_inst("pa", a, b);
	}
	ft_printf("\na: ");
	print_numarr(*a);
	free_sets(sets, set_size);
}
