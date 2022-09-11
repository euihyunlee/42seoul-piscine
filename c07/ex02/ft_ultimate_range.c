/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:32:42 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/11 19:50:30 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	int			*arr;
	int			i;

	if (range == NULL)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = malloc(sizeof (int) * size);
	if (arr == NULL)
		return (-1);
	i = -1;
	while (++i < size)
		arr[i] = min + i;
	*range = arr;
	return (size);
}
