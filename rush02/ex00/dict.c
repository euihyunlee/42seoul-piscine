/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 08:16:52 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/11 23:05:30 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_dict(int fd1, int fd2, t_node **list)
{
	char	c;
	char	*key;
	char	*val;

	while (read(fd1, &c, 1) == 1)
	{
		if (!('0' <= c && c <= '9'))
			return (ERROR);
		key = read_key(fd1, fd2, &c);
		if (key == NULL || !skip_to_val(fd1, fd2, &c))
			return (ERROR);
		if (!(' ' < c && c <= '~'))
			return (ERROR);
		val = read_val(fd1, fd2, &c);
		if (val == NULL)
			return (ERROR);
		load_entry(key, val, list);
	}
	return (SUCCESS);
}

char	*read_key(int fd1, int fd2, char *c)
{
	char	*key;
	int		keylen;

	keylen = 0;
	while ('0' <= *c && *c <= '9')
	{
		keylen++;
		if (read(fd1, c, 1) != 1)
			return (NULL);
	}
	if (*c == ' ' || *c == ':')
	{
		key = malloc(keylen + 1);
		if (key != NULL)
		{
			key[keylen] = '\0';
			read(fd2, key, keylen);
		}
		return (key);
	}
	else
		return (NULL);
}

int	skip_to_val(int fd1, int fd2, char *c)
{
	int		skiplen;
	int		i;
	char	*buf;

	skiplen = 1;
	i = 0;
	while (i < 2)
	{
		while (*c == ' ')
		{
			skiplen++;
			if (read(fd1, c, 1) != 1)
				return (ERROR);
		}
		if (i == 0 && (*c != ':' || read(fd1, c, 1) != 1))
			return (ERROR);
		i++;
	}
	buf = malloc(skiplen);
	read(fd2, buf, skiplen);
	free(buf);
	return (SUCCESS);
}

char	*read_val(int fd1, int fd2, char *c)
{
	char	*val;
	int		vallen;
	char	d;

	vallen = 0;
	while (' ' <= *c && *c <= '~')
	{
		vallen++;
		if (read(fd1, c, 1) != 1)
			return (NULL);
	}
	if (*c == '\n')
	{
		val = malloc(vallen + 1);
		if (val != NULL)
		{
			val[vallen] = '\0';
			read(fd2, val, vallen);
			read(fd2, &d, 1);
			trim_space(val, 1);
		}
		return (val);
	}
	else
		return (NULL);
}

void	trim_space(char *str, int is_space)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = str;
	tmp2 = str;
	while (*tmp1)
	{
		if (is_space)
		{
			if (*tmp1 == ' ')
			{
				tmp1++;
				continue ;
			}
			else
				is_space = 0;
		}
		else if (*tmp1 == ' ')
			is_space = 1;
		*tmp2++ = *tmp1++;
	}
	*tmp2 = '\0';
	if (*--tmp2 == ' ')
		*tmp2 = '\0';
}
