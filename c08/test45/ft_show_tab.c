/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:25:22 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/13 20:59:27 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int		ft_strlen2(char *str);
void	ft_putnbr(int nb);

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		write(1, par->copy, ft_strlen2(par->copy));
		write(1, "\n", 1);
		par++;
	}
}

int	ft_strlen2(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb < 10)
	{
		digit = nb + '0';
		write(1, &digit, 1);
		return ;
	}
	ft_putnbr(nb / 10);
	digit = nb % 10 + '0';
	write (1, &digit, 1);
	return ;
}
