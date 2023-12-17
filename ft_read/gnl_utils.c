/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:24:40 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/17 18:45:10 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_in_gnl(char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_str_realloc(char **str, size_t len)
{
	char	*new_str;
	size_t	src_len;

	if (!(*str))
	{
		src_len = 0;
		new_str = (char *)malloc(len);
		if (!new_str)
			return (NULL);
		while (src_len < len)
			new_str[src_len++] = '\0';
		return (new_str);
	}
	src_len = ft_strlen_gnl(*str);
	new_str = (char *)malloc(len);
	if (!new_str)
	{
		free(*str);
		return (NULL);
	}
	ft_strncpy(new_str, *str, len);
	while (src_len < len)
		new_str[src_len++] = '\0';
	free(*str);
	return (new_str);
}

int	ft_strlen_gnl(char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (*str && *str != EOF)
	{
		str++;
		len++;
	}
	return (len);
}

// Copies N symbold and then sets N+1TH SYMBOL as '\0'!
char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*og_dst;

	og_dst = dst;
	while (n > 0)
	{
		*dst = *src;
		if ((*src) == '\0')
			return (og_dst);
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return (og_dst);
}

int	check_read_success(int read_sz, char **tail, char **line)
{
	if (read_sz == -1)
	{
		if (tail)
		{
			free(*tail);
			*tail = NULL;
		}
		if (line)
			free(*line);
		return (1);
	}
	return (0);
}
