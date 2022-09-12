/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/12 19:11:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_inst_rotations(char *f, t_psinfo *info)
{
	if (!ft_strncmp(f, "ra", 2) && !rot_stack(&info->a))
		return (0);
	else if (!ft_strncmp(f, "rb", 2) && !rot_stack(&info->b))
		return (0);
	else if (!ft_strncmp(f, "rra", 3) && !rrot_stack(&info->a))
		return (0);
	else if (!ft_strncmp(f, "rrb", 3) && !rrot_stack(&info->b))
		return (0);
	else if (!ft_strncmp(f, "rrr", 3) && !(rrot_stack(&info->a)
			&& rrot_stack(&info->b)))
		return (0);
	else if (!ft_strncmp(f, "rr", ft_strlen(f)) && !(rot_stack(&info->a)
			&& rot_stack(&info->b)))
		return (0);
	return (1);
}

int	run_inst(char *f, t_psinfo *info, int debug)
{
	if (!ft_strncmp(f, "sa", 2) && !swap_stack(&info->a))
		return (0);
	else if (!ft_strncmp(f, "sb", 2) && !swap_stack(&info->b))
		return (0);
	else if (!ft_strncmp(f, "ss", 2) && !(swap_stack(&info->a)
			&& swap_stack(&info->b)))
		return (0);
	else if (!ft_strncmp(f, "pa", 2) && !push_stack(&info->a, &info->b))
		return (0);
	else if (!ft_strncmp(f, "pb", 2) && !push_stack(&info->b, &info->a))
		return (0);
	else if (!run_inst_rotations(f, info))
		return (0);
	if (!debug)
		ft_printf("%s\n", f);
	return (1);
}

static char	*combine_inst_val(t_list *curr, t_list *next)
{
	char	*curr_val;
	char	*next_val;

	curr_val = (char *)curr->content;
	if (!next)
		return (ft_strdup(curr_val));
	next_val = (char *)next->content;
	if (!ft_strncmp(curr_val, "rb", ft_strlen(curr_val))
		&& !ft_strncmp(next_val, "ra", ft_strlen(next_val)))
		return (ft_strdup("rr"));
	if (!ft_strncmp(curr_val, "pb", ft_strlen(curr_val))
		&& !ft_strncmp(next_val, "pa", ft_strlen(next_val)))
		return (0);
	return (ft_strdup(curr_val));
}

t_list	*combine_inst_lst(t_list *lst)
{
	t_list	*new;
	t_list	*curr;
	t_list	*next;
	char	*value;

	if (!lst)
		return (0);
	new = NULL;
	curr = lst;
	while (curr)
	{
		next = curr->next;
		value = combine_inst_val(curr, next);
		if (value)
		{
			ft_lstadd_back(&new, ft_lstnew(value));
			if (ft_strncmp(value, (char *)curr->content, ft_strlen(value)))
				next = next->next;
		}
		else
			next = next->next;
		curr = next;
	}
	return (new);
}

int	run_buff_inst(char *f, t_psinfo *info, int debug)
{
	ft_lstadd_back(&info->inst_buff, ft_lstnew(ft_strdup(f)));
	return (run_inst(f, info, debug));
}
