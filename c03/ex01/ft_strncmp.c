/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:28:15 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/03 18:42:01 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	if (n == 0)
		return (0);
	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	while (n-- > 0 && *t1 == *t2)
	{
		if (n == 0 || *t1 == '\0')
			return (0);
		t1++;
		t2++;
	}
	return (*t1 - *t2);
}
