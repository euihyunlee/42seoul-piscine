/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:37:05 by euihlee           #+#    #+#             */
/*   Updated: 2022/08/31 21:48:21 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
