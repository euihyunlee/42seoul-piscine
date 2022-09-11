/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:39:56 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/06 18:03:31 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		place_queen(int *board, int col);
int		threat(int *board, int col, int row);
void	print_board(int *board);

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;

	i = -1;
	while (++i < 10)
		board[i] = 0;
	return (place_queen(board, 0));
}

int	place_queen(int *board, int col)
{
	static int	count;
	int			row;

	if (col == 10)
	{
		print_board(board);
		count++;
		return (0);
	}
	row = -1;
	while (++row < 10)
	{
		if (!threat(board, col, row))
		{
			board[col] = row;
			place_queen(board, col + 1);
		}
	}
	return (count);
}

int	threat(int *board, int col, int row)
{
	int	i;

	i = -1;
	while (++i < col)
	{
		if (board[i] == row
			|| board[i] + i == row + col || board[i] - i == row - col)
			return (1);
	}
	return (0);
}

void	print_board(int *board)
{
	char	buf[10];
	int		i;

	i = -1;
	while (++i < 10)
		buf[i] = board[i] + '0';
	write(1, buf, 10);
	write(1, "\n", 1);
}
