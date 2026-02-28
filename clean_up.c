/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:19:26 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/28 07:42:25 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_cmd(char **cmd)
{
	int	i;

	if (cmd == NULL)
		return ;
	i = 0;
	while (cmd[i] != '\0')
	{
		free (cmd[i]);
		i++;
	}
	free (cmd);
	cmd = NULL;
	return ;
}

void	free_info(t_info *info)
{
	close (info->fd_infile);
	close (info->fd_outfile);
	close (info->p_fd[0]);
	close (info->p_fd[1]);
	free_cmd(info->cmd1);
	free_cmd(info->cmd2);
	free (info);
}
