/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/06 14:58:19 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(int *a, int n)
{
	if (n < 2)
		return (0);
	ft_numswap(&a[0], &a[1]);
	return (1);
}

static int	push(int *a, int *b)
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
		i = alen;
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
	}
	a[0] = b[0];
	i = 0;
	while (i < blen - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = 0;
	return (1);
}

static int	rot(int *a)
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
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
	return (1);
}

static int	rrot(int *a)
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
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = temp;
	return (1);
}

int	run_inst(char *f, int *a, int *b, int n)
{
	if (!ft_strncmp(f, "sa", 2) && !swap(a, n))
		return (0);
	else if (!ft_strncmp(f, "sb", 2) && !swap(b, n))
		return (0);
	else if (!ft_strncmp(f, "ss", 2) && (!swap(a, n) || !swap(b, n)))
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
	else if (!ft_strncmp(f, "rrr", 3) && (!rrot(a) || !rrot(b)))
		return (0);
	else if (!ft_strncmp(f, "rr", ft_strlen(f)) && (!rot(a) || !rot(b)))
		return (0);
	ft_printf("%s\n", f);
	return (1);
}
