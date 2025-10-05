/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:54:52 by h-el-ahr          #+#    #+#             */
/*   Updated: 2024/11/09 09:47:08 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cword(char const *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			w++;
		while (str[i] != c && str[i])
			i++;
	}
	return (w);
}

char	**ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**p;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (1 + ft_cword(s, c)));
	if (!p)
		return (NULL);
	while (s[i] && k < ft_cword(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		p[k] = ft_substr(s, j, i - j);
		if (p[k++] == NULL)
			return (ft_free(p));
	}
	p[k] = NULL;
	return (p);
}
