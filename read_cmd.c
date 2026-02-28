/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:01:56 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/28 07:36:09 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\n' || c == '\r'
			|| c == '\v' || c == '\0')
		return (1);
	return (0);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] > 33)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (!is_space(str[i]))
		i++;
	return (i);
}

int	count_cmd(char *argv)
{
	int	cmd;
	int	i;

	cmd = 0;
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] > 32 && argv[i] != 127 && isspace(argv[i + 1]))
		       cmd++;
		i++;
	}
	return (cmd);
}

char	**split_cmd(char **cmd_args, char *argv, t_info *info)
{
	int	count;
	int	i;

	count = count_cmd(argv);
	cmd_args = malloc(sizeof(char *) * (count + 1));
	if (cmd_args == NULL)
		print_error(info, "");
	i = 0;
	while (i < count)
	{
		cmd_args[i] = malloc(sizeof(char) * (ft_strlen(argv) + 1));
		if (cmd_args[i] == NULL)
			print_error(info, "");
		cmd_args[i] = ft_strcpy(cnd_args[i], argv);
		argv = argv + ft_strlen(argv);
		i++;
	}
	cmd_args[i] = '\0';
	return (cmd_args);
}

