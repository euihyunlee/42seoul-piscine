/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:14:01 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/04 19:54:18 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c);

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = 0;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			break ;
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
