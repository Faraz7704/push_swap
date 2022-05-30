/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/30 17:21:28 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf.h"

typedef enum e_stack
{
	A,
	B
}	t_e_stack;

typedef struct stack
{
	t_list		*lst;
	int			size;
	t_e_stack	stack_type;
}	t_stack;

typedef struct set_item
{
	int			index;
	int			value;
	int			moves;
	t_e_stack	stack_type;
}	t_set_item;

typedef struct sset
{
	int			id;
	t_set_item	*items;
	int			total_moves;
	int			size;
}	t_sset;

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

// list_utils
void		del_lst(void *content);
t_list		*del_first_lst(t_list **lst);
void		del_last_lst(t_list *lst);

// stack
t_stack		init_stack(int *a, int n, e_stack type);
int			run_inst(char *inst, t_stack *a, t_stack *b, int test);

// move_stack_utils
void		move_top_stack(int index, t_stack *a, t_stack *b, int on_b);

// stack_instructions
int			swap_stack(t_stack *a);
int			push_stack(t_stack *a, t_stack *b);
int			rot_stack(t_stack *a);
int			rrot_stack(t_stack *a);

// sort_stack
void		sort_stack(t_stack *a, t_stack *b);

// sort_big_stack
void		sort_big(t_stack *a, t_stack *b);

// sort_stack_utils
int			find_index_stack(int *a, int value, int n);
int			min_index_stack(int *a, int start, int n);
int			max_index_stack(int *a, int start, int n);
int			min_moves_stack(t_sset *set);
int			max_moves_stack(t_sset *set);

// stack_set
t_sset		*create_sets(t_stack *a, int *reflen);
int			sets_true_size(t_sset *set);

// stack_set_utils
int			get_moves(t_stack *a, int index);
void		cal_sets(t_sset *sets, t_stack *a, t_stack *b, int set_size);
void		cal_set(t_sset *set, t_stack *a);
void		free_sets(t_sset *sets, int set_size);
int			min_index_set(t_sset *set, int start, int n);

// quick_sort
int			*new_quicksort(int *a, int n);
void		quicksort(int *a, int start, int end);
int			issorted(int *a, int n);

// debug
void		print_inst(t_list *abuff);
void		print_sets(t_sset *sets, int set_size);
void		print_stack(t_stack a, t_stack b);
void		print_numarr(t_stack a);

#endif