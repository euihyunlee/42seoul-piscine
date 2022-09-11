/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:42:25 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/04 19:16:00 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	check_input(char *str, char *buf, int *flag)
{
	int	i;

	i = -1;
	while (str[++i] && !*flag)
	{
		if (i == 31)
			*flag = 1;
		else if (i % 2 == 0)
		{
			if ('1' <= str[i] && str[i] <= '4')
				buf[i / 2] = str[i];
			else
				*flag = 1;
		}
		else if (str[i] != ' ')
			*flag = 1;
	}
}

char	*valid_input(char *str)
{
	char	*buf;
	int		flag;

	flag = 0;
	buf = malloc(sizeof(char) * 17);
	if (!buf)
		return (NULL);
	buf[16] = '\0';
	check_input(str, buf, &flag);
	if (flag)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
