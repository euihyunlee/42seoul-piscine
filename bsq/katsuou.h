/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   katsuou.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:16:03 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 17:40:10 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KATSUOU_H
# define KATSUOU_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0

# include <stdio.h>

typedef struct s_map
{
	char	**map;
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

int	survey(char *file, t_map *map);
int	get_fd(char *file, t_fd *fd);
int	read_header(t_fd fd, t_map *map);
int	get_y(t_fd fd, int len);
int	get_x(t_fd fd, t_map *map);

int	make_map(t_fd fd, t_map *map);
char	*make_row(t_fd fd, t_map *map);
int	check_row(char *row, t_map *map);
void	burn(t_map *map);

void	find_square(t_map *map, t_max *max);
int	**get_buf(t_map *map, int *arr);
int	get_min(int i, int j, int k);
void	get_max(int **buf, int i, t_max *max, t_map *map);

#endif
