/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:22:46 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:56:28 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	dump_from_tail(char **tail, char **line)
{
	int	l;

	l = ft_strlen_gnl(*tail);
	if (l == 0)
	{
		free(*tail);
		*tail = NULL;
		return (0);
	}
	*line = (char *)malloc(l + 1);
	if (!(*line))
	{
		free(*tail);
		*tail = NULL;
		return (-1);
	}
	ft_strncpy(*line, *tail, l);
	free(*tail);
	*tail = NULL;
	return (l);
}

char	*dump_to_tail(char **tail, char **line)
{
	int		eol_pos;
	int		line_len;
	char	*temp_line;

	eol_pos = ft_in(*line, '\n');
	line_len = ft_strlen_gnl(*line);
	if (eol_pos == line_len - 1)
		return (*line);
	*tail = (char *)malloc(line_len - eol_pos);
	temp_line = (char *)malloc(eol_pos + 2);
	if (!(*tail) || !temp_line)
	{
		if (temp_line)
			free(temp_line);
		free(*line);
		*line = NULL;
		if (*tail)
			free(*tail);
		*tail = NULL;
		return (NULL);
	}
	ft_strncpy(*tail, *line + eol_pos + 1, line_len - eol_pos - 1);
	ft_strncpy(temp_line, *line, eol_pos + 1);
	free(*line);
	return (temp_line);
}

int	read_buf(int fd, char **line, int init_len)
{
	int	read_sz;

	*line = ft_str_realloc(line, init_len + BUFFER_SIZE + 1);
	if (!(*line))
		return (-1);
	read_sz = read(fd, *line + init_len, BUFFER_SIZE);
	if (ft_strlen_gnl(*line) < init_len + BUFFER_SIZE + 1)
	{
		*line = ft_str_realloc(line, ft_strlen_gnl(*line) + 1);
		if (!(*line))
			return (-1);
	}
	if (read_sz == -1 && *line)
	{
		free(*line);
		*line = NULL;
	}
	return (read_sz);
}

char	*scan_line(int fd, char **line, char **tail, int l)
{
	int	read_sz;
	int	end_pos;

	read_sz = l;
	end_pos = l;
	while (1)
	{
		if (!(*line))
			return (*line);
		else if (read_sz == 0)
			return (*line);
		else if (*line && ft_in(*line, '\n') == -1)
		{
			read_sz = read_buf(fd, line, end_pos);
			if (read_sz == -1 && check_read_success(read_sz, line, NULL))
				return (NULL);
		}
		else
		{
			*line = dump_to_tail(tail, line);
			return (*line);
		}
		end_pos += BUFFER_SIZE;
	}
}

char	*get_next_line(int fd)
{
	static char	*buf_tail = NULL;
	char		*cur_line;
	int			read_sz;

	read_sz = 0;
	cur_line = NULL;
	if (fd < 0)
		return (free_buf_tail(&buf_tail));
	if (buf_tail)
	{
		read_sz = dump_from_tail(&(buf_tail), &cur_line);
		if (check_read_success(read_sz, &(buf_tail), NULL))
			return (NULL);
	}
	read_sz += read_buf(fd, &cur_line, read_sz);
	if (read_sz == 0 && ft_strlen_gnl(cur_line) > 0)
		return (cur_line);
	if (check_read_success(read_sz, NULL, NULL) || !read_sz)
	{
		if (cur_line)
			return (free(cur_line), NULL);
	}
	scan_line(fd, &cur_line, &(buf_tail), read_sz);
	return (cur_line);
}
