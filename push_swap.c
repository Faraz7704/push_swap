/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/04 17:19:55 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_arg(int ac, char **av, int *lst)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i] || ft_numchr(lst, av[i][0]))
			return (0);
		lst[i - 1] = ft_atoi(av[i]);
		if (lst[i - 1] == 0 && !ft_isdigit(av[i][0]))
			return (0);
		if ((lst[i - 1] == -1 || lst[i - 1] == 0) && ft_strlen(av[i]) >= 10)
			return (0);
		i++;
	}
	return (1);
}

void	push_swap(int *a, int n)
{
	int	i;
	// int	*b;

	i = 0;
	while (a[i])
		ft_printf("%d\n", a[i++]);
}

int	main(int ac, char **av)
{
	int	*lst;

	if (ac < 2)
		return (0);
	lst = ft_calloc(sizeof(int), ac - 1);
	if (!lst)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (parse_arg(ac, av, lst))
		push_swap(lst, ac - 1);
	free(lst);
	return (0);
}
