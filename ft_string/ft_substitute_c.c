/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substitute_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:21:26 by lporoshi          #+#    #+#             */
/*   Updated: 2024/02/25 17:56:40 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substitute_c(char *s, char from, char to)
{
	char	*s_orig;

	s_orig = s;
	if (!s)
		return (s_orig);
	while (*s)
	{
		if (*s == from)
			*s = to;
		s++;
	}
	return (s_orig);
}
