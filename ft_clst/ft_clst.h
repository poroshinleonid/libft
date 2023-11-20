/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:16 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 21:23:43 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLST_H
# define FT_CLST_H

# include "../libft.h"

typedef struct s_lst
{
	void			*content;
	int				is_top;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

/**
 * @brief Initializes memory that was alloced for node with zeroes
 * 
 * content is NULL
 * is_top is 0
 * next and prev are NULL
 * @param node 
 * @return int 
 */
int	init_lst_node(t_lst *node)
{
	if (!t_lst)
		return (FT_ERROR);
	node->content = NULL;
	node->next = NULL;
	node->prev = NULL;
	node->is_top = 0;
}

/**
 * @brief Allocate and return a new node with content
 * 
 * @param content 
 * @return t_lst* 
 */
t_lst	*new_lst_node(void *content)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (new_node == NULL)
		return (NULL);
	if (init_lst_node(new_node) == FT_ERROR)
		return (NULL);
	new_node->content = content;
	return (new_node);
}

/**
 * @brief Inserts node new_last_node at the end of the list
 * 
 * @param list 
 * @param appendix 
 * @return int 
 */
int		lst_append_node(t_lst **list, t_list *new_last_node);

/**
 * @brief Inserts node new_first_node at the beginning of the list
 * 
 * @param lst 
 * @param new_first_node 
 * @return int 
 */
int		lst_insert_node(t_lst **lst, t_list *new_first_node);

/**
 * @brief Appends node with content at the end of the list
 * 
 * @param list 
 * @param content 
 * @return int 
 */
int		lst_append_content(t_lst **list, void *content);

/**
 * @brief Inserts node with content at the beginning of the list
 * 
 * @param lst 
 * @param content 
 * @return int 
 */
int		lst_insert_content(t_lst **lst, void *content);

int		lst_put_node_after(t_lst **lst, t_lst node, void *target);
int		lst_put_node_before(t_lst **lst, t_lst node, void *target);
int		lst_put_content_after(t_lst **lst, void *content, void *target); // ADD void funciton del()
int		lst_put_content_before(t_lst **lst, void *content, void *target); // ADD void funciton del()

void	*lst_pop_start(t_lst **lst); // ADD void funciton del()
void	*lst_pop_end(t_lst **lst); // ADD void funciton del()

/**
 * @brief pop the node with content
 * 
 * @param lst 
 * @param content 
 * @return void* 
 */
void	*lst_pop_by_content(t_lst **lst, void *content);

int		lst_del_start(t_lst **lst); // ADD void funciton del()
int		lst_del_end(t_lst **lst); // ADD void funciton del()
int		lst_del_by_content(t_lst **lst); // ADD void funciton del()

int		lst_clear(t_lst **lst); // ADD void funciton del()

t_lst	*lst_search(t_lst **lst, void *content);

int		get_lst_size(t_lst *lst);

t_lst	*get_last(t_lst *node);
t_lst	*get_first(t_lst *node);

/**
 * @brief FIRST LIST HEAD IS THE HEAD OF THE RESULT
 * 
 * @param list_a 
 * @param list_b 
 * @return int 
 */
int		lst_merge(t_lst **list_a, t_lst **list_b);

t_lst	*lst_clone(t_lst *list);

/**
 * @brief SHOULD WORK EVEN IF THEY ARE IN DIFFERENT LISTS
 * 
 * @param node1 
 * @param node2 
 * @return int 
 */
int		lst_swap_nodes(t_lst *node1, t_lst *node2);

/**
 * @brief creates NEW list with only these nodes
 * 
 * @param node1 
 * @param node2 
 * @return t_list* 
 */
t_list	*lst_slice(t_lst *node1, t_lst *node2);

void	*lst_to_array(t_lst **lst);

#endif
