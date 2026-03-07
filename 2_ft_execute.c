/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:59:28 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/07 19:57:30 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_info	*ft_pipe(t_info *info)
{
	if (!pipe(info->p_fd))
		print_error(info, "Pipe: ");
	return (info);
}	

void	ft_waitpid(t_info *info)
{
	pid_t	w1;
	int	status;
	pid_t	w2;

	w1 = waitpid(info->pid1, &status, 0);
	if (w1 == -1)
		print_error(info, "Waitpid: ");
	if (WIFEXITED(status))
		if (WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	else
		if (WIFESIGNALED(status))
		{
			write (2, "Child killed by signal: ", 24);
			write (2, WTERMSIG(status),);
			return (128 + WTERMSIG(status));
		}

	w2 = waitpid(info->pid2);
	if (w2 == -1)
		print_error(info, "Waitpid: ");
	return ;
}

void	ft_fork1(t_info *info, pid_t pid)
{
	pid = fork();
	if (pid < 0)
		print_error(info, "Fork: ");
	if (pid == 0)
	{
		dup2(info->fd_infile, 0);
		dup2(info->p_fd[1], 1);
		close (info->fd_outfile);
		close (info->p_fd[0]);
		ft_execve(info, info->cmd1);
		close (info->fd_infile);
		close (info->p_fd[1]);
	}
	return ;
}

void	ft_fork2(t_info *info, pid_t pid)
{
	pid = fork();
	if (pid < 0)
		print_error(info, "Fork: ");
	if (pid == 0)
	{
		dup2(info->p_fd[0], 0);
		dup2(info->fd_outfile, 1);
		close (info->fd_infile);
		close (info->p_fd[1]);
		ft_execve(info, info->cmd2);
		close (info->fd_outfile);
		close (info->p_fd[0]);
	}
	if (pid > 0)
	{
		close_fd(info);
		ft_waitpid(info);
	}
	return ;
}
