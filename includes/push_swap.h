/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/08/29 19:44:00 by fkhan            ###   ########.fr       */
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

typedef struct st_item
{
	int			index;
	int			value;
	int			move;
	t_e_stack	stack_type;
}	t_st_item;

typedef struct s_set
{
	int			id;
	t_st_item	*items;
	int			total_moves;
	int			size;
}	t_set;

typedef struct setinfo
{
	t_set		*sets;
	int			size;
}	t_setinfo;

typedef struct psinfo
{
	t_stack	a;
	t_stack	b;
}	t_psinfo;

// utils
int			ft_numncmp(const int *num, int c, int n);
size_t		ft_numlen(const int *num);
void		ft_numswap(int *a, int *b);
void		ft_numlcpy(int *dest, const int *src, int n);
int			*ft_numdup(const int *src, int n);

// arg_utils
int			ft_arglen(char **args);
char		**ft_argjoin(char **s1, char **s2);
char		**ft_argsplit(char **args, int n, char sep);
void		ft_freearg(char **args);
t_list		*ft_lstindex(t_list *lst, int index);

// list_utils
void		ft_lstdel(void *content);
int			*ft_lst_to_arr(t_list *lst, int n);

// stack
t_stack		init_stack(int *a, int n, t_e_stack type);
void		free_stack(t_stack *stack);

// stack_inst
int			run_inst(char *f, t_psinfo *info, int debug);

// stack_inst_utils
int			swap_stack(t_stack *a);
int			push_stack(t_stack *a, t_stack *b);
int			rot_stack(t_stack *a);
int			rrot_stack(t_stack *a);

// stack_sort
void		stack_sort(t_psinfo *info);

// stack_bigsort
void		stack_bigsort(t_psinfo *info);

// stack_sort_utils
int			find_index_stack(t_list *lst, int value, int n);
int			min_index_stack(t_list *lst, int n);
int			max_index_stack(t_list *lst, int n);
t_st_item	*min_move_stack(t_set *set, t_e_stack type);
t_st_item	*max_move_stack(t_set *set, t_e_stack type);
void		move_top_stack(int index, t_psinfo *info, int on_b);

// stack_set
// t_set		*create_sets(t_psinfo *info, int *set_size, int min_size);

// stack_set_utils
int			get_moves(t_stack a, int index);
void		cal_sets(t_set *sets, t_psinfo *info, int set_size);
void		cal_set(t_set *set, t_psinfo *info);
int			type_size_set(t_set *set, t_e_stack type);
void		free_sets(t_setinfo *info);

// quick_sort
int			*new_quicksort(int *a, int n);
int			*lstnew_quicksort(t_list *a, int n);
void		quicksort(int *a, int start, int end);
int			issorted(int *a, int n);
int			lst_issorted(t_list *lst, int n);

// debug
void		print_inst(t_list *abuff);
void		print_sets(t_set *sets, int set_size);
void		print_set(t_set set);
void		print_stack(t_stack a, t_stack b);
void		print_numarr(int *a, int n);
void		print_stackarr(t_stack a);

#endif