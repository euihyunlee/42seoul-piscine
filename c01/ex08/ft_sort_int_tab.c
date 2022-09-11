/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:01:38 by euihlee           #+#    #+#             */
/*   Updated: 2022/08/29 16:00:53 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int left, int right)
{
	int	tmp;

	tmp = tab[left];
	tab[left] = tab[right];
	tab[right] = tmp;
}

void	qsort(int *tab, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = tab[(left + right) / 2];
	i = left - 1;
	j = right + 1;
	while (1)
	{
		while (tab[++i] < pivot)
			;
		while (tab[--j] > pivot)
			;
		if (j <= i)
			break ;
		swap(tab, i, j);
	}
	qsort(tab, left, j);
	qsort(tab, j + 1, right);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	left;
	int	right;

	left = 0;
	right = size - 1;
	qsort(tab, left, right);
}
