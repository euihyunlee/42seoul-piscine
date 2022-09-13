/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartographer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:20:15 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 03:33:22 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	make_map(t_fd fd, t_map *map)
{
	int		i;
	char	nl;

	map->map = malloc(sizeof (int *) * map->y);
	if (map->map == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < map->y)
		*map++ = make_row(fd, map)
	if (read(fd, nl, 1) != 0)
	{
		burn(map);
		return (FALSE);
	}
	return (TRUE);
}

int	make_row(t_fd fd, t_map *map)
{
	int	*row;

	row = malloc(sizeof (int) * map->x);
	if (row == NULL)
	{
		// TODO: burn map
		burn(map);
		exit(EXIT_FAILURE);
	}
	// TODO: burn and return false if newline in row
	// make read_row func to check valid row
	if (read(fd.z, row, map->x) != map->x
		|| read(fd.z, &nl, 1) != 1 || nl != '\n')
	{
		burn(map);
		return (FALSE);
	}
	*map++ = row;
}

void	burn(t_map *map);
{
	while (map->map != NULL)
	{

	}
}

int	check_x(t_fd fd, t_map map)
{
	int		x;
	char	c;

	x = 0;
	while (read(fd.a, &c, 1) == 1 && c != '\n')
	{
		if (!(c == map->emp || c == map->obs))
			return (0);
		x++;
	}
	if (x != map->x)
		return (0);
	return (1);
}
