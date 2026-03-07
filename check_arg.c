/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:13:03 by thi-ming          #+#    #+#             */
/*   Updated: 2026/02/28 01:53:25 by thi-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	file_error(char *argv)
{
	int	i;
	(void)argv;

	i = 0;
	while (strerror(errno)[i] != '\0')
		i++;
	write (2, "Error: ", 7);
	write (2, strerror(errno), i);
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}

