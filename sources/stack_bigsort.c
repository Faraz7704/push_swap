/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 19:13:46 by fkhan            ###   ########.fr       */
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
		else if (i == 0)
			set_size /= 4;
		else if (i == 1)
			set_size = (total_size / 2) - curr_size ;
		else if (i != 2)
			set_size /= 2;
		if (!init_set(&sets[i], i + 1, set_size))
			exit(1);
		curr_size += set_size;
		i++;
	}
	return (sets);
}

static int	get_pivot(t_list *a, int size, int index)
{
	int	pivot;
	int	*sorted;

	sorted = lstnew_quicksort(a, size);
	if (!sorted)
		exit(1);
	pivot = sorted[index];
	free(sorted);
	return (pivot);
}

static void	set_item(t_st_item *item, int value, t_e_stack type)
{
	item->value = value;
	item->stack_type = type;
}

static void	add_one_set(t_psinfo *info, t_set *set)
{
	int	i;
	int	j;
	int	pivot;

	pivot = get_pivot(info->a.lst, info->a.size, set->size);
	i = 0;
	j = 0;
	while (i < info->a.size && j < set->size)
	{
		if (*(int *)info->a.lst->content < pivot)
		{
			run_buff_inst("pb", info, 1);
			set_item(&set->items[j], *(int *)info->b.lst->content, B_STACK);
			j++;
		}
		else
		{
			run_buff_inst("ra", info, 1);
			i++;
		}
	}
	cal_set(set, info);
}

static int	set_items(t_psinfo *info, t_st_item *item1,
	t_st_item *item2, int midpivot)
{
	if (*(int *)info->b.lst->content < midpivot)
	{
		set_item(item1, *(int *)info->b.lst->content, B_STACK);
		run_buff_inst("rb", info, 1);
		return (1);
	}
	set_item(item2, *(int *)info->b.lst->content, B_STACK);
	return (0);
}

static void	add_two_set(t_psinfo *info, t_set *set1, t_set *set2)
{
	int	i[3];
	int	pivot;
	int	midpivot;
	int	size;

	size = set1->size + set2->size;
	pivot = get_pivot(info->a.lst, info->a.size, size);
	midpivot = get_pivot(info->a.lst, info->a.size, size / 2);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < info->a.size && i[1] + i[2] < size)
	{
		if (*(int *)info->a.lst->content < pivot)
		{
			run_buff_inst("pb", info, 1);
			if (set_items(info, &set1->items[i[1]], &set2->items[i[2]], midpivot))
				i[1]++;
			else
				i[2]++;
		}
		else
		{
			run_buff_inst("ra", info, 1);
			i[0]++;
		}
	}
	cal_set(set1, info);
	cal_set(set2, info);
}

static void add_set(t_psinfo *info, t_set *set)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = info->a.lst;
	while (curr)
	{
		set_item(&set->items[i], *(int *)curr->content, A_STACK);
		curr = curr->next;
		i++;
	}
	cal_set(set, info);
}

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

static int	get_set_size(int size, int min_size)
{
	if (size <= min_size)
		return (2);
	return (get_set_size(size / 2, min_size) + 1);
}

static t_setinfo	*create_sets(t_psinfo *info, int min_set_size)
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

