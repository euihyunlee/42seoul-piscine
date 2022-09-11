/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:08:15 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/10 00:04:51 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_len(int size, char **strs, char *sep);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	char	*tmp;
	int		i;

	if (size == 0)
	{
		joined = malloc(1);
		if (joined != NULL)
			*joined = '\0';
		return (joined);
	}
	joined = malloc(get_len(size, strs, sep));
	if (joined == NULL)
		return (0);
	tmp = joined;
	i = -1;
	while (++i < size)
	{
		tmp = ft_strcpy(tmp, strs[i]);
		if (i != size - 1)
			tmp = ft_strcpy(tmp, sep);
	}
	*tmp = '\0';
	return (joined);
}

int	get_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (++i < size)
		len += ft_strlen(strs[i]);
	len += ft_strlen(sep) * (size - 1);
	return (len + 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}
