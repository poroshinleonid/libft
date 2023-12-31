/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:23:47 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/17 18:42:44 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdio.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*split_line_w_eol(char **buf_tail);
char	*fill_cur_line(int fd, char **cur_line, char **buf_tail);
int		ft_in_gnl(char *str, const char c);
char	*ft_str_realloc(char **str, size_t len);
int		ft_strlen_gnl(char *str);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		check_read_success(int read_sz, char **tail, char **line);
void	*free_buf_tail(char **buf_tail);

#endif
