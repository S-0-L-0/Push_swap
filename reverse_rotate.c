/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:46:39 by edforte           #+#    #+#             */
/*   Updated: 2024/06/26 11:07:32 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_list **list, char *str)
{
	t_list *penultimate_node;
	t_list *last_node;

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