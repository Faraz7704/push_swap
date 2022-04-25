/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/25 18:09:18 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	init_stack(int *a, int n)
{
	t_stack	new;

	new.value = a;
	new.size = n;
	return (new);
}

static int	*parse_arg(char **av, int n)
{
	int		i;
	int		len;
	char	**args;
	int		*lst;

	args = ft_argsplit(av, n, ' ');
	len = ft_argitemlen(args);
	lst = ft_calloc(sizeof(int), len);
	if (!lst)
		return (0);
	i = 0;
	while (i < len)
	{
		lst[i] = ft_atoi(args[i]);
		if (lst[i] == 0 && !ft_isdigit(args[i][0]))
			return (0);
		if ((lst[i] == -1 || lst[i] == 0) && ft_strlen(args[i]) >= 10)
			return (0);
		if (ft_numncmp(lst, lst[i], i))
			return (0);
		i++;
	}
	ft_freearg(args);
	return (lst);
}

void	push_swap(int *a, int n)
{
	int		*b;
	t_stack	stacka;
	t_stack	stackb;

	if (issorted(a, n))
		return ;
	b = ft_calloc(sizeof(int), n);
	if (!b)
		return ;
	stacka = init_stack(a, n);
	stackb = init_stack(b, 0);
	// print_stack(stacka, stackb);
	sort_stack(&stacka, &stackb);
	print_stack(stacka, stackb);
	free(b);
}

int	main(int ac, char **av)
{
	int	*lst;

	if (ac < 2)
		return (0);
	lst = parse_arg(av + 1, ac - 1);
	if (!lst)
	{
		ft_printf("Error\n");
		return (0);
	}
	push_swap(lst, ac - 1);
	free(lst);
	return (0);
}
