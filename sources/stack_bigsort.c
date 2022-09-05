/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/06 00:12:43 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_set(t_set	*set, int id, int size)
{
	set->id = id;
	set->size = size;
	set->total_moves = 0;
	set->items = malloc(sizeof(t_st_item) * size);
	if (!set->items)
		return (0);
	return (1);
}

static t_set	*init_sets(int size, int set_size)
{
	int		i;
	int		total_size;
	int		curr_size;
	t_set	*sets;

	sets = malloc(sizeof(t_set) * size);
	if (!sets)
		exit(1);
	total_size = set_size;
	i = 0;
	curr_size = 0;
	while (i < size)
	{
		if (i == size - 1)
			set_size = total_size - curr_size;
		else
			set_size /= 2;
		if (!init_set(&sets[i], i + 1, set_size))
			exit(1);
		curr_size += set_size;
		i++;
	}
	return (sets);
}

static int	get_pivot(t_list *a, int size, int index, int *midpivot)
{
	int	pivot;
	int	*sorted;

	sorted = lstnew_quicksort(a, size);
	if (!sorted)
		exit(1);
	pivot = sorted[index];
	*midpivot = sorted[index / 2];
	free(sorted);
	return (pivot);
}

static void	optimize_b(t_psinfo *info, t_set *set, int pivot)
{
	if (set->id > 1)
		return ;
	if (*(int *)info->b.lst->content <= pivot)
		run_inst("rb", info, 0);
}

static void	add_set(t_psinfo *info, t_set *set)
{
	int	i;
	int	j;
	int	pivot;
	int	midpivot;

	midpivot = 0;
	pivot = get_pivot(info->a.lst, info->a.size, set->size, &midpivot);
	i = 0;
	j = 0;
	while (i < info->a.size && j < set->size)
	{
		if (*(int *)info->a.lst->content < pivot)
		{
			run_inst("pb", info, 0);
			set->items[j].value = *(int *)info->b.lst->content;
			set->items[j].stack_type = info->b.stack_type;
			optimize_b(info, set, midpivot);
			j++;
		}
		else
		{
			run_inst("ra", info, 0);
			i++;
		}
	}
}

static void	quicksort_to_b(t_psinfo *info, t_set *set, int last_set_id)
{
	int		i;
	t_list	*curr;

	add_set(info, set);
	cal_set(set, info);
	if (set->id < last_set_id - 1)
		quicksort_to_b(info, ++set, last_set_id);
	else
	{
		set++;
		i = 0;
		curr = info->a.lst;
		while (curr)
		{
			set->items[i].value = *(int *)curr->content;
			set->items[i].stack_type = A_STACK;
			curr = curr->next;
			i++;
		}
		cal_set(set, info);
	}
}

static int	get_set_size(int size, int min_size)
{
	if (size <= min_size)
		return (1);
	return (get_set_size(size / 2, min_size) + 1);
}

static t_setinfo	*create_sets(t_psinfo *info, int min_set_size)
{
	t_setinfo	*new;

	new = malloc(sizeof(t_setinfo));
	if (!new)
		exit(1);
	new->size = get_set_size(info->a.size, min_set_size);
	new->sets = init_sets(new->size, info->a.size);
	quicksort_to_b(info, new->sets, new->size);
	return (new);
}

static void optimize_move_on_a(t_psinfo *info, int *sorted, int size, int index)
{
	int	stack_size;
	int	first;
	int	second;

	stack_size = info->a.size;
	if (index < stack_size / 2)
		run_inst("ra", info, 0);
	else
		run_inst("rra", info, 0);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, *(int *)info->a.lst->content, size);
	second = find_index_arr(sorted, *(int *)info->a.lst->next->content, size);
	if (first != -1 && second != -1 && first - 1 == second)
		run_inst("sa", info, 0);
}

static int	move_to_b(t_psinfo *info, int *sorted, int size, int index)
{
	int	counter;

	if (!size || !info->a.size)
		return (0);
	counter = 0;
	while (*(int *)info->a.lst->content != sorted[0])
	{
		if (size > 1 && *(int *)info->a.lst->content == sorted[1])
		{
			run_inst("pb", info, 0);
			counter++;
		}
		else
			optimize_move_on_a(info, sorted, size, index);
		if (lst_issorted(info->a.lst, info->a.size))
			return (counter);
	}
	run_inst("pb", info, 0);
	if (counter)
		run_inst("sb", info, 0);
	return (++counter);
}

static void	insertsort_on_a(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;
	int	add_size;
	int	temp;

	i = 0;
	add_size = 0;
	while (i < size)
	{
		index = min_index_stack(info->a.lst, info->a.size);
		temp = move_to_b(info, &sorted[i], size, index);
		add_size += temp;
		if (lst_issorted(info->a.lst, info->a.size))
			break ;
		i += temp;
	}
	i = 0;
	while (i < add_size)
	{
		run_inst("pa", info, 0);
		if (info->a.size > 1 && *(int *)info->a.lst->content
			> *(int *)info->a.lst->next->content)
			run_inst("sa", info, 0);
		i++;
	}
}

static void optimize_move_on_b(t_psinfo *info, int *sorted, int size, int index)
{
	int	stack_size;
	int	first;
	int	second;

	stack_size = info->b.size;
	if (index < stack_size / 2)
		run_inst("rb", info, 0);
	else
		run_inst("rrb", info, 0);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, *(int *)info->b.lst->content, size);
	second = find_index_arr(sorted, *(int *)info->b.lst->next->content, size);
	if (first != -1 && second != -1 && first - 1 == second)
		run_inst("sb", info, 0);
}

