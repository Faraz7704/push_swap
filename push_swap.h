/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/26 15:31:44 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf.h"

typedef struct stack
{
	int	*value;
	int	size;
}	t_stack;

typedef struct sset
{
	int		id;
	int		*index;
	int		*values;
	int		*moves;
	int		total_moves;
	int		size;
	int		used;
}	t_sset;

// utils
int		ft_numncmp(const int *num, int c, int n);
size_t	ft_numlen(const int *num);
void	ft_numswap(int *a, int *b);
void	ft_numlcpy(int *dest, const int *src, int n);
int		*ft_numdup(const int *src, int n);

// arg_utils
int		ft_arglen(char **args);
char	**ft_argjoin(char **s1, char **s2);
char	**ft_argsplit(char **args, int n, char sep);
void	ft_freearg(char **args);

// push_swap_stack
int		run_inst(char *inst, t_stack *a, t_stack *b);

// sort_stack
void	sort_stack(t_stack *a, t_stack *b);

// sort_big_stack
void	sort_big(t_stack *a, t_stack *b, int *sort, int set_size);

// sort_stack_utils
int		find_index_stack(int *a, int value, int n);
int		min_index_stack(int *a, int start, int n);
int		max_index_stack(int *a, int start, int n);
int		min_moves_stack(t_sset *set);
void	move_top_stack(int index, t_stack *a, t_stack *b);

// stack_set
t_sset	*create_sets(t_stack *a, int *sort, int set_size, int *reflen);
int		find_min_set(t_sset *sets, int set_size, t_sset **res);

// stack_set_utils
int		get_moves(t_stack *a, int index);
void	cal_sets(t_sset *sets, t_stack *a, int set_size);
void	cal_set(t_sset *set, t_stack *a);
void	free_sets(t_sset *sets, int set_size);

// quick_sort
void	quicksort(int *a, int start, int end);
int		issorted(int *a, int n);

// debug
void	print_sets(t_sset *sets, int *sort, int set_size);
void	print_stack(t_stack a, t_stack b);
void	print_numarr(t_stack a);

#endif