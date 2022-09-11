/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:33:23 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/01 20:36:02 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_type
{
	LOWER,
	UPPER,
	NUM,
	DELIMIT,
}	t_type;

t_type	ft_whatis(char c);

char	*ft_strcapitalize(char *str)
{
	char	*tmp;
	int		word;
	t_type	type;

	word = 0;
	tmp = str - 1;
	while (*++tmp)
	{
		type = ft_whatis (*tmp);
		if (word)
		{
			if (type == UPPER)
				*tmp += 32;
			else if (type == DELIMIT)
				word = 0;
		}
		else if (type != DELIMIT)
		{
			word = 1;
			if (type == LOWER)
				*tmp -= 32;
		}
	}
	return (str);
}

t_type	ft_whatis(char c)
{
	if ('a' <= c && c <= 'z')
		return (LOWER);
	else if ('A' <= c && c <= 'Z')
		return (UPPER);
	else if ('0' <= c && c <= '9')
		return (NUM);
	else
		return (DELIMIT);
}
