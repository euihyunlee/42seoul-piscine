/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:27:56 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/10 20:22:42 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(char *base);
int		atoi_base(char *str, char *base, int radix);
char	*putnbr_base(long long nbr, char *base, int radix, int neg);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		inbr;
	int		radix_from;
	int		radix_to;

	radix_from = is_valid(base_from);
	radix_to = is_valid(base_to);
	if (!radix_from || !radix_to)
		return (0);
	inbr = atoi_base(nbr, base_from, radix_from);
	return (putnbr_base((long long) inbr, base_to, radix_to, 0));
}
