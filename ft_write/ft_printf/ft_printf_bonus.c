/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:26:05 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:17:13 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	go_through_type_b(va_list args, char *s, t_flags flags)
{
	if (*s == CV_CHR)
		return (write_chr_b(args, flags));
	else if (*s == CV_STR)
		return (write_str_b(args, flags));
	else if (*s == CV_PTR)
		return (write_ptr_b(args, flags));
	else if (*s == CV_DEC)
		return (write_dec_b(args, flags));
	else if (*s == CV_INT)
		return (write_int_b(args, flags));
	else if (*s == CV_USD)
		return (write_usd_b(args, flags));
	else if (*s == CV_HXL)
		return (write_hxl_b(args, flags));
	else if (*s == CV_HXU)
		return (write_hxu_b(args, flags));
	else if (*s == CV_PRC)
		return (write_prc_b(flags));
	else
		return (0);
}

int	write_specifier_b(va_list args, int *i, char *s)
{
	t_flags	flags;
	int		spec_len;

	init_flags_b(&flags);
	spec_len = go_through_flags_b(&s, &flags);
	if (spec_len == -1)
		return (-1);
	else
		*i += spec_len + 1;
	s += spec_len;
	return (go_through_type_b(args, s, flags));
}

int	write_char_b(char *c)
{
	if (write(1, c, 1) != -1)
		return (1);
	else
		return (-1);
}

int	print_fstr_b(va_list args, char *s)
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
			write_len = write_specifier_b(args, &i, s + i);
			if (write_len == -1)
				return (-1);
		}
		else
		{
			if (write_char_b(s + i) == -1)
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
	out_len = print_fstr_b(args, s);
	va_end(args);
	free(s);
	return (out_len);
}
