/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:45:33 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/15 02:56:46 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

void	x_marks_the_spot(t_map map, t_max max)
{
	int	i;
	int	j;

	i = max.i;
	while (i > max.i - max.val)
	{
		j = max.j;
		while (j > max.j - max.val)
		{
			map.map[i][j] = map.ful;
			j--;
		}
		i--;
	}
	return ;
}

void	print_square(t_map map)
{
	int	i;

	i = -1;
	while (++i < map.y)
		write(1, map.map[i], map.x + 1);
	return ;
}
