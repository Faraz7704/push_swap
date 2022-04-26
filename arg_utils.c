/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:39:47 by fkhan             #+#    #+#             */
/*   Updated: 2022/04/26 14:25:56 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arglen(char **args)
{
	int		i;
	int		len;

	if (!args)
		return (0);
	len = 0;
	i = 0;
	while (args[i++])
		len++;
	return (len);
}

void	ft_freearg(char **args)
{
	int		i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

char	**ft_argjoin(char **s1, char **s2)
{
	int		i;
	int		j;
	int		total_size;
	char	**result;

	i = 0;
	j = 0;
	total_size = ft_arglen(s1) + ft_arglen(s2) + 1;
	if (total_size == 1)
		return (0);
	result = (char **)malloc(sizeof(char *) * total_size);
	if (!result)
		return (0);
	while (s1 && s1[i])
	{
		result[i] = ft_strdup(s1[i]);
		i++;
	}
	while (s2 && s2[j])
		result[i++] = ft_strdup(s2[j++]);
	result[i] = 0;
	return (result);
}

char	**ft_argsplit(char **args, int n, char sep)
{
	int		i;
	char	**res;
	char	**temp;

	res = NULL;
	i = 0;
	while (i < n)
	{
		temp = ft_argjoin(res, ft_split(args[i], sep));
		ft_freearg(res);
		res = temp;
		i++;
	}
	return (res);
}
