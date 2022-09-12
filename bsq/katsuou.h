/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   katsuou.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:16:03 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 22:11:41 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KATSUOU_H
# define KATSUOU_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0
# define CHECK(a) (a) == 0 ? FALSE : TRUE

typedef struct s_map
{
	char	**map;
	int		scale;
	char	emp;
	char	obs;
	char	ful;
}	t_map;

#endif
