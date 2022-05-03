// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_stack.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
// /*   Updated: 2022/04/30 22:12:40 by fkhan            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// static int	g_c = 0;

// int	run_inst(char *f, t_stack *a, t_stack *b)
// {
// 	// ft_printf("-----------------------------\n");
// 	// print_stack(a[0], b[0]);
// 	if (!ft_strncmp(f, "sa", 2) && !swap(a))
// 		return (0);
// 	else if (!ft_strncmp(f, "sb", 2) && !swap(b))
// 		return (0);
// 	else if (!ft_strncmp(f, "ss", 2) && !swap(a) && !swap(b))
// 		return (0);
// 	else if (!ft_strncmp(f, "pa", 2) && !push(a, b))
// 		return (0);
// 	else if (!ft_strncmp(f, "pb", 2) && !push(b, a))
// 		return (0);
// 	else if (!ft_strncmp(f, "ra", 2) && !rot(a))
// 		return (0);
// 	else if (!ft_strncmp(f, "rb", 2) && !rot(b))
// 		return (0);
// 	else if (!ft_strncmp(f, "rra", 3) && !rrot(a))
// 		return (0);
// 	else if (!ft_strncmp(f, "rrb", 3) && !rrot(b))
// 		return (0);
// 	else if (!ft_strncmp(f, "rrr", 3) && !rrot(a) && !rrot(b))
// 		return (0);
// 	else if (!ft_strncmp(f, "rr", ft_strlen(f)) && !rot(a) && !rot(b))
// 		return (0);
// 	ft_printf("%s\n", f);
// 	// print_stack(a[0], b[0]);
// 	// ft_printf("-----------------------------\n");
// 	ft_printf("TOTAL: %d\n", ++g_c);
// 	// print_stack(a[0], b[0]);
// 	return (1);
// }

// static void	del_lst(void *content)
// {
// 	free(content);
// }

// static void	combine_inst(t_list **a, t_list *b, int (*c)())
// {
// 	t_list	*temp;

// 	temp = a[0];
// 	while (b && temp)
// 	{
// 		while (temp)
// 		{
// 			if (!c(b->content, "rb", 2) && !c(temp->content, "ra", 2))
// 			{
// 				free(temp->content);
// 				temp->content = ft_strdup("rr");
// 				temp = temp->next;
// 				break ;
// 			}
// 			else if (!c(b->content, "rrb", 3) && !c(temp->content, "rra", 3))
// 			{
// 				free(temp->content);
// 				temp->content = ft_strdup("rrr");
// 				temp = temp->next;
// 				break ;
// 			}
// 			temp = temp->next;
// 		}
// 		b = b->next;
// 	}
// }

// void	run_multi_inst(int aindex, int bindex, t_stack *a, t_stack *b)
// {
// 	t_list	*curr_buff;
// 	t_list	*abuff;
// 	t_list	*bbuff;

// 	abuff = move_top_inst(aindex, a, "ra", "rra");
// 	bbuff = move_top_inst(bindex, b, "rb", "rrb");

// 	// print_inst(abuff, bbuff);

// 	combine_inst(&abuff, bbuff, ft_strncmp);
// 	curr_buff = abuff;
// 	while (curr_buff)
// 	{
// 		run_inst(curr_buff->content, a, b);
// 		curr_buff = curr_buff->next;
// 	}
// 	ft_lstclear(&abuff, del_lst);
// 	ft_lstclear(&bbuff, del_lst);
// }

// static void	swap_sort_stack(t_stack *a, t_stack *b, int n)
// {
// 	int	i;
// 	int	count;

// 	if (n <= 1)
// 		return ;
// 	i = 1;
// 	count = 1;
// 	// ft_printf("---------------------------\n");
// 	// ft_printf("before b: ");
// 	// print_numarr(*b);
// 	while (i > 0)
// 	{
// 		while (i < n)
// 		{
// 			if (b->value[0] < b->value[1])
// 			{
// 				run_inst("sb", a, b);
// 				if (i == n - count)
// 				{
// 					count++;
// 					break ;
// 				}
// 				run_inst("rb", a, b);
// 			}
// 			else
// 			{
// 				if (i == n - count)
// 				{
// 					count++;
// 					break ;
// 				}
// 				run_inst("rb", a, b);
// 			}
// 			i++;
// 		}
// 		while (i-- != 0)
// 		{
// 			if (i > 0)
// 				run_inst("rrb", a, b);
// 			if (b->value[0] < b->value[1])
// 				break ;
// 		}
// 	}
// 	// ft_printf("after b: ");
// 	// print_numarr(*b);
// 	// ft_printf("---------------------------\n");
// }