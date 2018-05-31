/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:53:14 by fhong             #+#    #+#             */
/*   Updated: 2018/05/30 20:35:01 by fhong            ###   ########.fr       */
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

int		newline_index(char *str)
{
	int index;

	index = 0;
	while (str[index])
		if (str[index++] == '\n')
			return (index);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			ret;

	if ((fd < 0 || line == NULL))
		return (-1);
	if (!save)
		save = ft_strnew(1);
	*line = ft_strnew(1);
	while (!newline_index(save))
	{
		buf = ft_strnew(BUFF_SIZE);
		if(!(ret = read(fd, buf, BUFF_SIZE)))
			return (0);
		save = ft_strjoin(save, buf);
	}
	*line = ft_strdup(my_strsearch(save, '\n'));
	save = ft_strdup(&save[newline_index(save)]);
	return (1);
}
