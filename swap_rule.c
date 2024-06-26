/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:53:22 by edforte           #+#    #+#             */
/*   Updated: 2024/06/26 10:22:02 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **list, char *str)
{
	t_list *tmp_node;

	tmp_node = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return;
	tmp_node = (*list)->next;
	tmp_node->next = (*list)->next->next;
	*list = tmp_node;
	if (str)
		write(1, str, 3);
}
