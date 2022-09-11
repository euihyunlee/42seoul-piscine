/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:33:45 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/05 22:54:28 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	while (*++argv)
	{
		while (**argv)
			write(1, (*argv)++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
