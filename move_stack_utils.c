/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/06/01 15:03:37 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_stack(int index, t_stack *a, t_stack *b, int on_b)
{
	int		i;
	char	*rx;
	// char	*rrx;
	// t_stack	*temp;

	rx = "ra";
	// rrx = "rra";
	// temp = a;
	if (on_b)
	{
		rx = "rb";
		// rrx = "rrb";
		// temp = b;
	}
	// if (index <= (temp->size / 2))
	// {
		i = 0;
		while (i++ < index)
			run_inst(rx, a, b, 0);
		// return ;
	// }
	// i = temp->size - 1;
	// while (i-- > index)
	// 	run_inst(rrx, a, b, 0);
}

// t_list	*move_top_inst(int index, t_stack *a, char *rx, char *rrx)
// {
// 	int		i;
// 	t_list	*res;

// 	res = NULL;
// 	if (index <= (a->size / 2))
// 	{
// 		i = 0;
// 		while (i++ < index)
// 			ft_lstadd_back(&res, ft_lstnew(ft_strdup(rx)));
// 	}
// 	else
// 	{
// 		i = a->size - 1;
// 		while (i-- >= index)
// 			ft_lstadd_back(&res, ft_lstnew(ft_strdup(rrx)));
// 	}
// 	return (res);
// }

// static void	trim_inst(t_list **buff)
// {
// 	int		sb;
// 	int		rrb;
// 	t_list	*curr;

// 	curr = buff[0];
// 	sb = 0;
// 	rrb = 0;
// 	while (curr)
// 	{
// 		if (!ft_strncmp(curr->content, "sb", 2))
// 			sb++;
// 		else if (!ft_strncmp(curr->content, "rrb", 3))
// 			rrb++;
// 		ft_printf("%s ", curr->content);
// 		curr = curr->next;
// 	}
// 	ft_printf("\n");
// 	if (!sb)
// 		rrb *= 2;
// 	else
// 		rrb = rrb - (sb * 3);
// 	ft_printf("sb: %d rrb: %d\n", sb, rrb);
// 	while (rrb > 0)
// 	{
// 		ft_printf("%d %s ", rrb, buff[0]->content);
// 		del_last_lst(buff[0]);
// 		rrb--;
// 	}
// 	if (!sb)
// 		buff[0] = NULL;
// 	ft_printf("\n");
// }

// t_list	*swap_sort_inst(t_stack *b, int n)
// {
// 	int		i;
// 	int		count;
// 	t_stack	temp;
// 	t_list	*res;

// 	if (n <= 1)
// 		return (0);
// 	i = 1;
// 	count = 1;
// 	res = NULL;
// 	ft_printf("---------------------------\n");
// 	ft_printf("before b: ");
// 	temp = init_stack(ft_numdup(b->values, b->size), b->size);
// 	print_numarr(temp);
// 	while (i > 0)
// 	{
// 		while (i < n)
// 		{
// 			if (temp.values[0] < temp.values[1])
// 			{
// 				ft_lstadd_back(&res, ft_lstnew(ft_strdup("sb")));
// 				run_inst("sb", NULL, &temp, 1);
// 				if (i == n - count)
// 				{
// 					// count++;
// 					break ;
// 				}
// 				ft_lstadd_back(&res, ft_lstnew(ft_strdup("rb")));
// 				run_inst("rb", NULL, &temp, 1);
// 			}
// 			else
// 			{
// 				if (i == n - count)
// 				{
// 					// count++;
// 					break ;
// 				}
// 				ft_lstadd_back(&res, ft_lstnew(ft_strdup("rb")));
// 				run_inst("rb", NULL, &temp, 1);
// 			}
// 			i++;
// 		}
// 		while (i-- != 0)
// 		{
// 			if (i > 0)
// 			{
// 				ft_lstadd_back(&res, ft_lstnew(ft_strdup("rrb")));
// 				run_inst("rrb", NULL, &temp, 1);
// 			}
// 			if (temp.values[0] < temp.values[1])
// 				break ;
// 		}
// 	}
// 	trim_inst(&res);
// 	return (res);
// }
