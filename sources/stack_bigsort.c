/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/11 19:16:36 by fkhan            ###   ########.fr       */
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
			run_inst("pb", info, 0);
			set->items[j].value = *(int *)info->b.lst->content;
			set->items[j].stack_type = info->b.stack_type;
			j++;
		}
		else
		{
			run_inst("ra", info, 0);
			i++;
		}
	}
	cal_set(set, info);
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
			run_inst("pb", info, 0);
			if (*(int *)info->b.lst->content < midpivot)
			{
				set1->items[i[1]].value = *(int *)info->b.lst->content;
				set1->items[i[1]].stack_type = info->b.stack_type;
				run_inst("rb", info, 0);
				i[1]++;
			}
			else
			{
				set2->items[i[2]].value = *(int *)info->b.lst->content;
				set2->items[i[2]].stack_type = info->b.stack_type;
				i[2]++;
			}
		}
		else
		{
			run_inst("ra", info, 0);
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
		set->items[i].value = *(int *)curr->content;
		set->items[i].stack_type = A_STACK;
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
			run_inst("pa", info, 0);
			i[1]++;
		}
		else
		{
			run_inst("rb", info, 0);
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
			run_inst("pb", info, 0);
			i[1]++;
		}
		else
		{
			run_inst("ra", info, 0);
			i[2]++;
		}
		i[0]++;
	}
	return (i[2]);
}

void divide_conquer_a(t_psinfo *info, int *sorted, int size, int min_size)
{
	int	mid_index;
	int	i;
	int	moves;

	// ft_printf("----------- A -----------\nsize: %d\n\n", size);
	// print_numarr(sorted, size);
	if (size <= min_size)
		return ;
	mid_index = (size / 2);
	moves = divide_on_a(info, sorted, size, mid_index);

	if (size - mid_index > min_size)
	{
		i = 0;
		while (i < moves)
		{
			run_inst("rra", info, 0);
			i++;
		}
	}

	// print_stack(info->a, info->b);
	// ft_printf("\n");
	// print_numarr(&sorted[mid_index], size - mid_index);
	// ft_printf("\n");
	// print_numarr(sorted, mid_index);

	divide_conquer_a(info, &sorted[mid_index], size - mid_index, min_size);

	// print_stack(info->a, info->b);
	// ft_printf("--------------------------------------- \n");

	insertsort_on_a(info, &sorted[mid_index], size - mid_index);

	// print_stack(info->a, info->b);
	// ft_printf("####################################### \n");

	divide_conquer_b(info, sorted, mid_index, min_size);
}

void divide_conquer_b(t_psinfo *info, int *sorted, int size, int min_size)
{
	int	i;
	int	mid_index;
	int	*rsorted;
	int	moves;

	// ft_printf("----------- B -----------\nsize: %d\n\n", size);
	// print_numarr(sorted, size);
	if (size <= min_size)
	{
		rsorted = num_rsort(sorted, size);
		insertsort_on_b(info, rsorted, size);
		free(rsorted);
		return ;
	}
	mid_index = (size / 2) + 1;
	moves = divide_on_b(info, sorted, size, mid_index - 1);

	// print_stack(info->a, info->b);
	// ft_printf("\n");
	// print_numarr(&sorted[mid_index], size - mid_index);
	// ft_printf("\n");
	// print_numarr(sorted, mid_index);

	divide_conquer_a(info, &sorted[mid_index], size - mid_index, min_size);
	insertsort_on_a(info, &sorted[mid_index], size - mid_index);

	// print_stack(info->a, info->b);
	if (size - mid_index > min_size)
	{
		i = 0;
		while (i < moves)
		{
			run_inst("rrb", info, 0);
			i++;
		}
	}
	// print_stack(info->a, info->b);

	divide_conquer_b(info, sorted, mid_index, min_size);
}

// static void divide_conquer(t_psinfo *info, int *sorted, int size, int min_size)
// {
// 	int		*rsorted;
// 	int		mid_index;

// 	ft_printf("--------\n");
// 	print_stack(info->a, info->b);
// 	print_numarr(sorted, size);
// 	ft_printf("--------\n");
// 	mid_index = (size / 2);
// 	if (size % 2 != 0)
// 		mid_index++;
// 	if (!lst_issorted(info->a.lst, info->a.size))
// 	{
// 		if (size > min_size)
// 		{
// 			divide_on_a(info, sorted, size);
// 			divide_conquer(info, &sorted[mid_index], size - mid_index, min_size);
// 			divide_conquer(info, sorted, mid_index, min_size);
// 		}
// 		else
// 		{
// 			insertsort_on_a(info, sorted, size);
// 		}
// 		return ;
// 	}
// 	if (size > min_size)
// 	{
// 		divide_on_b(info, sorted, size);
// 		divide_conquer(info, &sorted[mid_index], size - mid_index, min_size);
// 		divide_conquer(info, sorted, mid_index, min_size);
// 	}
// 	else
// 	{
// 		rsorted = num_rsort(sorted, size);
// 		insertsort_on_b(info, rsorted, size);
// 		free(rsorted);
// 	}
// }

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
		// ft_printf("************************************\n");
		divide_conquer_b(info, sorted, set->size, min_size);
		free(sorted);
		i--;
	}
}

void	stack_bigsort(t_psinfo *info)
{
	t_setinfo	*setinfo;
	int			min_size;

	// print_stack(info->a, info->b);
	min_size = 15;
	setinfo = create_sets(info, min_size);
	// print_sets(setinfo->sets, setinfo->size);
	insertsort(info, setinfo, 20);
	// print_stack(info->a, info->b);
	free_sets(setinfo);
}