static int	move_to_a(t_psinfo *info, int *sorted, int size, int index)
{
	int	counter;

	if (!size || !info->a.size)
		return (0);
	counter = 0;
	while (*(int *)info->b.lst->content != sorted[0])
	{
		if (size > 1 && *(int *)info->b.lst->content == sorted[1])
		{
			run_inst("pa", info, 0);
			counter++;
		}
		else
			optimize_move_on_b(info, sorted, size, index);
	}
	run_inst("pa", info, 0);
	if (counter)
		run_inst("sa", info, 0);
	return (++counter);
}

static void	insertsort_on_b(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;

	i = 0;
	while (i < size)
	{
		index = max_index_stack(info->b.lst, info->b.size);
		i += move_to_a(info, &sorted[i], size, index);
	}
}

static int min_move_index(t_stack *a, int *sorted, int **mask, int size, int *value)
{
	int	i;
	int	min;
	int	*moves;
	int	*indexes;

	moves = malloc(sizeof(int *) * size);
	if (!moves)
		exit(1);
	indexes = malloc(sizeof(int *) * size);
	if (!indexes)
		exit(1);
	i = 0;
	while (i < size)
	{
		if (!mask[0][i])
		{
			indexes[i] = find_index_stack(a->lst, sorted[i], a->size);
			moves[i] = get_moves(*a, indexes[i]);
		}
		else
		{
			indexes[i] = -1;
			moves[i] = -1;
		}
		i++;
	}
	// print_numarr(indexes, size);
	// print_numarr(moves, size);
	min = min_index_arr(moves, size);
	*value = sorted[min];
	mask[0][min] = 1;
	min = indexes[min];
	free(moves);
	free(indexes);
	return (min);
}

static void	divide_on_b(t_psinfo *info, int *sorted, int size, int set_size)
{
	int	i;
	int	value;
	int	index;
	int	*mask;

	mask = malloc(sizeof(int *) * (set_size - (size + 1)));
	if (!mask)
		exit(1);
	i = 0;
	while (i < (set_size - (size + 1)))
		mask[i++] = 0;
	i = size + 1;
	// ft_printf("------\n");
	// ft_printf("i: %d, set_size: %d, size: %d\n", i, set_size, size);
	while (i < set_size)
	{
		// print_stackarr(info->b);
		// print_numarr(&sorted[size + 1], set_size - (size + 1));
		value = 0;
		index = min_move_index(&info->b, &sorted[size + 1], &mask, (set_size - (size + 1)), &value);
		// print_numarr(mask, set_size - (size + 1));
		// ft_printf("index: %d, value: %d\n", index, value);
		if (index == -1)
		{
			ft_printf("here");
			exit(1);
		}
		while (*(int *)info->b.lst->content != value)
		{
			// optimize_move_on_b(info, sorted, size, index);
			if (index < info->b.size / 2)
				run_inst("rb", info, 0);
			else
				run_inst("rrb", info, 0);
		}
		run_inst("pa", info, 0);
		i++;
	}
	free(mask);
}

static void divide_conquer(t_psinfo *info, t_set *set, int min_set_size)
{
	int		*sorted;
	int		*rsorted;
	int		index;
	int		mid_index;
	int		size;
	int		size_temp;
	int		counter;
	int		temp;

	size = set->size;
	counter = 1;
	while (size > min_set_size)
	{
		size /= 2;
		counter++;
	}
	temp = counter;
	sorted = set_sort(set);
	index = 0;
	// ft_printf("size: %d, counter: %d\n", size, counter);
	// print_numarr(sorted, set->size);
	// print_stackarr(info->b);
	while (counter--)
	{
		index = (counter * size);
		if (counter == temp - 1)
			size_temp = set->size - index;
		else
			size_temp = size;
		// print_numarr(&sorted[index], size_temp);
		divide_on_b(info, &sorted[index], size_temp / 2, size_temp);
		mid_index = index + (size_temp / 2) + 1;
		// print_numarr(&sorted[mid_index], size_temp - (mid_index % size));
		// print_stackarr(info->a);
		// print_stackarr(info->b);
		insertsort_on_a(info, &sorted[mid_index], size - (mid_index % size));
		rsorted = num_rsort(&sorted[index], (mid_index % size));
		// print_numarr(rsorted, (mid_index % size));
		// print_stackarr(info->b);
		// ft_printf("---------");
		insertsort_on_b(info, rsorted, (mid_index % size));
		free(rsorted);
	}
	free(sorted);
}
//               0            |                                       
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

static void	insertsort(t_psinfo *info, t_setinfo *setinfo, int min_set_size)
{
	int		i;
	int		*sorted;
	t_set	*set;

	i = setinfo->size - 1;
	set = &setinfo->sets[i];
	sorted = set_sort(set);
	insertsort_on_a(info, sorted, set->size);
	free(sorted);
	i--;
	set = &setinfo->sets[i];
	sorted = set_rsort(set);
	insertsort_on_b(info, sorted, set->size);
	free(sorted);
	i--;
	while (i >= 0)
	{
		set = &setinfo->sets[i];
		divide_conquer(info, set, min_set_size);
		i--;
	}
}

void	stack_bigsort(t_psinfo *info)
{
	t_setinfo	*setinfo;
	int			min_set_size;

	// print_stack(info->a, info->b);
	min_set_size = 15;
	setinfo = create_sets(info, min_set_size);
	// print_sets(setinfo->sets, setinfo->size);
	insertsort(info, setinfo, min_set_size * 2);
	print_stack(info->a, info->b);
	free_sets(setinfo);
}
