/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_seperate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:04:10 by jpark2            #+#    #+#             */
/*   Updated: 2022/09/11 22:44:24 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*make_big_unit_str(int n)
{
	int		idx;
	char	*str;

	if (n < 1)
		return (0);
	str = (char *)malloc(sizeof(char) * (n * 3 + 2));
	if (str == 0)
		return (0);
	str[0] = '1';
	idx = 1;
	while (idx < n * 3 + 1)
		str[idx++] = '0';
	str[idx] = '\0';
	return (str);
}

char	*make_num(char n, int len)
{
	int		idx;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	arr[0] = n;
	idx = 1;
	while (idx < len)
	{
		arr[idx] = '0';
		idx++;
	}
	arr[idx] = '\0';
	return (arr);
}

void	check_big_unit(char **arr, t_ainfo *a_info)
{
	if (--(a_info->sm_u) < 0 && a_info->big_u != 0)
	{
		arr[a_info->idx] = make_big_unit_str(a_info->big_u);
		a_info->idx++;
		a_info->sm_u = 2;
		a_info->big_u--;
	}
}

void	num_to_digit(char **arr, char *str, t_ainfo *a_info)
{
	if (a_info->len == 1 && str[a_info->str_i] == '0')
		arr[a_info->idx] = make_num(str[a_info->str_i], 1);
	if (str[a_info->str_i] != '0')
	{
		if (a_info->sm_u == 2)
		{
			arr[a_info->idx++] = make_num(str[a_info->str_i], 1);
			arr[a_info->idx++] = make_num('1', 3);
		}
		else if (a_info->sm_u == 1)
		{
			if (str[a_info->str_i] == '1')
			{
				arr[a_info->idx++] = ten_variation(&str[a_info->str_i++]);
				check_big_unit(arr, a_info);
			}
			else
				arr[a_info->idx++] = make_num(str[a_info->str_i], 2);
		}
		else
			arr[a_info->idx++] = make_num(str[a_info->str_i], 1);
	}
}

char	**unit_seperate(char *str)
{
	char	**arr;
	t_ainfo	a_info;

	a_info.len = str_len(str);
	if (a_info.len == 1 && str[0] == '0')
		a_info.count = 1;
	else
		a_info.count = word_count(a_info.len, str);
	arr = (char **)malloc(sizeof(char *) * (a_info.count + 1));
	if (arr == 0)
		return (0);
	arr[a_info.count] = 0;
	a_info.big_u = (a_info.len - 1) / 3;
	a_info.sm_u = (a_info.len - 1) % 3;
	a_info.idx = 0;
	a_info.str_i = 0;
	while (a_info.str_i < a_info.len && a_info.idx < a_info.count)
	{
		num_to_digit(arr, str, &a_info);
		check_big_unit(arr, &a_info);
		a_info.str_i++;
	}
	return (arr);
}
