/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/04 18:33:31 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_set(t_sset **set, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("set selected: %d\n", set[0]->id);
	while (i < set[0]->size)
	{
		ft_printf("index: %d\n", set[0]->id);
		move_top_stack(set[0]->index[i], a, b);
		run_inst("pb", a, b);
		i++;
	}
	ft_printf("b: ");
	print_numarr(*b);
	set[0]->used = 1;
}

void	sort_big(t_stack *a, t_stack *b, int *sort, int set_size)
{
	t_sset	*sets;
	t_sset	*min_set;

	sets = create_sets(a, sort, set_size);
	while (find_min_set(sets, set_size, &min_set))
	{
		sort_set(&min_set, a, b);
		cal_sets_moves(sets, a, sort, set_size);
	}
	while (b->size)
		run_inst("pa", a, b);
	// print_sets(sets, sort, set_size);
	free_sets(sets, set_size);
	run_inst("error", a, b);
}
