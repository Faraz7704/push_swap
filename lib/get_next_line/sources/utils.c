/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:22 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 23:24:59 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_sep(const char *str, char sep)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

size_t	strlcpy_sep(char *dest, const char *src, size_t n, char sep)
{
	size_t	i;
	size_t	srcsize;

	if (!src)
		return (0);
	i = 0;
	srcsize = strlen_sep(src, sep);
	if (n > 0)
	{
		while (src[i] != sep && i < n - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = src[i];
	}
	return (srcsize);
}

char	*strdup_sep(const char *str, char sep)
{
	int		len;
	char	*result;

	len = strlen_sep(str, sep) + 1;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	strlcpy_sep(result, str, len, sep);
	result[len] = '\0';
	return (result);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		total_size;
	char	*result;

	i = 0;
	j = 0;
	total_size = strlen_sep(s1, '\0') + strlen_sep(s2, '\0') + 1;
	if (total_size == 1)
		return (0);
	result = (char *)malloc(total_size);
	if (!result)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
