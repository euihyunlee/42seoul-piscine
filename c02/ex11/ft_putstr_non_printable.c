/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:16:36 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/01 10:33:42 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hex(char c);

void	ft_putstr_non_printable(char *str)
{
	char			hex[3];
	char			*tmp;
	unsigned char	c;

	hex[0] = '\\';
	tmp = str - 1;
	while (*++tmp)
	{
		c = (unsigned char) *tmp;
		if (c < ' ' || '~' < c)
		{
			hex[1] = "0123456789abcdef"[c / 0x10];
			hex[2] = "0123456789abcdef"[c % 0x10];
			write (1, hex, 3);
		}
		else
			write(1, tmp, 1);
	}
}
