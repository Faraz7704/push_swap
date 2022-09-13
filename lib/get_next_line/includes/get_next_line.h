/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:07:34 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 23:25:04 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);
size_t	strlen_sep(const char *str, char sep);
size_t	strlcpy_sep(char *dest, const char *src, size_t n, char sep);
char	*strdup_sep(const char *str, char sep);
char	*gnl_strjoin(const char *s1, const char *s2);

#endif