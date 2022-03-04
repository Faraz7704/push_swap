/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/04 11:50:44 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_numchr(const int *num, int c)
{
	int	i;

	i = 0;
	while (num[i] != '\0' && c != num[i])
		i++;
	if (c == num[i])
		return ((int *)(num + i));
	return (0);
}

size_t	ft_numlen(const int *num)
{
	size_t	i;

	i = 0;
	while (num[i])
		i++;
	return (i);
}