/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wayfinder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:06:06 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/15 02:45:22 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

void	find_square(t_map *map, t_max *max)
{
	int		arr[128];
	int		**buf;
	int		i;
	int		j;
	int		row;

	i = -1;
	while (++i < 128)
		arr[i] = 0;
	arr[(int) map->emp] = 1;
	buf = get_buf(map, arr);
	/*
	for (int k = 0; k < map->x; k++)
		printf("%d ", buf[0][k]);
	printf("\n");
	*/
	i = 0;
	while (++i < map->y)
	{
		row = i % 2;
		j = -1;
		while (++j < map->x)
		{
			if (j == 0)
				buf[row][j] = arr[(int) map->map[i][j]];
			else if (map->map[i][j] == map->obs)
				buf[row][j] = 0;
			else
				buf[row][j] = get_min(buf[!row][j - 1], buf[!row][j], buf[row][j - 1]);
		}
		/*
		for (int k = 0; k < map->x; k++)
			printf("%d ", buf[row][k]);
		printf("\n");
		*/
		get_max(buf, i, max, map);
	}
	free(buf[0]);
	free(buf[1]);
	free(buf);
	return ;
}

int	**get_buf(t_map *map, int *arr)
{
	int	**buf;
	int	i;
	int	j;

	buf = malloc(sizeof (int *) * 2);
	if (buf == NULL)
	{
		burn(map);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < 2)
	{
		buf[i] = malloc(sizeof (int) * map->x);
		if (buf[i] == NULL)
		{
			if (i == 1)
				free(buf[0]);
			burn(map);
			exit(EXIT_FAILURE);
		}
	}
	j = -1;
	while (++j < map->x)
		buf[0][j] = arr[(int) map->map[0][j]];
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

void	get_max(int **buf, int i, t_max *max, t_map *map)
{
	int	j;

	j = -1;
	while (++j < map->x)
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
