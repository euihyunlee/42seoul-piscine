/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:05:13 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/07 12:26:03 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
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
		if (nb < m * m)
			r = m - 1;
		else if (nb > m * m)
			l = m + 1;
		else
			return (m);
	}
	return (0);
}
