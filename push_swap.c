/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/06 14:52:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	*b;

	if (issorted(a, n))
		return ;
	b = ft_calloc(sizeof(int), n);
	if (!b)
		return ;
	print_stack(a, b, n);
	//sort_big_stack(a, b, n);
	run_inst("ra", a, b, n);
	print_stack(a, b, n);
	run_inst("pb", a, b, n);
	print_stack(a, b, n);
	run_inst("pb", a, b, n);
	print_stack(a, b, n);
	run_inst("pa", a, b, n);
	print_stack(a, b, n);
	run_inst("ss", a, b, n);
	print_stack(a, b, n);
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
