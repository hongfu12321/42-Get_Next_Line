/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:53:14 by fhong             #+#    #+#             */
/*   Updated: 2018/05/25 16:31:37 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*store_str(char *buf, char **line)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 1;
	while (buf[len] != '\n' && buf[len])
		len++;
	tmp = ft_strnew(len);
	while (i < len)
	{
		tmp[i] = buf[i];
		i++;
	}
	*line = ft_strjoin(*line, tmp);
	if (!buf[i])
		return (&buf[i]);
	return (&buf[i + 1]);
}


int		get_next_line(const int fd, char **line)
{
	static char	*buf;
	static int	index;

	if (!buf)
	   buf = ft_strnew(BUFF_SIZE);
	if (!index)
		index = 0;
	if (!read(fd, store(buf, line), BUFF_SIZE))
		if ((buf = store(buf, line)))
			return (1);
	return (0);
}
