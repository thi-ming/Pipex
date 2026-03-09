/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_fd_cmd_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:15:53 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/07 18:40:06 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_info	*check_fd(t_info *info)
{
	info->fd_infile = open(info->argv[1], O_RDONLY);
	if (info->fd_infile < 0)
	{
		perror(info->argv[1]);
		info->fd_infile = open("/dev/null", O_RDONLY);
	}
	info->fd_outfile = open(info->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->fd_outfile < 0)
		print_error(info, info->argv[4], errno);
	return (info);
}

char	**split_cmd(char **cmd_args, char *argv, t_info *info)
{
	int	i;

	i = count_num(argv, is_space);
	if (i == 0)
		print_error(info, "Command line empty", 2);
	cmd_args = malloc(sizeof(char *) * (i + 1));
	if (cmd_args == NULL)
		print_error(info, "Malloc: ", errno);
	cmd_args[i] = NULL;
	i = 0;
	while (*argv != '\0')
	{
		while (is_space(*argv))
			argv++;
		cmd_args[i] = malloc(sizeof(char) * (ft_strlen(argv, is_space) + 1));
		if (cmd_args[i] == NULL)
			print_error(info, "Malloc: ", errno);
		cmd_args[i] = ft_strcpy(cmd_args[i], argv, ' ');
		argv = argv + ft_strlen(argv, is_space);
		i++;
	}
	return (cmd_args);
}

int	ft_strcmp(char *dst, char *src, int num)
{
	int	i;

	i = 0;
	while (i < num && dst[i] == src[i])
		i++;
	if (i == num)
		return (1);
	return (0);
}

char	*find_path(char *path, t_info *info)
{
	int	i;

	i = 0;
	while (info->envp[i] != NULL)
	{
		if (ft_strcmp(info->envp[i], "PATH=", 5))
		{
			path = info->envp[i];
			return (path + 5);
		}
		i++;
	}
	return (NULL);
}

t_info	*split_envp(t_info *info)
{
	char	*path;
	int		i;

	path = NULL;
	path = find_path(path, info);
	if (path == NULL)
		return (info->path = NULL, info);
	info->path = malloc(sizeof(char *) * (count_num(path, is_colon) + 1));
	if (info->path == NULL)
		print_error(info, "Malloc: ", errno);
	info->path[count_num(path, is_colon)] = NULL;
	i = 0;
	while (*path != '\0')
	{
		while (is_colon(*path))
			path++;
		info->path[i] = malloc(ft_strlen(path, is_colon) + 1);
		if (info->path[i] == NULL)
			print_error(info, "Malloc: ", errno);
		info->path[i] = ft_strcpy(info->path[i], path, ':');
		path = path + ft_strlen(path, is_colon);
		i++;
	}	
	return (info);
}
