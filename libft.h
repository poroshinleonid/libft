/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:49:55 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/10 15:29:49 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_read/gnl.h"
# include "ft_stack/stack.h"
# include "ft_clst/ft_clst.h"
# include "ft_write/ft_printf/ft_printf_bonus.h"

# define FT_BIN_BASE "01"
# define FT_INT_BASE "0123456789"
# define FT_HXU_BASE "0123456789ABCDEF"
# define FT_HXL_BASE "0123456789abcdef"

# define FT_ERROR -1
# define FT_SUCCESS 0
# define FT_LONG_ERR -2147483649

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//////////////////////////
//	Character functions //
//////////////////////////
/**
 * @brief Check if the character is alphanumeric
 * 
 * @param c 
 * @return int 
 */
int				ft_isalnum(int c);

/**
 * @brief Check if the character is aplhabetical
 * 
 * @param c 
 * @return int 
 */
int				ft_isalpha(int c);

/**
 * @brief Check if the character exists in ASCII table
 * 
 * @param c 
 * @return int 
 */
int				ft_isascii(int c);

/**
 * @brief Check if the character is a digit
 * 
 * @param c 
 * @return int 
 */
int				ft_isdigit(int c);

/**
 * @brief Check if the character is printable
 * 
 * @param c 
 * @return int 
 */
int				ft_isprint(int c);

/**
 * @brief Return lowercase letter if its alpha, do nothing otherwise
 * 
 * @param c 
 * @return int 
 */
int				ft_tolower(int c);

/**
 * @brief Return uppercase letter if its alpha, do nothing otherwise
 * 
 * @param c 
 * @return int 
 */
int				ft_toupper(int c);

///////////////////////////////////
// One-way linked list structure //
///////////////////////////////////

/**
 * @brief Add the node "new" at the end of the list.
 * 
 * If it gets null instead of new, nothing is done
 * It doesn't check the corecntess of new
 * new->next MUST be NULL, its responsiblity of
 * the calling function
 * @param lst 
 * @param new 
 */
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Add the node new at the beginning of the list.
 * 
 * Doesn't perform ANY checks.
 * Pass only correct values!
 * @param lst 
 * @param new 
 */
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Clears (and frees) the list and makes it NULL (i.e. empty)
 * 
 * Only pass correct values!
 * @param lst 
 * @param del 
 */
void			ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Frees the node that is passed
 * 
 * Doesn't free next
 * Pass only correct values!
 * @param lst 
 * @param del 
 */
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Iterates the list lst and applies the function
 * 			f on the content of each node.
 * 
 * @param lst 
 * @param f 
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Returns the last node of the list.
 * 
 * @param lst 
 * @return t_list* 
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Iterates the list lst and applies the function
 * 			f on the content of each node.
 * 			Creates(returns) a copy with mapped nodes.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));

/**
 * @brief Alloc and return a new node with content=content and next=NULL
 * 
 * @param content 
 * @return t_list* 
 */
t_list			*ft_lstnew(void *content);

/**
 * @brief Return list size
 * 
 * @param lst 
 * @return int 
 */
int				ft_lstsize(t_list *lst);

/////////////////////////
// Memory manipulation //
/////////////////////////

/**
 * @brief Write zeroes to a byte array
 * 
 * @param s 
 * @param n 
 */
void			ft_bzero(void *s, size_t n);

/**
 * @brief Allocate memory
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void			*ft_calloc(size_t count, size_t size);

/**
 * @brief Reallocate memory of new size
 * 
 * if newsz < oldsz, crop the memory
 * if malloc error, prev memory is not freed and NULL is returned
 * old_mem MUST be a properly allocated chunk of memory.
 * @param old_mem 
 * @param prev_sz 
 * @param new_sz 
 * @return void* 
 */
void			*ft_realloc(void *old_mem, size_t prev_sz, size_t new_sz);

/**
 * @brief locates the first occurrence of c
 * 			(converted to anunsigned char) in string s
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief compare byte string
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copy memory chunk
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void			*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Move memory chunk (src and dst can overlap!)
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void			*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Fill memory chunk of len "len" with a byte "c"
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
void			*ft_memset(void *b, int c, size_t len);

//
///////////////////////////////
// Convert related functions //
///////////////////////////////
//

/**
 * @brief convert an integer into its string representaton
 * 
 * @param n 
 * @return char* 
 */
char			*ft_itoa(int n);

/**
 * @brief Convert a string into integer
 * 
 * Different projects need differend behavious of this function.
 * It's better to rework it for every project and data type
 * @param str 
 * @return int 
 */
int				ft_atoi(const char *str);

/**
 * @brief atoi but normalized to uint (form push_swap)
 * 
 * @param str 
 * @return long int 
 */
long int		ft_atoi_ui(char *str);

//
//////////////////////////////
// Number related functions //
//////////////////////////////
//

