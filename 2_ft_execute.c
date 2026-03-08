/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:59:28 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/08 11:48:20 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr(int num)
{
	char	c;

	if (num < 0)
	{
		write (2, "-", 1);
		num = -num;
	}		
	if (num > 9)
		ft_putnbr(num / 10);
	c = '0' + (num % 10);
	write (2, &c, 1);
	return ;
}

t_info	*ft_pipe(t_info *info)
{
	if (pipe(info->p_fd))
		print_error(info, "Pipe: ");
	return (info);
}	

int	ft_waitpid(t_info *info)
{
	pid_t	w;
	int	status;	

	if (waitpid(info->pid1, NULL, 0) == -1)
		perror("Waitpid the 1st child process: ");
	w = waitpid(info->pid2, &status, 0);
	if (w == -1)
		print_error(info, "Waitpid the 2nd child process: ");
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		write (2, "Child killed by signal: ", 24);
		ft_putnbr(WTERMSIG(status));
		return (128 + WTERMSIG(status));
	}
	return (0);
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

int	ft_fork2(t_info *info, pid_t pid, int code)
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
		code = ft_waitpid(info);
	}
	return (code);
}
