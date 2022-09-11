/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:31:46 by euihlee           #+#    #+#             */
/*   Updated: 2022/08/28 14:34:28 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		first;
	int		second;
	char	arr[5];

	arr[2] = ' ';
	first = -1;
	while (++first < 99)
	{
		arr[0] = first / 10 + '0';
		arr[1] = first % 10 + '0';
		second = first;
		while (++second < 100)
		{
			arr[3] = second / 10 + '0';
			arr[4] = second % 10 + '0';
			write(1, arr, 5);
			if (!(first == 98 && second == 99))
				write (1, ", ", 2);
		}
	}
}
