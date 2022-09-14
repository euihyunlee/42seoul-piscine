/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:05:42 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/15 03:27:07 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

int	main(int argc, char **argv)
{
	char	*file;
	int		i;
	t_map	map;
	t_max	max;

	file = NULL;
	i = 0;
	if (argc == 1)
		i--;
	while (++i < argc)
	{
		if (argc > 1)
			file = argv[i];
		if (!survey(file, &map))
		{
			write(1, "map error\n", 10);
			continue ;
		}
		max.val = 0;
		find_square(&map, &max);
		x_marks_the_spot(map, max);
		print_square(map);
		burn(&map);
	}
}
