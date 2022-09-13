/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wayfinder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:06:06 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 07:23:37 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

void	find_square(t_map map, t_max *max)
{
	int		arr[128];
	int		**buf;
	int		i;
	int		j;
	int		row;

	arr[(int) map.obs] = 0;
	arr[(int) map.emp] = 1;
	buf = get_buf(map, arr);
	i = 0;
	while (++i < map.y)
	{
		row = i % 2;
		j = 0;
		while (++j < map.x)
		{
			if (j == 0)
				buf[row][j] = map.map[i][j];
			else if (map.map[i][j] == map.obs)
				buf[row][j] = 0;
			else
				buf[row][j] = get_min(buf[!row][j - 1], buf[!row][j], arr[map.map[i][j - 1]]);
			get_max(buf, i, max);
		}
	}
}

int	**get_buf(t_map map, int *arr)
{
	int	**buf;
	int	i;

	buf = malloc(sizeof (int *) * 2);
	/*
	if (buf == NULL)
	{
		burn(map);
		exit(EXIT_FAILURE);
	}
	*/
	i = -1;
	while (++i < 2)
	{
		buf[i] = malloc(sizeof (int) * map.x);
		/*
		if (buf[i] == NULL)
		{
			if (i == 1)
				free(buf[0]);
			burn(map);
			exit(EXIT_FAILURE);
		}
		*/
	}
	i = -1;
	while (++i < map.x)
		buf[0][i] = arr[(int) map.map[0][i]];
	return (buf);
}

int	get_min(int i, int j, int k)
{
	int	min;

	min = i;
	if (j < min)
		min = j;
	if (k < min)
		min = k;
	return (min + 1);
}

void	get_max(int **buf, int i, t_max *max)
{
	int	j;

	i = -1;
	// TODO: REMOVE HARDCODED 100
	while (++j < 100)
	{
		if (buf[i % 2][j] > max->val)
		{
			max->val = buf[i % 2][j];
			max->i = i;
			max->j = j;
		}
	}
	return ;
}

// TODO: remove stdio.h and printf
#include <stdio.h>

int	main(void)
{
	t_fd 	fd;
	t_map	map;
	char	buf[1024];
	int		i;
	int		*row;
	t_max	max;

	fd.a = open("testmap", O_RDONLY);
	map.x = 100;
	map.y = 100;
	map.emp = '.';
	map.obs = 'o';
	map.ful = 'x';
	read(fd.a, buf, 7);
	map.map = malloc(sizeof (int *) * map.y);
	i = -1;
	while (++i < map.y)
	{
		row = malloc(sizeof (int) * map.x);
		read(fd.a, row, map.x);
		map.map[i] = row;
		read(fd.a, buf, 1);
	}
	find_square(map, &max);
	printf("maxval: %d | maxi: %d | maxj: %d\n", max.val, max.i, max.j);
	close(fd.a);
	return (0);
}
