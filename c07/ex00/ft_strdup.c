/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:54:15 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/06 19:05:58 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;

	len = 0;
	while (src[len])
		len++;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	while (--len >= 0)
		dest[len] = src[len];
	return (dest);
}
