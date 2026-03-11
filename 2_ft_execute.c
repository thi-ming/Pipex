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
	if (pipe(info->p_fd) == -1)
		print_error(info, "Pipe: ", errno);
	return (info);
}	

int	ft_waitpid(t_info *info)
{
	pid_t	w;
	int		status;
	int		count;

	count = 0;
	while (count < 2)
	{
		w = waitpid(-1, &status, 0);
		if (w == -1)
			print_error(info, "Waitpid: ", errno);
		if (w == info->pid2)
		{
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
			{
				write(2, "Child killed by signal: ", 24);
				ft_putnbr(WTERMSIG(status));
				write(2, "\n", 1);
				return (128 + WTERMSIG(status));
			}
		}
		count++;
	}
	return (0);
}

void	ft_fork1(t_info *info)
{
	info->pid1 = fork();
	if (info->pid1 < 0)
		print_error(info, "Fork: ", errno);
	if (info->pid1 == 0)
	{
		dup2(info->fd_infile, 0);
		dup2(info->p_fd[1], 1);
		close_fd(info);
		ft_execve(info, info->cmd1);
	}
	return ;
}

int	ft_fork2(t_info *info, int code)
{
	info->pid2 = fork();
	if (info->pid2 < 0)
		print_error(info, "Fork: ", errno);
	if (info->pid2 == 0)
	{
		dup2(info->p_fd[0], 0);
		dup2(info->fd_outfile, 1);
		close_fd(info);
		ft_execve(info, info->cmd2);
	}
	if (info->pid2 > 0)
	{
		close_fd(info);
		code = ft_waitpid(info);
	}
	return (code);
}
