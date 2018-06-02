/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:14:49 by fhong             #+#    #+#             */
/*   Updated: 2018/06/01 17:22:18 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char	*my_strsearch(char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			break ;
	if (i == (int)ft_strlen(str) && str[i - 1] != '\n')
		return (0);
	tmp = ft_strnew(i - 1);
	tmp = ft_strncpy(tmp, str, i - 1);
	free(str);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	int			ret;
	char		*tmp;

	if (!buf)
		buf = ft_strnew(BUFF_SIZE);
	if ((read(fd, buf, 0) < 0 || line == NULL))
		return (-1);
	*line = ft_strdup(buf);
	while (!ft_strrchr(*line, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_bzero(buf, ft_strlen(buf));
		free(tmp);
	}
	if (ft_strlen(*line) == 0)
		return (0);
	buf = ft_strcpy(buf, (ft_strchr(*line, '\n') + 1));
	tmp = my_strsearch(*line, '\n');
	*line = ft_strdup(tmp);
	free(tmp);
	return (1);
}
