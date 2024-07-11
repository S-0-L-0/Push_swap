/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:39 by edforte           #+#    #+#             */
/*   Updated: 2024/07/10 16:37:38 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(struct s_list *lst)
{
	int		i;
	struct s_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	i = 0;
	while (tmp->next)
	{
		i ++;
		tmp = tmp->next;
	}
	i++;
	return (i);
}

int	position(struct s_list *list, struct s_list *node)
{
	struct s_list	*tmp;
	int				i;

	i = 0;
	tmp = list;
	while(tmp && tmp != node)
	{
		i ++;
		tmp = tmp->next;
	}
	return (i);
}