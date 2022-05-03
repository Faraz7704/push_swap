/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2022/05/03 12:42:17 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	g_c = 0;

int	run_inst(char *f, t_stack *a, t_stack *b, int test)
{
	int	flag1;
	int	flag2;
	// ft_printf("-----------------------------\n");
	// print_stack(a[0], b[0]);
	if (!ft_strncmp(f, "sa", 2) && !swap(a))
		return (0);
	else if (!ft_strncmp(f, "sb", 2) && !swap(b))
		return (0);
	else if (!ft_strncmp(f, "ss", 2))
	{
		flag1 = !swap(a);
		flag2 = !swap(b);
		if (flag1 && flag2)
			return (0);
	}
	else if (!ft_strncmp(f, "pa", 2) && !push(a, b))
		return (0);
	else if (!ft_strncmp(f, "pb", 2) && !push(b, a))
		return (0);
	else if (!ft_strncmp(f, "ra", 2) && !rot(a))
		return (0);
	else if (!ft_strncmp(f, "rb", 2) && !rot(b))
		return (0);
	else if (!ft_strncmp(f, "rra", 3) && !rrot(a))
		return (0);
	else if (!ft_strncmp(f, "rrb", 3) && !rrot(b))
		return (0);
	else if (!ft_strncmp(f, "rrr", 3))
	{
		flag1 = !rrot(a);
		flag2 = !rrot(b);
		if (flag1 && flag2)
			return (0);
	}
	else if (!ft_strncmp(f, "rr", ft_strlen(f)))
	{
		flag1 = !rot(a);
		flag2 = !rot(b);
		if (flag1 && flag2)
			return (0);
	}
	if (!test)
		ft_printf("%s\n", f);
	// print_stack(a[0], b[0]);
	// ft_printf("-----------------------------\n");
	// ft_printf("TOTAL: %d\n", ++g_c);
	// print_stack(a[0], b[0]);
	return (1);
}

// static t_list	*combine_inst(t_list *a, t_list *b, int (*cmp)())
// {
// 	t_list	*temp;
// 	t_list	*res;
// 	int		flag;

// 	res = NULL;
// 	while (b)
// 	{
// 		flag = 0;
// 		temp = a;
// 		while (temp)
// 		{
// 			if (!cmp(b->content, "rrb", 3) && !cmp(temp->content, "rra", 3))
// 			{
// 				ft_lstadd_back(&res, ft_lstnew(ft_strdup("rrr")));
// 				flag = 1;
// 				break ;
// 			}
// 			else if (!cmp(b->content, "rb", 2) && !cmp(temp->content, "ra", 2))
// 			{
// 				ft_lstadd_back(&res, ft_lstnew(ft_strdup("rr")));
// 				flag = 1;
// 				break ;
// 			}
// 			temp = temp->next;
// 		}
// 		if (flag)
// 			a = temp->next;
// 		else
// 			ft_lstadd_back(&res, ft_lstnew(ft_strdup(b->content)));
// 		b = b->next;
// 	}
// 	return (res);
// }

static void	run_inst_buff(t_list *buff, t_stack *a, t_stack *b)
{
	while (buff)
	{
		run_inst(buff->content, a, b, 0);
		// ft_printf("a: ");
		// print_numarr(*a);
		// ft_printf("b: ");
		// print_numarr(*b);
		buff = buff->next;
	}
	// ft_printf("\n");
}

void	run_multi_inst(int aindex, int bsize, t_stack *a, t_stack *b)
{
	t_list	*abuff;
	// t_list	*bbuff;
	// t_list	*cbuff;

	abuff = move_top_inst(aindex, a, "ra", "rra");
	if (bsize > 1)
	{
		if (b->value[0] < b->value[1])
		{
			run_inst("sb", a, b, 0);
			run_inst("rb", a, b, 0);
		}
	}
	// bbuff = swap_sort_inst(b, bsize);

	// ft_printf("---------------------------\n");
	// ft_printf("a: ");
	// print_inst(abuff);
	// ft_printf("b: ");
	// print_inst(bbuff);

	// cbuff = combine_inst(abuff, bbuff, ft_strncmp);

	// ft_printf("c: ");
	// print_inst(cbuff);
	// ft_printf("---------------------------\n");

	run_inst_buff(abuff, a, b);

	// ft_printf("after b: ");
	// print_numarr(*b);
	// ft_printf("---------------------------\n");

	ft_lstclear(&abuff, del_lst);
	// ft_lstclear(&bbuff, del_lst);
	// ft_lstclear(&cbuff, del_lst);
}
