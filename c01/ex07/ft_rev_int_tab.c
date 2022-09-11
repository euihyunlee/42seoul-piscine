/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:35:52 by euihlee           #+#    #+#             */
/*   Updated: 2022/08/29 15:51:34 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int left, int right)
{
	int	tmp;

	tmp = tab[left];
	tab[left] = tab[right];
	tab[right] = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	left;
	int	right;

	left = -1;
	right = size;
	while (++left < --right)
		swap (tab, left, right);
}
