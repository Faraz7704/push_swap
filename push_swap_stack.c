/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/28 15:41:21 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	g_c = 0;

int	run_inst(char *f, t_stack *a, t_stack *b)
{
	// ft_printf("-----------------------------\n");
	// print_stack(a[0], b[0]);
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
	// print_stack(a[0], b[0]);
	// ft_printf("-----------------------------\n");
	// ft_printf("TOTAL: %d\n", ++g_c);
	// print_stack(a[0], b[0]);
	return (1);
}

static t_instdata	*move_top_inst(int index, t_stack *a, char *rx, char *rrx)
{
	int		i;
	int		len;
	char	**res;

	if (index <= (a->size / 2))
		len = index;
	else
		len = a->size - index + 1;
	res = (char **)ft_calloc(sizeof(char *), len + 1);
	if (!res)
		return (0);
	if (index <= (a->size / 2))
	{
		i = 0;
		while (i < index)
			res[i++] = ft_strdup(rx);
		res[i] = NULL;
		return (res);
	}
	i = a->size - 1;
	while (i >= index)
	{
		res[i - index] = ft_strdup(rrx);
		i--;
	}
	res[i - index] = NULL;
	return (res);
}

static void	freeinst(t_inst	*buff)
{
	int	i;

	i = 0;
	while (buff->a[i])
		free(buff->a[i++]);
	i = 0;
	while (buff->b[i])
		free(buff->b[i++]);
}

void	run_multi_inst(int aindex, int bindex, t_stack *a, t_stack *b)
{
	int				i;
	int				j;
	static t_inst	inst;
	t_inst			buff;

	buff.a = move_top_inst(aindex, a, "ra", "rra");
	buff.b = move_top_inst(bindex, b, "rb", "rrb");
	i = 0;
	j = 0;
	while (buff.a[i])
	{
		if (buff.b[j] && ft_strncmp(buff.a[i], "ra", 2) && ft_strncmp(buff.b[j], "rb", 2))
		{
			run_inst("rr", a, b);
			j++;
		}
		else if (buff.b[j] && ft_strncmp(buff.a[i], "rra", 3) && ft_strncmp(buff.b[j], "rrb", 3))
		{
			run_inst("rrr", a, b);
			j++;
		}
		else
			run_inst(buff.a[i], a, b);
		i++;
	}
	freeinst(&buff);
}

void	move_top_stack(int index, t_stack *a, t_stack *b, int onB)
{
	int		i;
	char	*rx;
	char	*rrx;
	t_stack	*temp;

	rx = "ra";
	rrx = "rra";
	temp = a;
	if (onB)
	{
		rx = "rb";
		rrx = "rrb";
		temp = b;
	}
	if (index <= (temp->size / 2))
	{
		i = 0;
		while (i++ < index)
			run_inst(rx, a, b);
		return ;
	}
	i = temp->size - 1;
	while (i-- >= index)
		run_inst(rrx, a, b);
}
