/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:26:44 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/05 22:51:03 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 1)
		return (1);
	while (*argv[0])
		write(1, argv[0]++, 1);
	write(1, "\n", 1);
	return (0);
}
