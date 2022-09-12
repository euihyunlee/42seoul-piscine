/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surveyor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:19:51 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 22:22:08 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	survey(char *file)
{
	int		fd1;
	int		fd2;
	t_map	map;

	fd1 = open(file, O_RDONLY);
	if (fd1 < 0)
		exit(EXIT_FAILURE);
	fd2 = open(file, O_RDONLY);
	if (fd2 < 0)
	{
		close(fd1);
		exit(EXIT_FAILURE);
	}
	map = read_header(fd1, fd2);
	close(fd2);
	if(map == NULL || map.scale < 1)
	{
		close(fd1);
		return (FALSE);
	}
	map.map = make_map(fd1, map);
	close(fd1);
	return (CHECK(map));
}

t_map	*read_header(int fd1, int fd2)
{
	t_map	*map;
	char	c;
	char	symb[3];
	
	map = malloc(sizeof (t_map));
	if (map == NULL)
		exit(EXIT_FAILURE);
	map->scale = get_scale(fd1, fd2, &c);
	if (map->scale < 0
		|| read(fd1, symb, 3) != 3 || !is_printable(symb)
		|| c != '\n')
	{
		free(map);
		return (NULL);
	}
	map->emp = arr[0];
	map->obs = arr[1];
	map->ful = arr[2];
	read(fd2, symb, 3);
	return (map);
}

int	get_scale(int fd1, int fd2, char *c)
{
	int		len;
	char	*nbr;
	int		scale;

	len = 0;
	while (read(fd1, c, 1) == 1)
	{
		if ('0' <= *c && *c <= '9')
			len++;
		else
			break ;
	}
	nbr = malloc(len + 1);
	if (nbr == NULL)
		exit(EXIT_FAILURE);
	nbr[len] = '\0';
	read(fd2, nbr, len);
	scale = ft_atoi(nbr);
	free(nbr);
	return (scale);
}

int	is_printable(char *arr)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!(' ' <= arr[i] && arr[i] <= '~'))
			return (FALSE);
		j = i;
		while (--j <= 0)
		{
			if (arr[i] = arr[j])
				return (FALSE);
		}
	}
	return (TRUE);
}
