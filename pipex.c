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
		print_error(info, "Malloc: ", errno);
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	info->fd_infile = -1;
	info->fd_outfile = -1;
	info->p_fd[0] = -1;
	info->p_fd[1] = -1;
	info->cmd1 = NULL;
	info->cmd2 = NULL;
	info->path = NULL;
	info = check_fd(info);
	info->cmd1 = split_cmd(info->cmd1, info->argv[2], info);
	info->cmd2 = split_cmd(info->cmd2, info->argv[3], info);
	info = split_envp(info);
	return (info);
}

int	ft_piping(t_info *info, int code)
{
	info = ft_pipe(info);
	ft_fork1(info);
	code = ft_fork2(info, code);
	return (code);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;
	int	code;

	code = 0;
	info = NULL;
	info = make_info(info, argc, argv, envp);
	code = ft_piping(info, code);
	free_info(info);	
	return (code);
}
