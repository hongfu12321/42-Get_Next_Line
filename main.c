/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:26:10 by fhong             #+#    #+#             */
/*   Updated: 2018/05/30 13:25:18 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		i = 0;
	char	*line;
	int		fd;
	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) && i < 10)
	{
		ft_putendl(line);
		free(line);
		i++;
	}
	if (i == 10)
		printf("FUCK!!\n");
	if (ac == 2)
		close(fd);
	return (0);
}
