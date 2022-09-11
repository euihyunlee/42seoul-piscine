/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_seperate2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:12:41 by jpark2            #+#    #+#             */
/*   Updated: 2022/09/11 22:54:57 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_big_unit_count(int len, char *str)
{
	int	sm_u;
	int	idx;
	int	count;

	sm_u = (len - 1) % 3;
	idx = 0;
	count = 0;
	if ((len - 1) / 3 > 0)
		count++;
	while (++idx < len)
	{
		if (sm_u == 2 && str[idx] != '0')
			count++;
		if (--sm_u < 0)
			sm_u = 2;
	}
	return (count);
}

int	word_count(int len, char *str)
{
	int	sm_u;
	int	count;
	int	idx;

	sm_u = (len - 1) % 3;
	idx = -1;
	count = check_big_unit_count(len, str);
	while (++idx < len)
	{
		if (str[idx] != '0')
		{
			count++;
			if (sm_u == 2)
				count++;
			if (sm_u == 1 && str[idx] == '1')
			{
				sm_u--;
				idx++;
			}
		}
		if (--sm_u < 0)
			sm_u = 2;
	}
	return (count);
}

char	*ten_variation(char *n)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * 3);
	if (arr == 0)
		return (0);
	arr[0] = *n;
	arr[1] = *(n + 1);
	arr[2] = '\0';
	return (arr);
}
