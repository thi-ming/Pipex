/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:29:17 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/28 04:44:04 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_info	*make_info(t_info *info, int argc, char **argv)
{
	if (argc != 5)
		exit (1);
	info = malloc(sizeof(t_info));
	if (info == NULL)
		print_error(info, "");
	info->argc = argc;
	info->argv = argv;
	check_fd(info);	
}
