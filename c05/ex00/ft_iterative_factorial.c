/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:17:46 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/05 17:32:24 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	bang;

	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (1);
	bang = nb;
	while (--nb > 0)
		bang *= nb;
	return (bang);
}
