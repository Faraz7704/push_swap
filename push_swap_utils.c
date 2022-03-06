/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/06 13:45:22 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numncmp(const int *num, int c, int n)
{
	int	i;

	if (!n)
		return (0);
	i = 0;
	while (num[i] && c != num[i] && i < n -1)
		i++;
	return (c == num[i]);
}

size_t	ft_numlen(const int *num)
{
	size_t	i;

	i = 0;
	while (num[i])
		i++;
	return (i);
}

void	ft_numswap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_numlcpy(int *dest, const int *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

int	*ft_numdup(const int *src, int n)
{
	int	*new;

	new = ft_calloc(sizeof(int), n);
	if (!new)
		return (0);
	ft_numlcpy(new, src, n);
	return (new);
}
