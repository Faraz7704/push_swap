/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/13 13:10:23 by fkhan            ###   ########.fr       */
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
void	sort_big_stack(t_stack *a, t_stack *b);

// quick_sort
void	quicksort(int *a, int start, int end);
int		issorted(int *a, int n);

// debug
void	print_stack(t_stack a, t_stack b);
void	print_numarr(t_stack a);

#endif