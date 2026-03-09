/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:07:33 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/07 18:50:47 by thi-ming         ###   ########.fr       */
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
# include <sys/wait.h>

typedef struct s_info
{
	int		argc;
	char	**argv;
	char	**envp;	
	int		fd_infile;
	int		fd_outfile;
	int		p_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1;
	char	**cmd2;
	char	**path;
}	t_info;

t_info	*check_fd(t_info *info);
char	**split_cmd(char **cmd_args, char *argv, t_info *info);
int		ft_strcmp(char *dst, char *src, int num);
char	*find_path(char *path, t_info *info);
t_info	*split_envp(t_info *info);
//tool split
int		is_space(char c);
int		is_colon(char c);
char	*ft_strcpy(char *dst, char *src, char c);
int		ft_strlen(char *str, int (*condition)(char c));
int		count_num(char *str, int (*condition)(char c));
//pipe - fork - execve
t_info	*ft_pipe(t_info *info);
int		ft_waitpid(t_info *info);
void	ft_fork1(t_info *info);
int		ft_fork2(t_info *info, int code);
int		ft_execve(t_info *info, char **cmd);
char	*get_path(char *path, char *cmd, t_info *info);
char	*ft_strcon(char *res, char *path, char *cmd, t_info *info);
int		abs_relav_path(char *cmd, t_info *info);
//clean up - print error
void	free_array(char **cmd);
void	free_info(t_info *info);
void	close_fd(t_info *info);
void	print_error(t_info *info, char *str, int code);
//main functions
t_info	*make_info(t_info *info, int argc, char **argv, char **envp);
int		ft_piping(t_info *info, int code);

#endif
