/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:53:14 by fhong             #+#    #+#             */
/*   Updated: 2018/05/23 20:03:39 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*store_str(char *buf, char **line, int index)
{
	int i;
	int len;

	i = 0;
	len = 1;
	while (buf[len] != '\n' && !buf[len])
		len++;
	line[index] = ft_strnew(len);
	while (i < len)
	{
		line[index][i] = buf[i];
		i++;
	}
	line[i] = '\0';
	if (!buf[i])
		return (&buf[i]);
	return (&buf[i + 1]);
}


int		get_next_line(const int fd, char **line)
{
	static char	*buf;
	static int	index;

	if (!buf)
	   buf = ft_strnew(BUFF_SIZE * 2);
	if (!index)
		index = 0;
	if (!read(fd, buf, BUFF_SIZE))
		return (0);
	while (buf = store_str(buf, line, index))
		index++;
	return (1);

}
