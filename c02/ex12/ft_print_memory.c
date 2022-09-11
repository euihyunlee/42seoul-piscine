/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:06:54 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/01 17:06:57 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long addr);
void	print_str(char *addr, unsigned int diff);
char	*print_hex(char *hex, char *tmp, unsigned char c);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	void			*tmp;

	i = 0;
	while (i < size)
	{
		tmp = addr + i;
		print_addr((unsigned long) tmp);
		print_str((char *) tmp, size - i);
		write(1, "\n", 1);
		i += 0x10;
	}
	return (addr);
}

void	print_addr(unsigned long addr)
{
	char	buf[16];
	int		place;

	place = 16;
	while (--place >= 0)
	{
		buf[place] = "0123456789abcdef"[addr % 0x10];
		addr /= 0x10;
	}
	write(1, buf, 16);
	write(1, ":", 1);
}

void	print_str(char *addr, unsigned int diff)
{
	char			*tmp;
	char			hex[40];
	char			str[16];
	unsigned int	i;
	unsigned char	c;

	tmp = hex;
	i = 0;
	while (i < diff && i < 16)
	{
		c = (unsigned char) addr[i];
		tmp = print_hex(hex, tmp, c);
		if (c < ' ' || '~' < c)
			str[i] = '.';
		else
			str[i] = c;
		i++;
	}
	while (tmp < hex + 40)
		*tmp++ = ' ';
	write(1, hex, 40);
	write(1, " ", 1);
	write(1, str, i);
}

char	*print_hex(char *hex, char *tmp, unsigned char c)
{
	if ((tmp - hex) % 5 == 0)
		*tmp++ = ' ';
	*tmp++ = "0123456789abcdef"[c / 16];
	*tmp++ = "0123456789abcdef"[c % 16];
	return (tmp);
}
