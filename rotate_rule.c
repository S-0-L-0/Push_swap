/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:26:56 by edforte           #+#    #+#             */
/*   Updated: 2024/06/26 10:48:01 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **list, char *str)
{
	t_list *first_node;
	t_list *last_node;

	first_node = NULL;
	last_node = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return;
	first_node = *list;
	last_node = *list;
	while(last_node->next)
		last_node = last_node->next;
	(*list) = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	if (str)
		write(1, str, 3);
}