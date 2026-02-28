/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_read_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:57:04 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/20 18:18:24 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*fill_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

void	free_buffer(t_buffer *buf)
{
	t_buffer	*temp;

	while (buf != NULL)
	{
		temp = buf->next;
		free (buf->buf);
		free (buf);
		buf = temp;
	}
	return ;
}

char	*str_cpy(char *dst, char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


t_buffer	*add_buf(t_buffer *buf, char *buffer, int rd)
{
	t_buffer	*new;
	t_buffer	*start;

	new = malloc(sizeof(t_buffer));
	if (new != NULL)
		new->buf = malloc(sizeof(char) * (rd + 1));
	if (new == NULL || new->buf == NULL)
	{
		if (new != NULL)
			free (new);
		free_buf(buf);
		return (NULL);
	}
	new->rd = rd;
	new->buf = str_cpy(new->buf, buffer);
	new->next = NULL;
	if (buf == NULL)
		return (new);
	start = buf;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = new;
	return (start);
}

char	*make_file(char *file, t_buffer *buf)
{
	int	len;
	t_buffer	*temp;
	char	*start;

	len = 0;
	temp = buf;
	while (temp != NULL)
	{
		len = len + temp->rd;
		temp = temp->next;
	}
	file = malloc(sizeof(char) * (len + 1));
	if (file == NULL)//free buf?
		return (NULL);
	temp = buf;
	start = file;
	while (temp != NULL)
	{
		file = str_cpy(file, temp->buf);
		file = file + temp->rd;
		temp = temp->next;
	}
	return (start); //free buf?
}


char	*read_buffer(char *file, int fd)
{
	int	rd;
	char	buffer[BUFFER_SIZE];
	t_buffer	*buf;

	rd = read(fd, buffer, BUFFER_SIZE - 1);
	while (1)
	{
		fill_buffer(buffer);
		rd = read(fd, buffer, BUFFER_SIZE - 1);
		if (rd == 0)
			break ;
		buf = add_buf(buf, buffer, rd);
		if (buf == NULL)
			return (NULL);
	}
	file = make_file(file, buf);
	free_buffer(buf);
	return (file);
}


void	read_fd(char *argv)
{
	int	fdi;
	char	*file;

	fd = open(ARGV, O_RDONLY);
	if (rd < 0)
		file_error(argv);
	file = read_buffer(file, fd);
	if (file == NULL)
		return (NULL);
	return (file);
}
	

