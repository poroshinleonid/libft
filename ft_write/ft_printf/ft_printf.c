/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:27:18 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/22 19:02:49 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	go_through_type(va_list args, char *s)
{
	if (*s == CV_CHR)
		return (write_chr(args));
	else if (*s == CV_STR)
		return (write_str(args));
	else if (*s == CV_PTR)
		return (write_ptr(args));
	else if (*s == CV_DEC)
		return (write_dec(args));
	else if (*s == CV_INT)
		return (write_int(args));
	else if (*s == CV_USD)
		return (write_usd(args));
	else if (*s == CV_HXL)
		return (write_hxl(args));
	else if (*s == CV_HXU)
		return (write_hxu(args));
	else if (*s == CV_PRC)
		return (write_prc());
	else
		return (0);
}

int	write_specifier(va_list args, int *i, char *s)
{
	*i += 1;
	return (go_through_type(args, s));
}

int	write_char(char *c)
{
	if (write(1, c, 1) != -1)
		return (1);
	else
		return (-1);
}

int	print_fstr(va_list args, char *s)
{
	int	i;
	int	res_len;
	int	write_len;

	i = 0;
	res_len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			write_len = write_specifier(args, &i, s + i);
			if (write_len == -1)
				return (-1);
		}
		else
		{
			if (write_char(s + i) == -1)
				return (-1);
			write_len = 1;
			i++;
		}
		res_len += write_len;
	}
	return (res_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*s;
	int		out_len;

	va_start(args, format);
	s = ft_strdup(format);
	if (!s)
		return (-1);
	out_len = print_fstr(args, s);
	va_end(args);
	free(s);
	return (out_len);
}
