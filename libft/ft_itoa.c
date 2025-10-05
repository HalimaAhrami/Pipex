/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:04:13 by h-el-ahr          #+#    #+#             */
/*   Updated: 2024/11/14 14:03:26 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnbr(int n)
{
	int		c;
	long	nb;

	c = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		c++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*p;
	long	nb;
	int		i;

	nb = n;
	i = ft_cnbr(nb);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	p[i--] = '\0';
	if (n < 0)
	{
		nb = -nb;
		p[0] = '-';
	}
	while (nb > 0 && i >= 0)
	{
		p[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n == 0)
		p[0] = '0';
	return (p);
}
