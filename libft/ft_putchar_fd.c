/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:00:45 by h-el-ahr          #+#    #+#             */
/*   Updated: 2024/10/27 10:42:44 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int 	fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	write(fd,"Hello",5);
	sleep(30);
	//ft_putchar_fd(fd+48,1);
}*/
