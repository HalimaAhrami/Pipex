/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:57:34 by h-el-ahr          #+#    #+#             */
/*   Updated: 2024/11/10 14:33:42 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*sr;
	size_t		i;

	dst = (char *)dest;
	sr = (const char *)src;
	if (n == 0 || dest == src)
		return (dest);
	else if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dst[i] = sr[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
