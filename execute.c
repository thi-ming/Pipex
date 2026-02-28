/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:59:28 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/28 07:01:16 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_info	*ft_pipe(t_info *info)
{
	if (!pipe(info->p_fd))
	{
		perror("Pipe: ");
		free_info(info);
		exit (1);
	}
	return (info);
}	

pid_t	ft_fork(t_info *info, pid_t pid)
{
	pid = fork();
	if (pid < 0)
	{
		perror("Fork: ");
		free_info(info);
		exit (1);
	}
	return (pid);
}




void	execute(t_info *info)
{
	pipe(info->p_fd);

void	execute(t_info *info)
{
	fork();
	dup2(info->fd_infile, 0);
	execve(info->argv[2]);
	pipe(1);
	dup2(1, 0);
	execve(info->argv[3]);
	dup2(1, info->fd_outfile);
}
