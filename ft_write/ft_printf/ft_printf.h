/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:26:05 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/22 14:06:09 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../libft.h"

# define FLAG 1
# define CONV 2
# define EOI 3
# define CHAR 4
# define SPECIFIERS_L "sdsfdf"

# define CV_CHR 'c'
# define CV_STR 's'
# define CV_PTR 'p'
# define CV_DEC 'd'
# define CV_INT 'i'
# define CV_USD 'u'
# define CV_HXL 'x'
# define CV_HXU 'X'
# define CV_PRC '%'
# define HEX_CHARS "0123456789abcdef"

int		ft_printf(const char *fstr, ...);
int		write_chr(va_list args);
int		write_str(va_list args);
int		write_ptr(va_list args);
int		write_dec(va_list args);
int		write_int(va_list args);
int		write_usd(va_list args);
int		write_hxl(va_list args);
int		write_hxu(va_list args);
int		write_prc(void);
void	ptr_to_hex(void *ptr, char *addr);
char	dig_to_hex(int d);
char	byte_to_hex_1(unsigned char *c);
char	byte_to_hex_2(unsigned char *c);
char	*ft_itoha_lower(unsigned int n);
char	*ft_itoha_upper(unsigned int n);
void	str_toupper(char *s);
char	dig_to_hex(int d);
char	*ft_uitoa(unsigned int un);

#endif
