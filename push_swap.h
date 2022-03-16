/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/16 17:33:17 by fkhan            ###   ########.fr       */
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

// main
void	push_swap(int *lst, int n);

// utils
int		ft_numncmp(const int *num, int c, int n);
size_t	ft_numlen(const int *num);
void	ft_numswap(int *a, int *b);
void	ft_numlcpy(int *dest, const int *src, int n);
int		*ft_numdup(const int *src, int n);

// push_swap_stack
int		run_inst(char *inst, t_stack *a, t_stack *b);

// sort_stack
void	sort_stack(t_stack *a, t_stack *b);

// sort_big_stack
void	sort_big(t_stack *a, t_stack *b, int *sort, int set_size);

// sort_stack_utils
int		min_index_stack(int *a, int start, int n);
int		max_index_stack(int *a, int start, int n);
void	move_top_stack(int index, t_stack *a, t_stack *b);

// quick_sort
void	quicksort(int *a, int start, int end);
int		issorted(int *a, int n);

// debug
void	print_stack(t_stack a, t_stack b);
void	print_numarr(t_stack a);

#endif