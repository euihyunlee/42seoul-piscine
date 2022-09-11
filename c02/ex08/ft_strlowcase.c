/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:30:16 by euihlee           #+#    #+#             */
/*   Updated: 2022/08/31 15:31:42 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*tmp;

	tmp = str - 1;
	while (*++tmp)
	{
		if ('A' <= *tmp && *tmp <= 'Z')
			*tmp += 32;
	}
	return (str);
}