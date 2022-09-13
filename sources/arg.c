/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 17:06:59 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isnumber(int num, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && !ft_isdigit(str[0]))
		return (0);
	if ((num == -1 || num == 0) && i >= 10)
		return (0);
	return (1);
}

int	*parse_arg(char **av, int n, int *reflen)
{
	int		i;
	char	**args;
	int		*lst;

	args = ft_argsplit(av, n, ' ');
	*reflen = ft_arglen(args);
	lst = ft_calloc(sizeof(int), *reflen + 1);
	if (!lst)
		exit(1);
	i = 0;
	while (i < *reflen)
	{
		lst[i] = ft_atoi(args[i]);
		if (!isnumber(lst[i], args[i]) || ft_numncmp(lst, lst[i], i))
		{
			ft_freearg(args);
			free(lst);
			return (0);
		}
		i++;
	}
	ft_freearg(args);
	return (lst);
}
