/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:33:48 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/05 17:40:12 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	val;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	val = nb;
	while (--power)
		val *= nb;
	return (val);
}
