/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:18:04 by jpark2            #+#    #+#             */
/*   Updated: 2022/09/11 23:37:14 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	write_in_file(int fd, char *str, int len)
{
	if (write(fd, str, len) == -1)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (1);
}

void	add_line_in_file(char *file, char *key, char *value)
{
	int	fd;
	int	i;

	fd = open(file, O_RDWR | O_APPEND);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	i = 0;
	while (key[i] != 0)
		i++;
	if (write_in_file(fd, key, i) == 0)
		return ;
	write(fd, " : ", 3);
	i = 0;
	while (value[i] != 0)
		i++;
	if (write_in_file(fd, value, i) == 0)
		return ;
	write(fd, "\n", 1);
	close(fd);
	return ;
}

void	rewrite_file(char *file, t_node *list)
{
	int	fd;

	fd = open(file, O_WRONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	while (list != 0)
	{
		write(fd, list->key, str_len(list->key));
		write(fd, " : ", 3);
		write(fd, list->val, str_len(list->val));
		write(fd, "\n", 1);
		list = list->next;
	}
	close(fd);
}
