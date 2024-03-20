/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:54:13 by lporoshi          #+#    #+#             */
/*   Updated: 2024/03/20 20:19:15 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in(char c, char *s)
{
	if (!s)
		return (FT_ERROR);
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

int	ft_consists_of(char *str, char *chars)
{
	if (!str)
		return (FT_ERROR);
	while (*str)
		if (!ft_in(*(str++), chars))
			return (0);
	return (1);
}
