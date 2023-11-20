/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:34:05 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 20:06:21 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrev(char *s)
{
	int		len;
	char	*res;
	int		i;

	len = ft_strlen(s);
	if (len == -1)
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		res[i] = s[len - 1];
		len--;
		i++;
	}
	res[i] = '\0';
	return (res);
}
