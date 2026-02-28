/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:07:33 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/28 01:12:39 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define BUFFER_SIZE	1000;

typedef struct	s_info
{
	int	argc;
	char	**argv;
	int	fd_infile;
	int	fd_outfile;
	int	p_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1;
	char	**cmd2;
}	t_info;

void    file_error(char *argv);
int	check_fd(t_info *info);

typedef struct	s_buffer
{
	int	rd;
	char	*buf;
	t_buffer	*next;
}	t_buffer;


# endif