static void optimize_move_on_a(t_psinfo *info, int *sorted, int size, int index)
{
	int	stack_size;
	int	first;
	int	second;

	stack_size = info->a.size;
	if (index < stack_size / 2)
		run_buff_inst("ra", info, 1);
	else
		run_buff_inst("rra", info, 1);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, *(int *)info->a.lst->content, size);
	second = find_index_arr(sorted, *(int *)info->a.lst->next->content, size);
	if (first != -1 && second != -1 && first - 1 == second)
		run_buff_inst("sa", info, 1);
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
			run_buff_inst("pb", info, 1);
			counter++;
		}
		else
			optimize_move_on_a(info, sorted, size, index);
		if (lst_issorted(info->a.lst, info->a.size))
			return (counter);
	}
	run_buff_inst("pb", info, 1);
	if (counter)
		run_buff_inst("sb", info, 1);
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
		run_buff_inst("pa", info, 1);
		if (info->a.size > 1 && *(int *)info->a.lst->content
			> *(int *)info->a.lst->next->content)
			run_buff_inst("sa", info, 1);
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
		run_buff_inst("rb", info, 1);
	else
		run_buff_inst("rrb", info, 1);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, *(int *)info->b.lst->content, size);
	second = find_index_arr(sorted, *(int *)info->b.lst->next->content, size);
	if (first != -1 && second != -1 && first - 1 == second)
		run_buff_inst("sb", info, 1);
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
			run_buff_inst("pa", info, 1);
			counter++;
		}
		else
			optimize_move_on_b(info, sorted, size, index);
	}
	run_buff_inst("pa", info, 1);
	if (counter)
		run_buff_inst("sa", info, 1);
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

static int	divide_on_b(t_psinfo *info, int *sorted, int set_size, int mid_index)
{
	int	i[3];
	int	pivot;

	pivot = sorted[mid_index];
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < set_size && i[1] < mid_index)
	{
		if (*(int *)info->b.lst->content > pivot)
		{
			run_buff_inst("pa", info, 1);
			i[1]++;
		}
		else
		{
			run_buff_inst("rb", info, 1);
			i[2]++;
		}
		i[0]++;
	}
	return (i[2]);
}

static int	divide_on_a(t_psinfo *info, int *sorted, int set_size, int mid_index)
{
	int	i[3];
	int	pivot;

	pivot = sorted[mid_index];
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < set_size && i[1] < mid_index)
	{
		if (*(int *)info->a.lst->content < pivot)
		{
			run_buff_inst("pb", info, 1);
			i[1]++;
		}
		else
		{
			run_buff_inst("ra", info, 1);
			i[2]++;
		}
		i[0]++;
	}
	return (i[2]);
}

static void	reverse_move(t_psinfo *info, char *f, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		run_buff_inst(f, info, 1);
		i++;
	}
}

void divide_conquer_a(t_psinfo *info, int *sorted, int size, int min_size)
{
	int	mid_index;
	int	moves;

	if (size <= min_size)
		return ;
	mid_index = (size / 2);
	moves = divide_on_a(info, sorted, size, mid_index);
	if (size - mid_index > min_size)
		reverse_move(info, "rra", moves);
	divide_conquer_a(info, &sorted[mid_index], size - mid_index, min_size);
	insertsort_on_a(info, &sorted[mid_index], size - mid_index);
	divide_conquer_b(info, sorted, mid_index, min_size);
}

void divide_conquer_b(t_psinfo *info, int *sorted, int size, int min_size)
{
	int	mid_index;
	int	*rsorted;
	int	moves;

	if (size <= min_size)
	{
		rsorted = num_rsort(sorted, size);
		insertsort_on_b(info, rsorted, size);
		free(rsorted);
		return ;
	}
	mid_index = (size / 2) + 1;
	moves = divide_on_b(info, sorted, size, mid_index - 1);
	divide_conquer_a(info, &sorted[mid_index], size - mid_index, min_size);
	insertsort_on_a(info, &sorted[mid_index], size - mid_index);
	if (size - mid_index > min_size)
		reverse_move(info, "rrb", moves);
	divide_conquer_b(info, sorted, mid_index, min_size);
}

static void	insertsort(t_psinfo *info, t_setinfo *setinfo, int min_size)
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
		sorted = set_sort(set);
		divide_conquer_b(info, sorted, set->size, min_size);
		free(sorted);
		i--;
	}
}

void	stack_bigsort(t_psinfo *info)
{
	t_setinfo	*setinfo;

	setinfo = create_sets(info, 15);
	insertsort(info, setinfo, 20);
	print_combine_inst(info->inst_buff);
	free_sets(setinfo);
}
