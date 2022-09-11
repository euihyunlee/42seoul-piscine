/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:44:31 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/01 10:57:51 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (!src[i])
			break ;
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
