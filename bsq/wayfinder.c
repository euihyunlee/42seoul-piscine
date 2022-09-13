/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wayfinder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:06:06 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 05:13:18 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	find_square(t_map map, t_max *max)
{
	char	arr[128];
	int		**buf;
	int		i;
	int		j;
	int		row;

	arr[map.obs] = 0;
	arr[map.emp] = 1;
	buf = get_buf(map);
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

int	**get_buf(t_map map, char *arr)
{
	int	**buf;

	buf = malloc(sizeof (int *) * 2);
	if (buf == NULL)
	{
		burn(map);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < 2)
	{
		buf[i] = malloc(sizeof (int) * map.x)
		if (buf[i] == NULL)
		{
			if (i == 1)
				free(buf[0]);
			burn(map);
			exit(EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < map.x)
		buf[0][i] = arr[map.map[0][i]];
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
	while (++j < map.x)
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
