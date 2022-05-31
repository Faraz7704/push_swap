/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/31 14:10:37 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int *a, int n, t_e_stack type)
{
	int		i;
	t_list	*lst;
	t_stack	new;

	if (n > 0)
	{
		lst = ft_lstnew(&a[0]);
		i = 1;
		while (i < n)
			ft_lstadd_back(&lst, ft_lstnew(&a[i++]));
		new.lst = lst;
	}
	else
		new.lst = NULL;
	new.size = n;
	new.stack_type = type;
	return (new);
}

int	run_inst(char *f, t_stack *a, t_stack *b, int debug)
{
	if (!ft_strncmp(f, "sa", 2) && !swap_stack(a))
		return (0);
	else if (!ft_strncmp(f, "sb", 2) && !swap_stack(b))
		return (0);
	else if (!ft_strncmp(f, "ss", 2) && !(swap_stack(a) && swap_stack(b)))
		return (0);
	else if (!ft_strncmp(f, "pa", 2) && !push_stack(a, b))
		return (0);
	else if (!ft_strncmp(f, "pb", 2) && !push_stack(b, a))
		return (0);
	else if (!ft_strncmp(f, "ra", 2) && !rot_stack(a))
		return (0);
	else if (!ft_strncmp(f, "rb", 2) && !rot_stack(b))
		return (0);
	else if (!ft_strncmp(f, "rra", 3) && !rrot_stack(a))
		return (0);
	else if (!ft_strncmp(f, "rrb", 3) && !rrot_stack(b))
		return (0);
	else if (!ft_strncmp(f, "rrr", 3) && !(rrot_stack(a) && rrot_stack(b)))
		return (0);
	else if (!ft_strncmp(f, "rr", 2) && !(rot_stack(a) && rot_stack(b)))
		return (0);
	if (!debug)
		ft_printf("%s\n", f);
	return (1);
}
