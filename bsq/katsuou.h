/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   katsuou.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:16:03 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 07:07:15 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KATSUOU_H
# define KATSUOU_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0

typedef struct s_map
{
	int		**map;
	int		x;
	int		y;
	char	emp;
	char	obs;
	char	ful;
}	t_map;

typedef struct s_fd
{
	int	a;
	int	z;
}	t_fd;

typedef struct s_max
{
	int	val;
	int	i;
	int	j;
}	t_max;

void	find_square(t_map map, t_max *max);
int	**get_buf(t_map map, int *arr);
int	get_min(int i, int j, int k);
void	get_max(int **buf, int i, t_max *max);

#endif
