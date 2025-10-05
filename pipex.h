/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:36:04 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/04 10:56:47 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

char	*ft_get_path(char *cmd, char **env, int *flag);
void	ft_is_acss(char *path, char **cmd_, char **env);

#endif