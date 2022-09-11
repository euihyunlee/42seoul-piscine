/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:38:46 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/04 21:09:45 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_base(char *base);
void	write_digits_base(long n, int base_dec, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	long	lnbr;
	int		base_dec;

	base_dec = get_base(base);
	if (!base_dec)
		return ;
	lnbr = (long) nbr;
	if (lnbr < 0)
	{
		write(1, "-", 1);
		lnbr *= -1;
	}
	write_digits_base(lnbr, base_dec, base);
}

int	get_base(char *base)
{
	int	n;
	int	i;

	n = 0;
	while (base[n])
	{
		if (base[n] == '+' || base[n] == '-')
			return (0);
		i = n;
		while (--i > 0)
		{
			if (base[n] == base[i])
				return (0);
		}
		n++;
	}
	if (n < 2)
		return (0);
	return (n);
}

void	write_digits_base(long n, int base_dec, char *base)
{
	if (n < base_dec)
	{
		write(1, base + n, 1);
		return ;
	}
	write_digits_base(n / base_dec, base_dec, base);
	write(1, base + (n % base_dec), 1);
}
