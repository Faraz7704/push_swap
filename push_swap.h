/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/06 14:50:59 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf.h"

// main
void	push_swap(int *lst, int n);

// utils
int		ft_numncmp(const int *num, int c, int n);
size_t	ft_numlen(const int *num);
void	ft_numswap(int *a, int *b);
void	ft_numlcpy(int *dest, const int *src, int n);
int		*ft_numdup(const int *src, int n);

// push_swap_stack
int		run_inst(char *inst, int *a, int *b, int n);

// sort_stack
void	sort_big_stack(int *a, int *b, int n);

// quick_sort
void	quicksort(int *a, int start, int end);
int		issorted(int *a, int n);

// debug
void	print_stack(int *a, int *b, int n);
void	print_numarr(int *a, int n);

#endif