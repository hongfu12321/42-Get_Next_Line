/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:26:10 by fhong             #+#    #+#             */
/*   Updated: 2018/05/30 20:35:19 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	if (ac == 2)
		close(fd);
	return (0);
}
