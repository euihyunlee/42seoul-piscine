/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:10:14 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/13 10:29:08 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ABS(-42));
	printf("%d\n", ABS(42));
	printf("%d\n", ABS(98 * 124 + 38));
	printf("%d\n", ABS(102 - 1987));
	printf("%d\n", ABS(-1 * 8712));
}
