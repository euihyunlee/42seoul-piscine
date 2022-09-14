/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartographer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:20:15 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 16:57:15 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

int	make_map(t_fd fd, t_map *map)
{
	int		i;
	char	nl;

	map->map = malloc(sizeof (char *) * map->y);
	if (map->map == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < map->y)
		map->map[i] = NULL;
	i = -1;
	while (++i < map->y)
	{
		map->map[i] = make_row(fd, map);
		if (map->map[i] == NULL)
		{
			burn(map);
			return (FALSE);
		}
	}
	if (read(fd.z, &nl, 1) != 0)
	{
		burn(map);
		return (FALSE);
	}
	return (TRUE);
}

char	*make_row(t_fd fd, t_map *map)
{
	char	*row;
	int		x;

	x = map->x + 1;
	row = malloc(x);
	if (row == NULL)
	{
		burn(map);
		exit(EXIT_FAILURE);
	}
	if (read(fd.z, row, x) != x || !check_row(row, map)
		|| row[map->x] != '\n')
		return (NULL);
	return (row);
}

int	check_row(char *row, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->x)
	{
		if (!(row[i] == map->emp || row[i] == map->obs))
			return (FALSE);
	}
	return (TRUE);
}

void	burn(t_map *map)
{
	if (map->map == NULL)
	{
		while (*map->map)
			free(*map->map++);
	}
	return ;
}
