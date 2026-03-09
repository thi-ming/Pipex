/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_clean_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:19:26 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/07 18:19:23 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_array(char **cmd)
{
	int	i;

	if (cmd == NULL)
		return ;
	i = 0;
	while (cmd[i] != NULL)
	{
		free (cmd[i]);
		i++;
	}
	free (cmd);
	return ;
}

void	close_fd(t_info *info)
{
	if (info->fd_infile > 2)
		close (info->fd_infile);
	if (info->fd_outfile > 2)
		close (info->fd_outfile);
	if (info->p_fd[0] > 2)
		close (info->p_fd[0]);
	if (info->p_fd[1] > 2)
		close (info->p_fd[1]);
	return ;
}

void	free_info(t_info *info)
{
	close_fd(info);
	free_array(info->cmd1);
	free_array(info->cmd2);
	free_array(info->path);
	free (info);
}

void	ft_print_str(char *str)
{
	while (*str != '\0')
	{
		write (2, str, 1);
		str++;
	}
	write (2, "\n", 1);
	return ;
}

void	print_error(t_info *info, char *str, int code)
{
	if (code == 127)
	{
		write(2, "Command not found: ", 19);
		ft_print_str(str);
	}
	if (code == 126)
	{
		write(2, "Command not executable: ", 24);
		ft_print_str(str);
	}
	if (info != NULL)
		free_info(info);
	if (code == -1)
	{
		ft_print_str(str);
		exit (EXIT_FAILURE);
	}
	if (code == errno)
	{
		perror(str);
		exit (EXIT_FAILURE);
	}
	exit (code);
}
