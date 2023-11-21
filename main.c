/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:54:58 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/21 17:04:54 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	ft_printf("[%d %d %s]", ft_strlen("12345678"), 999999, "Money");
	ft_printf("[%s]\n", get_next_line(1));
	get_next_line(-1);
	return (0);
}
