/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:05:42 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 23:03:27 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

int	main(int argc, char **argv)
{
	char	*file;
	int		i;
	t_map	map;
	t_max	max;

	i = 0;
	if (argc == 1)
	{
		file = NULL;
		i--;
	}
	while (++i < argc)
	{
		if (argc > 1)
			file = argv[i];
		if (!survey(file, &map))
		{
			write(1, "map error\n", 10);
			continue ;
		}
		// TODO
		max.val = 0;
		max.i = 0;
		max.j = 0;
		find_square(&map, &max);
		printf("maxval: %d | maxi: %d | maxj: %d\n", max.val, max.i, max.j);
	}
	return (0);
}
