/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:05:09 by euihlee           #+#    #+#             */
/*   Updated: 2022/08/28 14:05:38 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);
void		printrow(int x, char left, char mid, char right);

void	rush(int x, int y)
{
	char	corner[4];
	char	hor;
	char	ver;
	int		row;

	if (x < 1 || y < 1)
		return ;
	corner[0] = 'o';
	corner[1] = 'o';
	corner[2] = 'o';
	corner[3] = 'o';
	hor = '-';
	ver = '|';
	printrow(x, corner[0], hor, corner[1]);
	if (y > 1)
	{
		row = 1;
		while (++row < y)
		{
			printrow(x, ver, ' ', ver);
		}
		printrow(x, corner[2], hor, corner[3]);
	}
}

void	printrow(int x, char left, char mid, char right)
{
	int	col;

	ft_putchar(left);
	if (x > 1)
	{
		col = 1;
		while (++col < x)
		{
			ft_putchar(mid);
		}
		ft_putchar(right);
	}
	ft_putchar('\n');
}
