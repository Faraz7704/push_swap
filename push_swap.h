/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:23 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/04 11:51:01 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

void	push_swap(int *lst);
int		*ft_numchr(const int *num, int c);
size_t  ft_numlen(const int *num);

#endif