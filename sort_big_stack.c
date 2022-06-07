/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/07 19:09:01 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_values(t_set_item *items, int n)
{
	int	*values;
	int	*sort;

	values = new_item_values(items, n);
	sort = new_quicksort(values, n);
	free(values);
	return (sort);
}

static void	set_to_b(t_sset *set, t_stack *a, t_stack *b)
{
	int			i;
	int			index;
	int			*sort;
	int			pivot;

	sort = sort_values(set->items, set->size);
	pivot = sort[set->size / 2];
	i = 0;
	while (i < set->size)
	{
		index = min_index_set(set->items, A_STACK, set->size);
		if (index == -1)
		{
			i++;
			continue ;
		}
		set->items[index].stack_type = B_STACK;
		index = set->items[index].index;
		move_top_stack(index, a, b, 0);
		run_inst("pb", a, b, 0);
		cal_set(set, a, b);
		if (set->id == 1 && b->size > 1 && *(int *)b->lst->content < pivot)
			run_inst("rb", a, b, 0);
		i++;
	}
}

static int	find_index_arr(int *a, int value, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int	sort_in_a(int *values, int n, t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	int	*sort;
	int	first_index;
	int	second_index;
	int	record;
	int	len;
	int	flag;

	sort = new_quicksort(values, n);
	i = 0;
	record = 0;
	flag = 1;
	while (i < n)
	{
		index = min_index_stack(a->lst, a->size);
		len = get_moves(a, index);
		if (!len)
		{
			run_inst("pb", a, b, 0);
			record++;
			if (b->size > 1 && *(int *)b->lst->content < *(int *)b->lst->next->content)
				run_inst("sb", a, b, 0);
			if (lst_issorted(a->lst, a->size))
			{
				free(sort);
				return (record);
			}
		}
		while (len--)
		{
			if (index <= a->size / 2)
				run_inst("ra", a, b, 0);
			else
				run_inst("rra", a, b, 0);
			first_index = find_index_arr(sort, *(int *)a->lst->content, n);
			second_index = find_index_arr(sort, *(int *)a->lst->next->content, n);
			if (first_index == second_index + 1)
				run_inst("sa", a, b, 0);
			if (lst_issorted(a->lst, a->size))
			{
				free(sort);
				return (record);
			}
			if ((flag && first_index < record + 2) || (!flag && first_index < record + 1))
			{
				flag = first_index == record;
				run_inst("pb", a, b, 0);
				record++;
				len--;
				if (b->size > 1 && *(int *)b->lst->content < *(int *)b->lst->next->content)
					run_inst("sb", a, b, 0);
				index = min_index_stack(a->lst, a->size);
				if (*(int *)a->lst->content == *(int *)(ft_lstindex(a->lst, index)->content))
				{
					i--;
					break ;
				}
			}
			if (lst_issorted(a->lst, a->size))
			{
				free(sort);
				return (record);
			}
		}
		i++;
	}
	free(sort);
	return (record);
}

static int	find_index_item(t_set_item *items, int value, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (items[i].value == value)
			return (1);
		i++;
	}
	return (0);
}

static int	sort_in_b(t_sset *set, int *values, int n, t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	int	*sort;
	int	first_index;
	int	second_index;
	int	record;
	int	len;
	int	flag;

	sort = new_quicksort(values, n);
	i = 0;
	record = 0;
	flag = 1;
	index = max_index_stack(b->lst, b->size);
	while (index != -1 && find_index_item(set->items, *(int *)ft_lstindex(b->lst, index)->content, n))
	{
		len = get_moves(b, index);
		if (!len)
		{
			run_inst("pa", a, b, 0);
			record++;
			if (a->size > 1 && *(int *)a->lst->content > *(int *)a->lst->next->content)
				run_inst("sa", a, b, 0);
		}
		while (len--)
		{
			if (index <= b->size / 2)
				run_inst("rb", a, b, 0);
			else
				run_inst("rrb", a, b, 0);
			first_index = find_index_arr(sort, *(int *)b->lst->content, n);
			second_index = find_index_arr(sort, *(int *)b->lst->next->content, n);
			if (first_index == second_index - 1)
				run_inst("sb", a, b, 0);
			if ((flag && first_index >= n - record + 2) || (!flag && first_index >= n - record + 1))
			{
				flag = first_index == n - 1;
				run_inst("pa", a, b, 0);
				record++;
				len--;
				if (a->size > 1 && *(int *)a->lst->content > *(int *)a->lst->next->content)
					run_inst("sa", a, b, 0);
				index = max_index_stack(b->lst, b->size);
				if (*(int *)b->lst->content == *(int *)(ft_lstindex(b->lst, index)->content))
				{
					i--;
					break ;
				}
			}
		}
		i++;
		index = max_index_stack(b->lst, b->size);
	}
	free(sort);
	return (record);
}

