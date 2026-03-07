/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:38:43 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/07 18:43:39 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	abs_relav_path(char *cmd, t_info *info)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
		{
			if (!access(cmd, F_OK))
				if (!access(cmd, X_OK))
					return (1);
			print_error(info, cmd);
		}
		i++;
	}
	return (0);
}

char	*ft_strcon(char *res, char *path, char *cmd, t_info *info)
{
	int		len;
	char	*start;

	len = ft_strlen(path, NULL) + ft_strlen(cmd, NULL);
	res = malloc(len + 2);
	if (res == NULL)
		print_error(info, "Malloc: ");
	start = res;
	res = ft_strcpy(res, path, '\0');
	res = res + ft_strlen(path, NULL) + 1;
	*res = '/';
	res++;
	res = ft_strcpy(res, cmd, '\0');
	return (start);
}

// print error w/o errno
char	*get_path(char *path, char *cmd, t_info *info)
{
	int	i;

	if (abs_relav_path(cmd))
		return (cmd);
	i = 0;
	while (info->path[i] != NULL)
	{		
		path = ft_strcon(path, info->path[i], cmd, info);
		if (!access(path, F_OK))
			if (!access(path, X_OK))
				return (path);
		free (path);
		path = NULL;
		i++;
	}
	print_error(info, "Invalid command");
}

void	ft_execve(t_info *info, char **cmd)
{
	char	*path;

	path = NULL;
	path = get_path(path, cmd[0], info);
	execve(path, cmd, info->envp);
	if (!abs_relav_path(cmd))
		free(path);
	return ;
}
