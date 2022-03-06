/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:57:52 by fkhan             #+#    #+#             */
/*   Updated: 2022/03/06 15:01:32 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int *a, int *b, int n)
{
	ft_printf("a: ");
	print_numarr(a, n);
	ft_printf("b: ");
	print_numarr(b, n);
}

void	print_numarr(int *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_printf("%-5d", a[i++]);
	ft_printf("\n");
}
