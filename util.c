/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:00:12 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/04 12:00:17 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_get_env(char **env)
{
	int		i;
	char	**p;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			p = ft_split(env[i] + 5, ':');
			if (!p)
				return (NULL);
			return (p);
		}
		i++;
	}
	return (NULL);
}

void	ft_is_acss(char *path, char **cmd_, char **env)
{
	if (access(path, X_OK) == 0)
	{
		if (execve(path, cmd_, env) == -1)
			exit((ft_putstr_fd("pipex: fail execution ", 2),
					free(path), ft_free(cmd_), 1));
	}
	else
		exit((ft_putstr_fd("pipex: Permission denied", 2),
				free(path), ft_free(cmd_), 126));
}

static char	*ft_cmd_path(char **p, char *cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	while (p[i])
	{
		tmp = ft_strjoin(p[i], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin(tmp, cmd);
		if (!cmd_path)
			return (NULL);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
			return ((ft_free(p), cmd_path));
		free(cmd_path);
		i++;
	}
	return ((ft_free(p), cmd));
}

char	*ft_get_path(char *cmd, char **env, int *flag)
{
	char	**p;

	p = ft_get_env(env);
	if (!p || !*p)
	{
		if (p)
			free (p);
		if (*cmd == '/')
		{
			if (access(cmd, F_OK) == 0)
			{
				if (access(cmd, X_OK) == 0)
					return (cmd);
				else
					return ((*flag = 1, NULL));
			}
			else
				return ((*flag = 1, NULL));
		}
		if (*cmd != '/')
			return ((*flag = 1, NULL));
		return (NULL);
	}
	else
		return (ft_cmd_path(p, cmd));
}
