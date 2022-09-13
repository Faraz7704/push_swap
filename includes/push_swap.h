/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 23:44:24 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum e_stack
{
	ALL_STACK,
	A_STACK,
	B_STACK,
}	t_e_stack;

typedef struct stack
{
	t_list		*lst;
	int			size;
	t_e_stack	stack_type;
}	t_stack;

typedef struct s_set
{
	int			id;
	int			*values;
	int			size;
}	t_set;

typedef struct setinfo
{
	t_set		*sets;
	int			size;
}	t_setinfo;

typedef struct psinfo
{
	t_stack		a;
	t_stack		b;
	t_list		*inst_buff;
}	t_psinfo;

// num_utils
int			ft_numncmp(const int *num, int c, int n);
size_t		ft_numlen(const int *num);
void		ft_numswap(int *a, int *b);
void		ft_numlcpy(int *dest, const int *src, int n);
int			*ft_numdup(const int *src, int n);

// parse_arg
int			*parse_arg(char **av, int n, int *reflen);

// parse_arg_utils
int			ft_arglen(char **args);
char		**ft_argjoin(char **s1, char **s2);
char		**ft_argsplit(char **args, int n, char sep);
void		ft_freearg(char **args);
t_list		*ft_lstindex(t_list *lst, int index);

// list_utils
void		ft_lstnumdel(void *content);
void		ft_lstdel(void *content);
int			*ft_lst_to_arr(t_list *lst, int n);
void		ft_lstdellast(t_list *lst);

// stack
t_stack		init_stack(int *a, int n, t_e_stack type);
void		free_stack(t_stack *a);

// stack_inst
int			run_inst_rots(char *f, t_psinfo *info);
int			run_inst_rrots(char *f, t_psinfo *info);
int			run_inst_push(char *f, t_psinfo *info);
int			run_inst_swap(char *f, t_psinfo *info);
int			run_inst(char *f, t_psinfo *info, int debug);

// stack_inst_combine
t_list		*combine_inst_lst(t_list *lst);
int			run_buff_inst(char *f, t_psinfo *info, int debug);

// stack_inst_utils
int			swap_stack(t_stack *a);
int			push_stack(t_stack *a, t_stack *b);
int			rot_stack(t_stack *a);
int			rrot_stack(t_stack *a);

// stack_sort
void		stack_sort(t_psinfo *info);

// stack_bigsort
void		print_inst(t_list *lst);
void		print_combine_inst(t_list *lst);
void		stack_bigsort(t_psinfo *info);

// stack_divide_conquer
void		divide_conquer(t_psinfo *info, t_setinfo *setinfo, int min_size);
void		divide_conquer_a(t_psinfo *info, int *sorted,
				int size, int min_size);
void		divide_conquer_b(t_psinfo *info, int *sorted,
				int size, int min_size);

// stack_divide_conquer_utils
void		reverse_move(t_psinfo *info, char *f, int size);

// stack_insertsort_a
void		insertsort_on_a(t_psinfo *info, int *sorted, int size);

// stack_insertsort_b
void		insertsort_on_b(t_psinfo *info, int *sorted, int size);

// stack_sort_utils
int			find_index_arr(int *a, int value, int n);
int			min_index_stack(t_list *lst, int n);
int			max_index_stack(t_list *lst, int n);
void		move_top_stack(int index, t_psinfo *info, int on_b);
int			get_pivot(t_list *a, int size, int index);

// stack_set
t_setinfo	*create_sets(t_psinfo *info, int min_set_size);
int			*num_sort(int *values, int size);
int			*num_rsort(int *values, int size);

// stack_set_utils
int			init_set(t_set	*set, int id, int size);
t_set		*init_sets(int size, int set_size);
void		free_sets(t_setinfo *info);

// stack_set_utils2
int			get_set_size(int size, int min_size);
void		add_set(t_psinfo *info, t_set *set);
void		add_one_set(t_psinfo *info, t_set *set);
void		add_two_set(t_psinfo *info, t_set *set1, t_set *set2);

// quick_sort
int			*new_quicksort(int *a, int n);
int			*lstnew_quicksort(t_list *a, int n);
void		quicksort(int *a, int start, int end);

// quick_sort_utils
int			issorted(int *a, int n);
int			lst_issorted(t_list *lst, int n);

// debug
void		print_sets(t_set *sets, int set_size);
void		print_set(t_set set);
void		print_stack(t_stack a, t_stack b);
void		print_numarr(int *a, int n);
void		print_stackarr(t_stack a);

#endif