/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:44:48 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/04 21:03:36 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(char *base);
int		is_space(char c);
char	*get_sign(char *str, int *sign);
int		num_in_base(char c, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	base_dec;
	int	sign;
	int	num;
	int	digit;

	base_dec = is_valid(base);
	if (!base_dec)
		return (0);
	while (is_space(*str))
		str++;
	str = get_sign(str, &sign);
	num = 0;
	while (*str)
	{
		digit = num_in_base(*str, base);
		if (digit < 0)
			break ;
		num = num * base_dec + digit;
		str++;
	}
	return (sign * num);
}

int	is_valid(char *base)
{
	int	n;
	int	i;

	n = 0;
	while (base[n])
	{
		if (base[n] == '+' || base[n] == '-' || is_space(base[n]))
			return (0);
		i = n;
		while (--i > 0)
		{
			if (base[n] == base[i])
				return (0);
		}
		n++;
	}
	if (n < 2)
		return (0);
	return (n);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*get_sign(char *str, int *sign)
{
	*sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	num_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}
