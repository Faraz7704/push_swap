/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 15:43:58 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isnumber(int num, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && !ft_isdigit(str[0]))
		return (0);
	if ((num == -1 || num == 0) && i >= 10)
		return (0);
	return (1);
}

static int	*parse_arg(char **av, int n, int *reflen)
{
	int		i;
	char	**args;
	int		*lst;

	args = ft_argsplit(av, n, ' ');
	*reflen = ft_arglen(args);
	lst = ft_calloc(sizeof(int), *reflen + 1);
	if (!lst)
		exit(1);
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
	t_psinfo	info;

	if (issorted(a, n))
		return ;
	info.a = init_stack(a, n, A_STACK);
	info.b = init_stack(NULL, 0, B_STACK);
	info.inst_buff = NULL;
	stack_sort(&info);
	free_stack(&info.a);
	free_stack(&info.b);
	if (!info.inst_buff)
		ft_lstclear(&info.inst_buff, ft_lstdel);
}

int	main(int ac, char **av)
{
	int	*lst;
	int	len;

	if (ac < 2)
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		return (0);
	}
	lst = parse_arg(&av[1], ac - 1, &len);
	if (!lst)
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		return (0);
	}
	push_swap(lst, len);
	free(lst);
	return (0);
}
