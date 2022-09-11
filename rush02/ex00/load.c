/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:29:42 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/11 18:11:56 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	load(char *dict, t_node **list)
{
	int	fd1;
	int	fd2;

	fd1 = open(dict, O_RDONLY);
	fd2 = open(dict, O_RDONLY);
	if (!parse_dict(fd1, fd2, list))
	{
		write(1, "Dict Error\n", 11);
		close(fd1);
		close(fd2);
		unload(list);
		return (ERROR);
	}
	close(fd1);
	close(fd2);
	return (SUCCESS);
}

int	load_entry(char *key, char *val, t_node **list)
{
	t_node			*entry;

	entry = malloc(sizeof (t_node));
	if (entry == NULL)
		return (ERROR);
	entry->key = key;
	entry->val = val;
	entry->next = NULL;
	if (*list != NULL)
		entry->next = *list;
	*list = entry;
	return (SUCCESS);
}

void	unload(t_node **list)
{
	t_node	*tmp;

	while (*list != NULL)
	{
		tmp = (*list)->next;
		free((*list)->key);
		free((*list)->val);
		free(*list);
		*list = tmp;
	}
	return ;
}

/*
char	*lookup(char *key, t_node **tab)
{
	t_node	*tmp;

	tmp = tab[hash(key)];
	while (tmp != NULL)
	{
		if (ft_strcmp(key, tmp->key) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
}
*/
