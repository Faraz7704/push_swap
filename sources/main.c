/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 22:48:02 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
