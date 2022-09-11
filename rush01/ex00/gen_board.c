/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosulee <hosulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:28:03 by hosulee           #+#    #+#             */
/*   Updated: 2022/09/03 22:01:08 by hosulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_around(char mat[][4], char *str);

void	print_board(char mat[][4])
{
	int	i;

	i = 0;
	while (i <= 15)
	{
		write(1, &mat[i / 4][i % 4], 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

int	is_valid_hor(int pos, char mat[][4])
{
	int	line;
	int	arr[4];
	int	k;

	k = 0;
	line = pos / 4;
	while (k < 4)
	{
		arr[k] = mat[line][k] - '0';
		k++;
	}
	if (arr[0] + arr[1] + arr[2] + arr[3] == 10)
	{
		if (arr[0] * arr[1] * arr[2] * arr[3] == 24)
			return (1);
	}
	return (0);
}

int	is_valid_vert(char mat[][4])
{
	int	line;
	int	arr[4];
	int	k;

	line = 0;
	while (line < 4)
	{
		k = 0;
		while (k < 4)
		{
			arr[k] = mat[k][line] - '0';
			k++;
		}
		if (arr[0] + arr[1] + arr[2] + arr[3] != 10)
			return (0);
		else if (arr[0] * arr[1] * arr[2] * arr[3] != 24)
			return (0);
		line++ ;
	}
	return (1);
}

void	check_board(int pos, char mat[][4], int *flag, char *str)
{
	if (is_valid_hor(pos, mat) && is_valid_vert(mat))
	{
		if (check_around(mat, str))
		{
			print_board(mat);
			*flag = 1;
		}
	}
}

void	gen_board(int pos, char mat[][4], int *flag, char *str)
{
	int	i;

	if (!*flag)
	{
		i = 1;
		while (i <= 4)
		{
			mat[pos / 4][pos % 4] = '0' + i;
			if (pos == 15)
				check_board(pos, mat, flag, str);
			else if (pos % 4 == 3)
			{
				if (is_valid_hor(pos, mat))
					gen_board(pos + 1, mat, flag, str);
			}
			else
				gen_board(pos + 1, mat, flag, str);
			i++;
		}
	}
}
