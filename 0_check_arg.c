/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:13:03 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/28 01:53:25 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_error(t_info *info, char *str)
{
	perror(str);
	if (info != NULL)
		free_info(info);
	exit (1);
}

void	file_error(char *argv)
{
	int	i;
	(void)argv;

	i = 0;
	while (strerror(errno)[i] != '\0')
		i++;
	write (2, "Error: ", 7);
	write (2, strerror(errno), i);
	write (2, "\n", 1);
	exit (1);
}

int	check_fd(t_info *info)
{
	info->fd_infile = open(info->argv[1], O_RDONLY);
	if (info->fd_infile < 0)
		print_error(info, info->argv[1]);
	info->fd_outfile = open(info->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->fd_outfile < 0)
		print_error(info, info->argv[4]);
	else
		return (1);
}
