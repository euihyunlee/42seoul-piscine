/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:56:28 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/01 11:36:32 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	srcsize;
	unsigned int	i;

	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && i < srcsize)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}
