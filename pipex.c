/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:29:17 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/07 18:46:12 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_info	*make_info(t_info *info, int argc, char **argv, char **envp)
{
	if (argc != 5)
		exit (EXIT_FAILURE);
	info = malloc(sizeof(t_info));
	if (info == NULL)
		print_error(info, "Malloc: ");
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	info = check_fd(info);
	info->cmd1 = split_cmd(info->cmd1, info->argv[2], info);
	info->cmd2 = split_cmd(info->cmd2, info->argv[3], into);
	info = split_envp(info);
	return (info);
}

void	ft_piping(t_info *info)
{
	info = ft_pipe(info);
	info->pid1 = ft_fork(info, info->pid1);
	info->pid2 = ft_fork(info, info->pid2);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	info = NULL;
	info = make_info(info, argc, argv, envp);
	ft_piping(info);
	return (0);
}
