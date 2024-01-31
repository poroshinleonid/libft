/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:26:05 by lporoshi          #+#    #+#             */
/*   Updated: 2024/01/23 17:35:43 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../libft.h"

# define FLAG 1
# define CONV 2
# define EOI 3
# define CHAR 4
# define SPECIFIERS_L "sdsfdf"
# define FLAGS_ONLY "+- 0#"
# define FLAGS_L "0# .-+123456789"
# define CONVS_L "cspdiuxX%"
# define DIGITS "0123456789"
# define DIGITS_START "0123456789"

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

typedef struct s_flags {
	int	minus;
	int	zero;
	int	plus;
	int	blank;
	int	sharp;
	int	dot;
	int	minw;
}	t_flags;

int		ft_printf(const char *fstr, ...);
int		write_chr_b(va_list args, t_flags flags);
int		write_str_b(va_list args, t_flags flags);
int		write_ptr_b(va_list args, t_flags flags);
int		write_dec_b(va_list args, t_flags flags);
int		write_usd_b(va_list args, t_flags flags);
int		write_hxl_b(va_list args, t_flags flags);
int		write_hxu_b(va_list args, t_flags flags);
int		write_prc_b(t_flags flags);
void	ptr_to_hex_b(void *ptr, char *addr);
char	byte_to_hex_1_b(unsigned char *c);
char	byte_to_hex_2_b(unsigned char *c);
char	*ft_itoha_lower_b(unsigned int n, t_flags flags);
char	*ft_itoha_upper_b(unsigned int n, t_flags flags);
void	str_toupper_b(char **s);
char	dig_to_hex_b(int d);
char	*crop_s_b(char *s, int maxw);
char	*get_s_minmaxed_b(char *s, t_flags flags);
char	*get_s_of_minw_rightpad_b(char *s, int minw);
int		ft_max_b(int a, int b);
char	*ft_strncpy_b(char *dst, char *src, size_t n);
int		go_through_flags_b(char **s, t_flags *flags);
int		check_actual_flags_b(char *s, t_flags *flags);
int		check_minw_b(char *s, t_flags *flags);
int		check_precision_b(char *s, t_flags *flags);
int		check_conv_b(char *s, t_flags *flags);
void	init_flags_b(t_flags *flags);
char	*get_s_minmaxed_b(char *s, t_flags flags);
char	*get_s_of_minw_rightpad_b(char *s, int minw);
char	*get_s_of_minw_leftpad_b(char *s, int minw);
char	*ft_strncpy_b(char *dst, char *src, size_t n);
int		check_precision_b(char *s, t_flags *flags);
int		ft_in_b(char c, char *s);
char	*get_res_s_b(char *s, t_flags flags);
int		pad_str_b(char **s, t_flags flags);
char	*crop_strrepr_b(char *s, int maxw);
char	*pad_strrepr_b(char *s, t_flags flags);
char	*pad_left_b(char *s, t_flags flags);
char	*pad_right_b(char *s, t_flags flags);
char	*ft_itoa_w_flags_b(int i, t_flags flags);
int		write_int_b(va_list args, t_flags flags);
char	*pad_digit_precision_b(char *s, t_flags flags);
char	*pad_digit_minw_b(char *s, t_flags flags);
char	*add_sign_b(char *s, t_flags flags, int i);
char	*get_d_minw_padded_b(char *s, t_flags flags, char pad_char);
char	*get_d_of_minw_rightpad_b(char *s, t_flags flags, char pad_char);
char	*get_d_of_minw_leftpad_b(char *s, t_flags flags, char pad_char);
char	*ft_itoa_no_sign_b(int i, t_flags flags);
int		get_int_len_b(int i, t_flags flags);
char	*add_0x_b(char *s, unsigned int n, t_flags flags);
char	*ft_uitoa_b(unsigned int un, t_flags flags);
char	*pad_percent_minw_b(char *s, t_flags flags);
char	*add_sign_minus_b(char *s, t_flags flags);
char	*add_sign_plus_b(char *s, t_flags flags);
char	*add_sign_blank_b(char *s, t_flags flags);
char	*pad_minw_and_0x_b(char *n_hexrepr, int n, t_flags flags);
char	*ft_itoa_pad_and_sign_b(char *res_str, t_flags flags, int i);
int		get_uint_len_b(unsigned int un);

#endif
