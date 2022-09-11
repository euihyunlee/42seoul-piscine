/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:43:01 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/05 22:52:54 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	swap_params(char **argv, int a, int b);
void	print_params(char **argv);

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	min;

	if (argc == 1)
		return (1);
	i = 0;
	while (++i < argc - 1)
	{
		min = i;
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[min], argv[j]) > 0)
				min = j;
		}
		if (min != i)
			swap_params(argv, i, min);
	}
	print_params(argv);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	while (*t1 == *t2)
	{
		if (*t1 == '\0')
			return (0);
		t1++;
		t2++;
	}
	return (*t1 - *t2);
}

void	swap_params(char **argv, int a, int b)
{
	char	*tmp;

	tmp = argv[a];
	argv[a] = argv[b];
	argv[b] = tmp;
}

void	print_params(char **argv)
{
	while (*++argv)
	{
		while (**argv)
			write(1, (*argv)++, 1);
		write(1, "\n", 1);
	}
}
