/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:05:42 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 20:28:06 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "katsuou.h"

int	main(int argc, char **argv)
{
	int fd1;

	if (argc == 1)
		fd1 = 0;
	else
	{
		i = -1;
		while (++i < argc)
		{
			if (!read_map(argv[i]))
			{
				// print map error and exit
			}
		}
	}
}
