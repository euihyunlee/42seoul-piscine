/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:53:20 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/10 12:54:13 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_digit(char c, char *base);

int	is_valid(char *base)
{
	int		n;
	int		i;

	n = 0;
	while (base[n])
	{
		if (base[n] == '+' || base[n] == '-'
			|| base[n] == ' ' || ('\t' <= base[n] && base[n] <= '\r'))
			return (0);
		i = n;
		while (--i >= 0)
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

int	atoi_base(char *str, char *base, int radix)
{
	int		sign;
	int		num;
	int		digit;

	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = 0;
	while (*str)
	{
		digit = get_digit(*str, base);
		if (digit < 0)
			break ;
		num = num * radix + digit;
		str++;
	}
	return (sign * num);
}

int	get_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*putnbr_base(long long nbr, char *base, int radix, int neg)
{
	static char	*to;
	static char	*tmp;
	static int	len;

	len++;
	if (nbr < 0)
	{
		nbr *= -1;
		neg = 1;
		len++;
	}
	if (nbr < radix)
	{
		to = malloc(len + 1);
		if (to == NULL)
			return (NULL);
		tmp = to;
		tmp[len] = '\0';
		if (neg)
			*tmp++ = '-';
		*tmp++ = base[nbr];
	}
	else if (putnbr_base(nbr / radix, base, radix, neg))
		*tmp++ = base[nbr % radix];
	return (to);
}
