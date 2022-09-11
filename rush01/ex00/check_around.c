/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosulee <hosulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:54:17 by hosulee           #+#    #+#             */
/*   Updated: 2022/09/03 22:21:06 by hosulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_ltor(char mat[][4], int row)
{
	int		cnt;
	char	max_num;
	int		i;

	i = 0;
	max_num = mat[row][i];
	cnt = 1;
	while (i < 4)
	{
		if (mat[row][i] > max_num)
		{
			cnt++;
			max_num = mat[row][i];
		}
		i++;
	}
	return (cnt);
}

int	check_rtol(char mat[][4], int row)
{
	int		cnt;
	char	max_num;
	int		i;

	i = 3;
	max_num = mat[row][i];
	cnt = 1;
	while (i >= 0)
	{
		if (mat[row][i] > max_num)
		{
			cnt++;
			max_num = mat[row][i];
		}
		i--;
	}
	return (cnt);
}

int	check_utod(char mat[][4], int col)
{
	int		cnt;
	char	max_num;
	int		i;

	i = 0;
	max_num = mat[i][col];
	cnt = 1;
	while (i < 4)
	{
		if (mat[i][col] > max_num)
		{
			cnt++;
			max_num = mat[i][col];
		}
		i++;
	}
	return (cnt);
}

int	check_dtou(char mat[][4], int col)
{
	int		cnt;
	char	max_num;
	int		i;

	i = 3;
	max_num = mat[i][col];
	cnt = 1;
	while (i >= 0)
	{
		if (mat[i][col] > max_num)
		{
			cnt++;
			max_num = mat[i][col];
		}
		i--;
	}
	return (cnt);
}

int	check_around(char mat[][4], char *str)
{
	int		i;
	int		j;
	int		idx;
	char	arr[16];

	idx = 0;
	j = 0;
	while (j < 4)
		arr[idx++] = check_utod(mat, j++) + '0';
	j = 0;
	while (j < 4)
		arr[idx++] = check_dtou(mat, j++) + '0';
	j = 0;
	while (j < 4)
		arr[idx++] = check_ltor(mat, j++) + '0';
	j = 0;
	while (j < 4)
		arr[idx++] = check_rtol(mat, j++) + '0';
	i = 0;
	while (str[i] == arr[i] && str[i])
		i++;
	if (i == 16)
		return (1);
	else
		return (0);
}