static int	**split_set(t_sset *set, t_stack *a, t_stack *b)
{
	int	i[3];
	int	pivot;
	int	*sort;
	int	**split;
	int	true_size;

	sort = sort_values(set->items, set->size);
	true_size = set_type_size(set, B_STACK);
	pivot = sort[true_size / 2];
	free (sort);
	split = (int **)malloc(sizeof(int *) * 2);
	if (!split)
		return (0);
	split[0] = malloc(sizeof(int) * true_size - (true_size / 2));
	if (!split[0])
		return (0);
	split[1] = malloc(sizeof(int) * true_size / 2);
	if (!split[1])
		return (0);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < true_size)
	{
		if (*(int *)b->lst->content > pivot)
		{
			split[0][i[1]] = *(int *)b->lst->content;
			run_inst("pa", a, b, 0);
			i[1]++;
		}
		else
		{
			split[1][i[2]] = *(int *)b->lst->content;
			i[2]++;
			run_inst("rb", a, b, 0);
		}
		i[0]++;
	}
	while (i[2]--)
		run_inst("rrb", a, b, 0);
	return (split);
}

static void	sort_midpoint(t_sset *set, t_stack *a, t_stack *b, int for_b)
{
	int	*sort;
	int	**split;
	int	true_size;
	int	record;

	if (for_b == 2)
	{
		true_size = set_type_size(set, B_STACK);
		split = split_set(set, a, b);
		record = sort_in_a(split[0], true_size / 2, a, b);
		while (record--)
		{
			run_inst("pa", a, b, 0);
			if (a->size > 1 && *(int *)a->lst->content > *(int *)a->lst->next->content)
				run_inst("sa", a, b, 0);
		}
		record = (true_size - (true_size / 2)) - sort_in_b(set, split[1], true_size - (true_size / 2), a, b);
		while (record--)
			run_inst("pa", a, b, 0);
		free(split[0]);
		free(split[1]);
		free(split);
	}
	else if (for_b == 1)
	{
		sort = sort_values(set->items, set->size);
		true_size = set_type_size(set, B_STACK);
		record = true_size - sort_in_b(set, sort, true_size, a, b);
		while (record--)
			run_inst("pa", a, b, 0);
		free (sort);
	}
	else
	{
		sort = sort_values(set->items, set->size);
		true_size = set_type_size(set, A_STACK);
		record = sort_in_a(sort, true_size, a, b);
		while (record--)
			run_inst("pa", a, b, 0);
		free (sort);
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		set_size;
	t_sset	*sets;

	sets = create_sets(a, &set_size);
	i = 0;
	while (i < set_size - 1)
	{
		set_to_b(&sets[i], a, b);
		cal_sets(sets, a, b, set_size);
		i++;
	}
	i = set_size - 1;
	// while (i >= 0)
	// {
		sort_midpoint(&sets[i--], a, b, 0);
		sort_midpoint(&sets[i--], a, b, 1);
		sort_midpoint(&sets[i--], a, b, 2);
		sort_midpoint(&sets[i--], a, b, 2);
	// 	i++;
	// }
	free_sets(sets, set_size);
}
