/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_tools_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:01:56 by thi-ming          #+#    #+#             */
/*   Updated: 2026/03/07 18:36:40 by thi-ming         ###   ########.fr       */
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

int	is_colon(char c)
{
	if (c == ':')
		return (1);
	return (0);
}

char	*ft_strcpy(char *dst, char *src, char c)
{
	int	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] > 32 && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strlen(char *str, int (*condition)(char c))
{
	int	i;

	i = 0;
	if (condition == NULL)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	while (!condition(str[i]))
		i++;
	return (i);
}

int	count_num(char *str, int (*condition)(char c))
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 32 && str[i] != 127 && condition(str[i + 1]))
			num++;
		i++;
	}
	return (num);
}
