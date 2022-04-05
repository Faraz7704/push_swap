/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/05 14:59:32 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_set(t_sset *set, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	// ft_printf("set selected: %d\n", set->id);
	while (i < set->size)
	{
		// ft_printf("(%d) %d ", set->index[i], set->values[i]);
		move_top_stack(set->index[i], a, b);
		run_inst("pb", a, b);
		cal_set_moves(set, a);
		i++;
	}
	// ft_printf("\nb: ");
	// print_numarr(*b);
	set->used = 1;
}

void	sort_big(t_stack *a, t_stack *b, int *sort, int set_size)
{
	t_sset	*sets;
	t_sset	*min_set;

	sets = create_sets(a, sort, set_size);
	// print_sets(sets, sort, set_size);
	while (find_min_set(sets, set_size, &min_set))
	{
		sort_set(min_set, a, b);
		cal_sets_moves(sets, a, set_size);
		// print_sets(sets, sort, set_size);
	}
	while (b->size)
		run_inst("pa", a, b);
	// ft_printf("\na: ");
	// print_numarr(*a);
	free_sets(sets, set_size);
}
