/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:54:13 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/14 14:10:12 by lporoshi         ###   ########.fr       */
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
