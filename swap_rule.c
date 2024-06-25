/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:53:22 by edforte           #+#    #+#             */
/*   Updated: 2024/06/25 19:15:00 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



swap(tumadre, "ss\n")

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

void swap(t_list **list1, t_list **list2, char *str)
{
	t_list *tmp_node;
	t_list *tmp2_node;

	tmp_node = NULL;
	tmp2_node = NULL;
	if (*list1 == NULL || (*list)->next == NULL)
		return;
	tmp_node = (*list)->next;
	tmp_node->next = (*list)->next->next;
	*list = tmp_node;
	write(1, str, 2);
	write(1, "\n", 1);
}