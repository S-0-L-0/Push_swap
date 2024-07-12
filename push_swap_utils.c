/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:41:06 by edforte           #+#    #+#             */
/*   Updated: 2024/07/12 13:34:31 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_counter(t_manage *stacks)
{
	struct s_list	*tmp;
	int				i;

	tmp = stacks->stack_b;
	i = 0;
	while (tmp)
	{
		if (i <= (ft_lstsize(tmp) / 2) + 1)
		{
			tmp->moves = i;
			tmp->moves += fc_calca(stacks, tmp->content);
		}
		else
		{
			tmp->moves = (ft_lstsize(stacks->stack_b) - i);
			tmp->moves += fc_calca(stacks, tmp->content);
		}
		i ++;
		tmp = tmp->next;
	}
}

struct s_list	*bnode_finder(t_manage *stacks, int content)
{
	struct s_list	*tmp;
	struct s_list	*last_node;

	tmp = stacks->stack_a;
	last_node = stacks->stack_a;
	while (last_node->next)
		last_node = last_node->next;
	if (content > last_node->content && content < tmp->content)
	{
		return (tmp);
	}
	while (tmp->next)
	{
		if (content > tmp->content && content < tmp->next->content)
		{
			return (tmp->next);
		}
		else
			tmp = tmp->next;
	}
}

int	fc_calca(t_manage *stacks, int content)
{
	struct s_list	*best_node;
	struct s_list	*tmp;
	int				i;

	i = 0;
	tmp = stacks->stack_a;
	best_node = bnode_finder(stacks, content);
	while (tmp && tmp != best_node)
	{
		tmp = tmp->next;
		i ++;
	}
	if (i < (ft_lstsize(stacks->stack_a) / 2) + 1)
		return (i + 1);
	else
		return ((ft_lstsize(stacks->stack_a) - i) + 1);
}

struct s_list	*cheap_finder(struct s_list *list)
{
	struct s_list	*tmp;
	struct s_list	*cheapest;
	int				res;

	res = 2147483647;
	cheapest = NULL;
	tmp = list;
	while (tmp)
	{
		if (tmp->moves < res)
		{
			cheapest = tmp;
			res = tmp->moves;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}
