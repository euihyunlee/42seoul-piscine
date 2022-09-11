/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:08:37 by jpark2            #+#    #+#             */
/*   Updated: 2022/09/11 22:24:15 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	find_key_in_list(char *key, char *value, t_node *list)
{
	int		idx;

	idx = 0;
	while (list != 0)
	{
		if (ft_strcmp(list->key, key) == 0)
		{
			if (value != 0)
				list->val = ft_strcpy(list->val, value);
			return (idx);
		}
		idx++;
		list = list->next;
	}
	return (-1);
}

void	print_value_in_list(t_node *list, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		list = list->next;
		i++;
	}
	ft_putstr(list->val);
}
