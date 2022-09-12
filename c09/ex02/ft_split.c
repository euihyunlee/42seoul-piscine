/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:00:05 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/10 21:26:50 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset);
char	*get_substr(char *str, int len);

char	**ft_split(char *str, char *charset)
{
	static char	**arr;
	static int	count;
	int			len;

	while (is_sep(*str, charset))
		str++;
	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	if (len == 0)
	{
		arr = malloc(sizeof (char *) * (count + 1));
		if (arr != NULL)
			arr[count] = NULL;
		return (arr);
	}
	count++;
	if (ft_split(str + len, charset))
		arr[--count] = get_substr(str, len);
	return (arr);
}

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset++ == c)
			return (1);
	}
	return (0);
}

char	*get_substr(char *str, int len)
{
	char	*substr;

	substr = malloc(len + 1);
	if (substr == NULL)
		return (0);
	substr[len] = '\0';
	while (--len >= 0)
		substr[len] = str[len];
	return (substr);
}
