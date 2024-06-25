/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:40 by edforte           #+#    #+#             */
/*   Updated: 2024/06/25 19:02:27 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void push(t_list **source, t_list **dest, char *str)
{
	t_list	*new_node;
	if (!source || !*source)
		return;
	new_node = *source;
	*source = (*source)->next;
	new_node->next = NULL;
	ft_lstadd_front(dest, new_node);
	write(1, str, 2);
	write(1, "\n", 1);
}
