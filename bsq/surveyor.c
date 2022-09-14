/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surveyor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:19:51 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/15 08:11:12 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

int	survey(char *file, t_map *map)
{
	t_fd	fd;

	if (!get_fd(file, &fd))
		return (FALSE);
	if(!read_header(fd, map) || map->y < 1 || map->x < 1)
	{
		close(fd.a);
		close(fd.z);
		return (FALSE);
	}
	return (make_map(fd, map));
}

int	get_fd(char *file, t_fd *fd)
{
	char	c;

	if (file == NULL)
	{
		fd->a = open("tmpfile", O_CREAT | O_RDWR | O_TRUNC);
		if (fd->a < 0)
			return (FALSE);
		while (read(0, &c, 1) == 1)
			write(fd->a, &c, 1);
		file = "tmpfile";
		close(fd->a);
	}
	fd->a = open(file, O_RDONLY);
	if (fd->a < 0)
		return (FALSE);
	fd->z = open(file, O_RDONLY);
	if (fd->z < 0)
	{
		close(fd->a);
		return (FALSE);
	}
	return (TRUE);
}

int	read_header(t_fd fd, t_map *map)
{
	int		len;
	char	c;
	
	len = 0;
	while (read(fd.a, &c, 1) == 1 && c != '\n')
	{
		if (!(' ' <= c && c <= '~'))
			return (FALSE);
		len++;
	}
	if (len < 4)
		return (FALSE);
	map->y = get_y(fd, len - 3);
	map->x = get_x(fd, map);
	return (TRUE);
}

int	get_y(t_fd fd, int len)
{
	char	*buf;
	int		y;
	int		i;

	buf = malloc(len);
	if (buf == NULL)
		exit(EXIT_FAILURE);
	read(fd.z, buf, len);
	y = 0;
	i = -1;
	while (++i < len)
	{
		if (!('0' <= buf[i] && buf[i] <= '9'))
		{
			free(buf);
			return (-1);
		}
		y = y * 10 + (buf[i] - '0');
	}
	free(buf);
	return (y);
}

int	get_x(t_fd fd, t_map *map)
{
	int		x;
	char	c;

	read(fd.z, &map->emp, 1);
	read(fd.z, &map->obs, 1);
	read(fd.z, &map->ful, 1);
	if (map->emp == map->obs
		|| map->obs == map->ful
		|| map->ful == map->emp)
		return (-1);
	read(fd.z, &c, 1);
	x = 0;
	while (read(fd.a, &c, 1) == 1 && c != '\n')
	{
		if (!(c == map->emp || c == map->obs))
			return (-1);
		x++;
	}
	return (x);
}