/**
 * @brief Return max of 2 ints
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int				ft_max(int a, int b);

/**
 * @brief Return min of 2 ints
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int				ft_min(int a, int b);

//
/////////////////////////
// String manipulation //
/////////////////////////
//

/**
 * @brief Checks if c is in s
 * 
 * @param c 
 * @param s 
 * @return int 
 */
int				ft_in(char c, char *s);

/**
 * @brief Allocates and returns an array of strings obtained by splitting ’s’
 * 			using the character ’c’ as a delimiter. Array is NULL-terminated.
 * 
 * NULL as input or error -> returns NULL
 * Empty string = array with only one item, which is null
 * @param s 
 * @param c 
 * @return char** 
 */
char			**ft_split(char const *s, char c);

/**
 * @brief Returns a pointer to the first
 * 			occurence of c in s (or NULL, if not found)
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char			*ft_strchr(const char *s, int c);

/**
 * @brief Allocate and return a dublicate of the string
 * 
 * @param s1 
 * @return char* 
 */
char			*ft_strdup(const char *s1);

/**
 * @brief Allocate and return a dublicate of the string, but up to (n-1) chars
 * 
 * Auto-terminates
 * @param s 
 * @param n 
 * @return char* 
 */
char			*ft_strndup(char *s, size_t n);

/**
 * @brief allocate and return rev(string)
 * 
 * @param s 
 * @return char* 
 */
char			*ft_strrev(char *s);

/**
 * @brief Apply f() to every character of the string, characters
 * 			are passed by pointer
 * 
 * @param s 
 * @param f 
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Allocates and returns a new string
 * 			which is the result of the concatenation of s1 and s2.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Return the length of the string
 * 
 * Passing NULL results in returning FT_ERROR
 * @param s 
 * @return int 
 */
int				ft_strlen(const char *s);

/**
 * @brief Allocate and return a copy of the string, such that
 * 			new_string[i] = f(i, old_string[i])
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Compare strings (only up to n-th character)
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Find string needle in the haystack,
 * 			only acessing first n characters of the haystack
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char			*ft_strnstr(const char *haystack, \
							const char *needle, size_t len);

/**
 * @brief Find the last occurrence of c in s
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char			*ft_strrchr(const char *s, int c);

/**
 * @brief Allocates and returns a copy of  ’s1’ (s1 IS FREED),
 * 			with the characters specified in ’set’ removed
 * 			from the beginning and the end of the string.
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char			*ft_strtrim(char *s1, char *set);

/**
 * @brief Allocates and returns a substring from the string s.
 * 			The substring begins at index start and is of maximum size len
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char			*ft_substr(const char *s, int start, int len);

/**
 * @brief Appends up to (n-1) chars from s1 to s2
 * 
 * Auto-terminates
 * Memory cant overlap
 * Returns a pointer to s1
 * @param s1 
 * @param s2 
 * @param n 
 * @return char* 
 */
char			*ft_strncat(char *s1, char *s2, size_t n);

/**
 * @brief copies up to (len-1) chars (or until nul-char) from src to dst. 
 * 
 * Auto-terminates.
 * @param dst 
 * @param src 
 * @param len 
 * @return char* 
 */
char			*ft_strncpy(char *dst, char *src, size_t len);

/**
 * @brief Convert str to a number in base "base".
 * 
 * @param str 
 * @param base 
 * @return long int 
 */
long int		ft_atoi_base(char *str, char *base);

/**
 * @brief Get size of array of strings
 * 
 * Returns FT_ERROR if array is NULL
 * @param text 
 * @return int 
 */
int				get_str_arr_sz(char **text);

/**
 * @brief Free array of strings, that is passed by address
 * 
 * Doesn't return any errors
 * Just ignores the array if it is NULL
 * @param text 
 * @return int 
 */
void			free_str_arr(char ***text);

/**
 * @brief Join string array into one string, separated by sep
 * 
 * @param arr 
 * @return char* 
 */
char			*strjoin_str_arr(char **strings, char sep);

/**
 * @brief Get the sum of lengths of all string in a string array
 * 
 * @param strings 
 * @return int 
 */
int				get_str_arr_len(char **strings);

//
///////////////////////////////
// Convert related functions //
///////////////////////////////
//

/**
 * @brief put a character into fd
 * 
 * @param c 
 * @param fd 
 */
int				ft_putchar_fd(char c, int fd);

/**
 * @brief Put a string with endline into fd
 * 
 * @param s 
 * @param fd 
 */
int				ft_putendl_fd(char *s, int fd);

/**
 * @brief put a number (base 10) into a fd
 * 
 * @param n 
 * @param fd 
 */
int				ft_putnbr_fd(int n, int fd);

/**
 * @brief Put a string into fd
 * 
 * @param s 
 * @param fd 
 */
int				ft_putstr_fd(char *s, int fd);

#endif
