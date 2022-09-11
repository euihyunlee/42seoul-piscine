/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:25:22 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/11 20:27:40 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		write(1, par->cpy, ft_strlen(par->cpy));
		write(1, "\n", 1);
		par++;
	}
}
