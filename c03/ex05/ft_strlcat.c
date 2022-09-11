/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:55:03 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/02 22:21:07 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlen;
	unsigned int	srclen;
	char			*end;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0 || destlen > size)
		return (size + srclen);
	end = dest + size - 1;
	while (*dest)
		dest++;
	while (dest < end && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (destlen + srclen);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
