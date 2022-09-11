/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:36 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/03 19:18:26 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lookfor(char *s1, char *s2, unsigned int n);

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	len;

	len = 0;
	while (to_find[len])
		len++;
	if (len == 0)
		return (str);
	while (*str)
	{
		if (ft_lookfor(to_find, str, len) == 0)
			return (str);
		str++;
	}
	return (0);
}

int	ft_lookfor(char *s1, char *s2, unsigned int n)
{
	unsigned char	*needle;
	unsigned char	*haystack;

	needle = (unsigned char *) s1;
	haystack = (unsigned char *) s2;
	while (n-- > 0 && *needle == *haystack)
	{
		if (n == 0)
			return (0);
		needle++;
		haystack++;
	}
	return (*needle - *haystack);
}
