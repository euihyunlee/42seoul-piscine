/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:01:17 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/02 21:26:06 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (nb-- > 0 && *src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
