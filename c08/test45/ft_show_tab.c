/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:25:22 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 13:48:13 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"

int		ft_strlen2(char *str);
char	*ft_itoa(int nbr);

void	ft_show_tab(struct s_stock_str *par)
{
	char	*size;

	while (par->str != 0)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		size = ft_itoa(par->size);
		if (size == NULL)
			return ;
		write(1, size, ft_strlen2(size));
		free(size);
		write(1, "\n", 1);
		write(1, par->copy, ft_strlen2(par->copy));
		write(1, "\n", 1);
		par++;
	}
}

int	ft_strlen2(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_itoa(int nbr)
{
	static char	*to;
	static char	*tmp;
	static int	len;

	len++;
	if (nbr < 10)
	{
		to = malloc(len + 1);
		if (to == NULL)
			return (NULL);
		tmp = to;
		tmp[len] = '\0';
		*tmp++ = '0' + nbr;
	}
	else if (ft_itoa(nbr / 10))
		*tmp++ = '0' + (nbr % 10);
	return (to);
}
