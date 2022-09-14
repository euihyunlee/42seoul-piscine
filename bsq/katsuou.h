/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   katsuou.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:16:03 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/14 16:32:35 by euihlee          ###   ########.fr       */
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

#endif
