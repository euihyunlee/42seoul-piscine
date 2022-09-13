/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surveyor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:19:51 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 06:39:15 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	survey(char *file, t_map *map)
{
	t_fd	fd;

	if (!get_fd(file, &fd))
		return (FALSE)
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
	if (file == NULL)
	{
		fd->a = 0;
		fd->z = 0;
	}
	else
	{
		fd->a = open(file, O_RDONLY);
		if (fd->a < 0)
			return (FALSE);
		fd->z = open(file, O_RDONLY);
		if (fd->z < 0)
		{
			close(fd->a);
			return (FALSE);
		}
	}
	return (TRUE);
}

t_map	*read_header(t_fd fd, t_map *map)
{
	int		len;
	char	c;
	char	*buf;
	
	len = 0;
	while (read(fd.a, &c, 1) == 1 && c != '\n')
	{
		if (!(' ' <= arr[i] && arr[i] <= '~'))
			return (FALSE);
		len++;
	}
	if (len < 4)
		return (FALSE);
	buf = malloc(len - 3);
	if (buf == NULL)
		exit(EXIT_FAILURE);
	read(fd.z, buf, len - 3);
	map->y = get_y(len - 3, buf);
	free(buf);
	map->x = get_x(fd, map);
	return (TRUE);
}

// TODO: atoi invalid number
int	get_y(int len, char *str)
{
	int	i;
	int	y;

	y = 0;
	i = -1;
	while (++i < len)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (-1);
		y = y * 10 + (str[i] - '0');
	}
	return (y);
}

int	get_x(t_fd fd, tmap *map)
{
	int		x;
	char	c;

	read(fd.z, map->emp, 1);
	read(fd.z, map->obs, 1);
	read(fd.z, map->ful, 1);
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
