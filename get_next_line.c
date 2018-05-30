/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:53:14 by fhong             #+#    #+#             */
/*   Updated: 2018/05/29 20:18:31 by fhong            ###   ########.fr       */
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
	if (i == (int)ft_strlen(str))
	{
		return (0);
	}
	tmp = ft_strnew(i - 1);
	tmp = ft_strncpy(tmp, str, i -1);
	return (tmp);
}

int		newline_index(char *str)
{
	int index;

	index = 0;
	while (str[index])
		if (str[index++] == '\n')
			return (index);
	if (ft_strlen(str) < BUFF_SIZE)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (!save)
		save = ft_strnew(1);
	*line = ft_strnew(1);
	buf[BUFF_SIZE] = '\0';
	if ((tmp = my_strsearch(save, '\n')))
	{
		*line = ft_strdup(tmp);
		free(tmp);
		save = ft_strdup(&save[newline_index(save)]);
		return (1);
	}
	else
	{
		while (!newline_index(save))
		{
			ret = read(fd, buf, BUFF_SIZE);
			save = ft_strjoin(save, buf);
		}
		if (ret != 0)
		{
			{
				*line = ft_strdup(my_strsearch(save, '\n'));
				save = ft_strdup(&save[newline_index(save)]);
				return (1);
			}
		}
		else
			return (0);
		return (1);
	}
}
