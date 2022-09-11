/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:01:45 by euihlee           #+#    #+#             */
/*   Updated: 2022/08/28 17:04:48 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_digits(int n, char *arr, int digit, int depth)
{
	int	max;

	if (depth == n)
	{
		write(1, arr, n);
		if (*arr <= '9' - n)
			write(1, ", ", 2);
		return ;
	}
	max = 10 - n + depth;
	while (++digit <= max)
	{
		arr[depth] = digit + '0';
		fill_digits(n, arr, digit, depth + 1);
	}
}

void	ft_print_combn(int n)
{
	char	arr[9];
	int		digit;
	int		depth;

	digit = -1;
	depth = 0;
	fill_digits(n, arr, digit, depth);
}
