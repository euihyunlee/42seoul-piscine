/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:24:33 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/03 19:43:44 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_digits(long nb)
{
	char	digit;

	if (nb < 1)
		return ;
	write_digits (nb / 10);
	digit = nb % 10 + '0';
	write (1, &digit, 1);
}

void	ft_putnbr(int nb)
{
	long	lnb;

	lnb = (long) nb;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	else if (lnb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	write_digits (lnb);
}
