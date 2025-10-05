/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:35:59 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/04 14:05:10 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_exit(int s)
{
	if (WIFEXITED(s))
		return (WEXITSTATUS(s));
	else if (WIFSIGNALED(s))
		return (128 + WTERMSIG(s));
	else
		return (1);
}

static void	ft_execut(char *cmd, char **env)
{
	char	**cmd_;
	char	*path;
	int		flag;

	flag = 0;
	cmd_ = ft_split(cmd, ' ');
	if (!cmd_)
		exit((1));
	path = ft_get_path(cmd_[0], env, &flag);
	if (path == NULL)
	{
		if (flag)
			exit((ft_putstr_fd("pipex: ", 2), ft_putstr_fd(cmd_[0], 2),
					ft_putstr_fd(": No such file or directory\n", 2),
					ft_free(cmd_), 127));
		else
			exit ((ft_free(cmd_), 1));
	}
	else if (access(path, F_OK) == 0)
		ft_is_acss(path, cmd_, env);
	else
		exit((ft_putstr_fd("pipex: ", 2), ft_putstr_fd(cmd_[0], 2),
				ft_putstr_fd(": command not found :\n", 2),
				ft_free(cmd_), 127));
}

static void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit((ft_putstr_fd("pipex: ", 2), ft_putstr_fd(av[1], 2),
				ft_putstr_fd(": No such file or directory\n", 2), 1));
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	ft_execut(av[2], env);
}

static void	child2(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		exit((ft_putstr_fd("pipex: ", 2), ft_putstr_fd(av[4], 2),
				ft_putstr_fd(": No such file or directory\n", 2), 1));
	}
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	ft_execut(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	pid_t	pid2;
	int		s;

	if (ac != 5)
		exit((write(2, "./pipex infile cmd cmd outfile\n", 32), 1));
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(av, p_fd, env);
	pid2 = fork();
	if (pid2 == -1)
		exit(-1);
	if (pid2 == 0)
		child2(av, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, &s, 0);
	exit(ft_exit(s));
}
