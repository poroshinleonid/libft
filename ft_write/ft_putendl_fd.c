/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:49:13 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/11 14:31:16 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = ft_putstr_fd(s, fd);
	if (i == -1)
		return (-1);
	if (ft_putchar_fd('\n', fd) == 1)
		return (i + 1);
	return (-1);
}
