/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:37:28 by jpark2            #+#    #+#             */
/*   Updated: 2022/09/11 23:08:15 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	input_number_validate(char *str)
{
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		str++;
	}
	return (1);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	seperate_num_and_print(char **n_print, t_node *list)
{
	int	i;
	int	idx;

	i = 0;
	while (n_print[i] != 0)
	{
		idx = find_key_in_list(n_print[i], 0, list);
		if (idx < 0)
		{
			ft_putstr("Error\n");
			return ;
		}
		i++;
	}
	i = 0;
	while (n_print[i] != 0)
	{
		idx = find_key_in_list(n_print[i], 0, list);
		if (i != 0)
			write(1, " ", 1);
		print_value_in_list(list, idx);
		i++;
	}
	write(1, "\n", 1);
}

void	find_and_write_on_dict(char **av, t_node *list)
{
	int	idx;

	if (input_number_validate(av[1]) == 1)
	{
		idx = find_key_in_list(av[1], av[2], list);
		if (idx >= 0)
			rewrite_file(DICT, list);
		else
			add_line_in_file(DICT, av[1], av[2]);
	}	
}

int	main(int ac, char **av)
{
	char	**n_print;
	t_node	*list;

	list = NULL;
	load(DICT, &list);
	if (ac == 2)
	{
		if (input_number_validate(av[1]) == 1)
		{
			n_print = unit_seperate(av[1]);
			seperate_num_and_print(n_print, list);
			free_arr(n_print);
		}
	}
	else if (ac == 3)
		find_and_write_on_dict(av, list);
	else
		ft_putstr("Error\n");
	unload(&list);
}
