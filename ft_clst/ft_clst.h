/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:16 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/21 16:57:00 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLST_H
# define FT_CLST_H

# include "../libft.h"

typedef struct s_lst
{
	void			*content;
	int				is_head;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

/**
 * @brief Allocate and return a new node with content
 * 
 * @param content 
 * @return t_lst* 
 */
t_lst		*new_lst_node(void *content);

/**
 * @brief Inserts node new_last_node at the end of the list
 * 
 * @param list 
 * @param appendix 
 * @return int 
 */
int			lst_append_node(t_lst **list, t_lst *new_last_node);

/**
 * @brief Inserts node new_first_node at the beginning of the list
 * 
 * @param lst 
 * @param new_first_node 
 * @return int 
 */
int			lst_insert_node(t_lst **list, t_lst *new_first_node);

/**
 * @brief Appends node with content at the end of the list
 * 
 * @param list 
 * @param content 
 * @return int 
 */
int			lst_append_content(t_lst **list, void *content);

/**
 * @brief Inserts node with content at the beginning of the list
 * 
 * @param lst 
 * @param content 
 * @return int 
 */
int			lst_insert_content(t_lst **list, void *content);

#endif

// int		lst_put_node_after(t_lst **list, t_lst node, void *target);
// int		lst_put_node_before(t_lst **list, t_lst node, void *target);
// void	*lst_pop_start(t_lst **list); // ADD void funciton del()
// void	*lst_pop_end(t_lst **list); // ADD void funciton del()
// void	*lst_pop_by_content(t_lst **list, void *content);
// int		lst_del_start(t_lst **list); // ADD void funciton del()
// int		lst_del_end(t_lst **list); // ADD void funciton del()
// int		lst_del_by_content(t_lst **list); // ADD void funciton del()
// int		lst_clear(t_lst **list); // ADD void funciton del()
// t_lst	*lst_search(t_lst **list, void *content);
// int		get_lst_size(t_lst *list);
// t_lst	*get_last(t_lst *node);
// t_lst	*get_first(t_lst *node);
// int		lst_merge(t_lst **list_a, t_lst **list_b);
// t_lst	*lst_clone(t_lst *list);
// int		lst_swap_nodes(t_lst *node1, t_lst *node2);
// t_lst	*lst_slice(t_lst *node1, t_lst *node2);
// void	*lst_to_array(t_lst **list);
