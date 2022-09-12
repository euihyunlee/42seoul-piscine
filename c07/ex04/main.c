/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:31:34 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 14:35:16 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 4)
	{
		printf("usage: ./a.out nbr base_from base_to\n");
		return (1);
	}
	str = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s\n", str);
	free(str);
	system("leaks a.out");
}
