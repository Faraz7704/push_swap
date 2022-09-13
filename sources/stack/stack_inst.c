/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 23:23:10 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_inst_rots(char *f, t_psinfo *info)
{
	if (!ft_strncmp(f, "ra", 2))
	{
		rot_stack(&info->a);
		return (1);
	}
	if (!ft_strncmp(f, "rb", 2))
	{
		rot_stack(&info->b);
		return (1);
	}
	if (!ft_strncmp(f, "rr", ft_strlen(f)))
	{
		rot_stack(&info->a);
		rot_stack(&info->b);
		return (1);
	}
	return (0);
}

int	run_inst_rrots(char *f, t_psinfo *info)
{
	if (!ft_strncmp(f, "rra", 3))
	{
		rrot_stack(&info->a);
		return (1);
	}
	if (!ft_strncmp(f, "rrb", 3))
	{
		rrot_stack(&info->b);
		return (1);
	}
	if (!ft_strncmp(f, "rrr", 3))
	{
		rrot_stack(&info->a);
		rrot_stack(&info->b);
		return (1);
	}
	return (0);
}

int	run_inst_push(char *f, t_psinfo *info)
{
	if (!ft_strncmp(f, "pa", 2))
	{
		push_stack(&info->a, &info->b);
		return (1);
	}
	if (!ft_strncmp(f, "pb", 2))
	{
		push_stack(&info->b, &info->a);
		return (1);
	}
	return (0);
}

int	run_inst_swap(char *f, t_psinfo *info)
{
	if (!ft_strncmp(f, "sa", 2))
	{
		swap_stack(&info->a);
		return (1);
	}
	if (!ft_strncmp(f, "sb", 2))
	{
		swap_stack(&info->b);
		return (1);
	}
	if (!ft_strncmp(f, "ss", 2))
	{
		swap_stack(&info->a);
		swap_stack(&info->b);
		return (1);
	}
	return (0);
}

int	run_inst(char *f, t_psinfo *info, int debug)
{
	if (run_inst_swap(f, info) || run_inst_push(f, info)
		|| run_inst_rots(f, info) || run_inst_rrots(f, info))
	{
		if (!debug)
			ft_printf("%s\n", f);
		return (1);
	}
	return (0);
}
