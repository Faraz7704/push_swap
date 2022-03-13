/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/13 13:17:11 by fkhan            ###   ########.fr       */
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

static int	parse_arg(int ac, char **av, int *lst)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i])
			return (0);
		lst[i - 1] = ft_atoi(av[i]);
		if (lst[i - 1] == 0 && !ft_isdigit(av[i][0]))
			return (0);
		if ((lst[i - 1] == -1 || lst[i - 1] == 0) && ft_strlen(av[i]) >= 10)
			return (0);
		if (ft_numncmp(lst, lst[i - 1], i - 1))
			return (0);
		i++;
	}
	return (1);
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
	print_stack(stacka, stackb);
	sort_big_stack(&stacka, &stackb);
	print_stack(stacka, stackb);
	free(b);
}

int	main(int ac, char **av)
{
	int	*lst;

	if (ac < 2)
		return (0);
	lst = ft_calloc(sizeof(int), ac - 1);
	if (!lst)
		return (0);
	if (parse_arg(ac, av, lst))
		push_swap(lst, ac - 1);
	else
		ft_printf("Error\n");
	free(lst);
	return (0);
}
