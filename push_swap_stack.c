/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/14 17:35:58 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *a)
{
	if (a->size < 2)
		return (0);
	ft_numswap(&a->value[0], &a->value[1]);
	return (1);
}

static int	push(t_stack *a, t_stack *b)
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

static int	rot(t_stack *a)
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

static int	rrot(t_stack *a)
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

int	run_inst(char *f, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(f, "sa", 2) && !swap(a))
		return (0);
	else if (!ft_strncmp(f, "sb", 2) && !swap(b))
		return (0);
	else if (!ft_strncmp(f, "ss", 2) && !swap(a) && !swap(b))
		return (0);
	else if (!ft_strncmp(f, "pa", 2) && !push(a, b))
		return (0);
	else if (!ft_strncmp(f, "pb", 2) && !push(b, a))
		return (0);
	else if (!ft_strncmp(f, "ra", 2) && !rot(a))
		return (0);
	else if (!ft_strncmp(f, "rb", 2) && !rot(b))
		return (0);
	else if (!ft_strncmp(f, "rra", 3) && !rrot(a))
		return (0);
	else if (!ft_strncmp(f, "rrb", 3) && !rrot(b))
		return (0);
	else if (!ft_strncmp(f, "rrr", 3) && !rrot(a) && !rrot(b))
		return (0);
	else if (!ft_strncmp(f, "rr", ft_strlen(f)) && !rot(a) && !rot(b))
		return (0);
	ft_printf("%s\n", f);
	print_stack(a[0], b[0]);
	return (1);
}
