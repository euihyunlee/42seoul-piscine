/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:01 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/07 14:12:17 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);
int	ft_isqrt(int nb);

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (!ft_is_prime(nb))
	{
		if (nb % 2 == 0)
			nb++;
		else
			nb += 2;
	}
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	iroot;

	if (nb < 2 || (nb % 2 == 0 && nb != 2))
		return (0);
	iroot = ft_isqrt(nb);
	i = 3;
	while (i <= iroot)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_isqrt(int nb)
{
	int			l;
	int			r;
	long long	m;

	if (nb < 0)
		return (0);
	l = 0;
	r = nb;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (m * m < nb)
			l = m + 1;
		else
			r = m - 1;
	}
	return (l);
}
