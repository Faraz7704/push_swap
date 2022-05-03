/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/01 21:04:19 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int *a, int n)
{
	t_stack	new;

	new.value = a;
	new.size = n;
	return (new);
}

int	swap(t_stack *a)
{
	if (a->size < 2)
		return (0);
	ft_numswap(&a->value[0], &a->value[1]);
	return (1);
}

int	push(t_stack *a, t_stack *b)
{
	int	i;

	if (!b->size)
		return (0);
	if (a->size)
	{
		i = a->size;
		while (i > 0)
		{
			a->value[i] = a->value[i - 1];
			i--;
		}
	}
	a->value[0] = b->value[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->value[i] = b->value[i + 1];
		i++;
	}
	b->value[i] = 0;
	b->size--;
	return (1);
}

int	rot(t_stack *a)
{
	int	i;
	int	len;
	int	temp;

	len = a->size;
	if (len < 2)
		return (0);
	i = 0;
	temp = a->value[i];
	while (i < len - 1)
	{
		a->value[i] = a->value[i + 1];
		i++;
	}
	a->value[i] = temp;
	return (1);
}

int	rrot(t_stack *a)
{
	int	i;
	int	len;
	int	temp;

	len = a->size;
	if (len < 2)
		return (0);
	i = len - 1;
	temp = a->value[i];
	while (i > 0)
	{
		a->value[i] = a->value[i - 1];
		i--;
	}
	a->value[i] = temp;
	return (1);
}
