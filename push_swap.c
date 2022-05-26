/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/26 15:06:06 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isnumber(int num, char *str)
{
	if (num == 0 && !ft_isdigit(str[0]))
		return (0);
	if ((num == -1 || num == 0) && ft_strlen(str) >= 10)
		return (0);
	return (1);
}

static int	*parse_arg(char **av, int n, int *reflen)
{
	int		i;
	char	**args;
	int		*lst;

	args = ft_argsplit(av, n, ' ');
	i = 0;
	*reflen = ft_arglen(args);
	lst = ft_calloc(sizeof(int), *reflen + 1);
	if (!lst)
		return (0);
	i = 0;
	while (i < *reflen)
	{
		lst[i] = ft_atoi(args[i]);
		if (!isnumber(lst[i], args[i]) || ft_numncmp(lst, lst[i], i))
		{
			ft_freearg(args);
			free(lst);
			return (0);
		}
		i++;
	}
	ft_freearg(args);
	return (lst);
}

static void	push_swap(int *a, int n)
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
	// print_stack(stacka, stackb);
	free(b);
}

int	main(int ac, char **av)
{
	int	*lst;
	int	len;

	if (ac < 2)
		return (0);
	lst = parse_arg(av + 1, ac - 1, &len);
	if (!lst)
	{
		ft_printf("Error\n");
		return (0);
	}
	push_swap(lst, len);
	free(lst);
	return (0);
}
