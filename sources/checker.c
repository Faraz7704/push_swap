/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 23:28:19 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	read_inst(t_psinfo *info, int fd)
{
	char	*inst;

	inst = get_next_line(fd);
	while (inst && inst[0] != '\0')
	{
		inst[ft_strlen(inst) - 1] = '\0';
		if (!run_inst(inst, info, 1))
			return (0);
		inst = get_next_line(fd);
	}
	return (1);
}

static void	checker(int *a, int n)
{
	t_psinfo	info;

	info.a = init_stack(a, n, A_STACK);
	info.b = init_stack(NULL, 0, B_STACK);
	info.inst_buff = NULL;
	if (!read_inst(&info, STDIN_FILENO))
		ft_fprintf(STDERR_FILENO, "Error\n");
	else
	{
		if (lst_issorted(info.a.lst, info.a.size) && info.b.size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_stack(&info.a);
	free_stack(&info.b);
	ft_lstclear(&info.inst_buff, ft_lstdel);
}

int	main(int ac, char **av)
{
	int	*lst;
	int	len;

	if (ac < 2)
		return (0);
	lst = parse_arg(&av[1], ac - 1, &len);
	if (!lst)
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		return (0);
	}
	checker(lst, len);
	free(lst);
	return (0);
}
