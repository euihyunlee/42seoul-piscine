/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:29:30 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 14:59:51 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			ac;
	char		**av;
	t_stock_str	*par;
	int			i;

	if (argc == 1)
	{
		printf("missing arguments\n");
		return (1);
	}
	ac = argc - 1;
	av = argv + 1;
	if (av[ac] != NULL)
	{
		printf("check ac, av\n");
		return (1);
	}
	par = ft_strs_to_tab(ac, av);
	ft_show_tab(par);
	i = -1;
	while (++i < ac)
		free(par[i].copy);
	free(par);
	system("leaks a.out");
	return (0);
}
