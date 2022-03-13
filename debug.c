/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:57:52 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/13 12:41:43 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack a, t_stack b)
{
	ft_printf("a: ");
	print_numarr(a);
	ft_printf("b: ");
	print_numarr(b);
}

void	print_numarr(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.size)
		ft_printf("%-5d", a.value[i++]);
	ft_printf("\n");
}
