/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:40 by edforte           #+#    #+#             */
/*   Updated: 2024/07/06 23:23:16 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(struct s_list **source, struct s_list **dest, char *str)
{
	t_list	*first_node;

	first_node = NULL;
	if (source == NULL || *source == NULL)
		return;
	first_node = *source;
	*source = (*source)->next;
	first_node->next = *dest;
	*dest = first_node;
	if (str)
	{
		write(1, str, 3);
	}
}

void swap(struct s_list **list, char *str)
{
	struct s_list *tmp;

	tmp = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return;
	tmp = (*list)->next;
	(*list)->next = (*list)->next->next;
	tmp->next = *list;
	*list = tmp;
	if (str)
		write(1, str, 3);
}
void rotate(struct s_list **list, char *str)
{
	struct s_list *first_node;
	struct s_list *last_node;

	first_node = NULL;
	last_node = NULL;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	first_node = *list;
	last_node = *list;
	while(last_node->next)
		last_node = last_node->next;
	*list = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	if (str)
		write(1, str, 3);
}
void reverse_rotate(struct s_list **list, char *str)
{
	struct s_list	*penultimate_node;
	struct s_list	*last_node;

	penultimate_node = NULL;
	last_node = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return;
	penultimate_node = *list;
	last_node = *list;
	while(last_node->next)
	{
		penultimate_node = last_node;
		last_node = last_node->next;
	}
	penultimate_node->next = NULL;
	last_node->next = *list;
	*list = last_node;
	if (str)
		write(1, str, 4);
}
