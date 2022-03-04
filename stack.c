/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/04 14:32:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int *a)
{
	int	len;
	int	temp;

	len = ft_numlen(a);
	if (len < 2)
		return (0);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (1);
}

int	push(int *a, int *b)
{
	int	i;
	int	alen;
	int	blen;

	blen = ft_numlen(b);
	if (!blen)
		return (0);
	alen = ft_numlen(a);
	if (alen)
	{
		i = alen - 1;
		while (i > 0)
			a[i] = a[--i];
	}
	a[0] = b[0];
	i = 0;
	while (i < blen - 1)
		b[i] = b[++i];
	b[i] = 0;
	return (1);
}

int	rotate(int *a)
{
	int	i;
	int	len;
	int	temp;

	len = ft_numlen(a);
	if (len < 2)
		return (0);
	i = 0;
	temp = a[i];
	while (i < len - 1)
		a[i] = a[++i];
	a[i] = temp;
	return (1);
}

int	rrotate(int *a)
{
	int	i;
	int	len;
	int	temp;

	len = ft_numlen(a);
	if (len < 2)
		return (0);
	i = len - 1;
	temp = a[i];
	while (i > 0)
		a[i] = a[--i];
	a[i] = temp;
	return (1);
}
