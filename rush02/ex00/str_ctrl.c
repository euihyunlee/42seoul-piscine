/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:01:10 by jpark2            #+#    #+#             */
/*   Updated: 2022/09/11 22:55:09 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
