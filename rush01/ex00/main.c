/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:47:02 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/03 22:20:39 by hosulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*valid_input(char *str);
void	gen_board(int pos, char mat[][4], int *flag, char *str);

void	init(char mat[][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			mat[i][j++] = '0';
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	mat[4][4];
	int		flag;
	char	*str;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	flag = 0;
	init(mat);
	str = valid_input(argv[1]);
	if (str)
	{
		gen_board(0, mat, &flag, str);
		if (!flag)
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
