/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:08:24 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/11 19:50:17 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*arr;
	long long	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = malloc(sizeof (int) * size);
	if (arr == NULL)
		return (NULL);
	while (--size >= 0)
		arr[size] = min + size;
	return (arr);
}
