/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:14:49 by fhong             #+#    #+#             */
/*   Updated: 2018/05/31 20:40:05 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char	*my_strsearch(char *str, char c)
{
	int 	i;
	char	*tmp;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			break;
	if (i == (int)ft_strlen(str) && str[i - 1] != '\n')
		return (0);
	tmp = ft_strnew(i - 1);
	tmp = ft_strncpy(tmp, str, i - 1);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			ret;
	char		*tmp;
	char	*test;

	if ((fd < 0 || line == NULL))
		return (-1);
	if (!save)
		save = ft_strnew(1);
	*line = ft_strdup(save);
	while (!ft_strchr(*line, '\n'))
	{
		buf = ft_strnew(BUFF_SIZE);
		if(!(ret = read(fd, buf, BUFF_SIZE)))
			return (0);
		*line = ft_strjoin(*line, buf);
		free(buf);
	}
	tmp = *line;
	test = ft_strchr(*line, '\n') + 1;
	save = ft_strdup(test);
	*line = ft_strdup(my_strsearch(*line, '\n'));
	free(tmp);
	return (1);
}
