/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartographer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:20:15 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 22:22:50 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**make_map(int fd, t_map map)
{
	char	**map;
	int		i;
	char	*row;
	char	nl;

	map = malloc(sizeof (char *) * key.size);
	if (map == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < key.size)
	{
		row = malloc(sizeof (char) * key.size);
		if (row == NULL)
		{
			burn(map);
			exit(EXIT_FAILURE);
		}
		if (read(fd, row, key.size) != key.size
			|| read(fd, &nl, 1) != 1 || nl != '\n')
		{
			burn(map);
			return (NULL);
		}
		*map++ = row;
	}
	if (read(fd, nl, 1) != 0)
	{
		burn(map);
		return (NULL);
	}
	return (map);
}
