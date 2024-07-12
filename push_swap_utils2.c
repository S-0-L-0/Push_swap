/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:39 by edforte           #+#    #+#             */
/*   Updated: 2024/07/12 13:40:55 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position(struct s_list *list, struct s_list *node)
{
	struct s_list	*tmp;
	int				i;

	i = 0;
	tmp = list;
	while (tmp && tmp != node)
	{
		i ++;
		tmp = tmp->next;
	}
	return (i);
}

void	double_mvs(t_manage *stacks, struct s_list *bnod, struct s_list *cheap)
{
	int	bn_pos;
	int	chp_pos;

	bn_pos = position(stacks->stack_a, bnod);
	chp_pos = position(stacks->stack_b, cheap);
	if (bn_pos <= ft_lstsize(stacks->stack_a) / 2 && \
	chp_pos <= ft_lstsize(stacks->stack_b) / 2)
	{
		rotate(&stacks->stack_a, NULL);
		rotate(&stacks->stack_b, "rr\n");
	}
	else if (bn_pos > ft_lstsize(stacks->stack_a) / 2 && \
	chp_pos > ft_lstsize(stacks->stack_b) / 2)
	{
		reverse_rotate(&stacks->stack_a, NULL);
		reverse_rotate(&stacks->stack_b, "rrr\n");
	}
}

void	move_a(t_manage *stacks, struct s_list *best_node)
{
	int	bn_pos;

	bn_pos = position(stacks->stack_a, best_node);
	if (bn_pos <= ft_lstsize(stacks->stack_a) / 2)
		rotate(&stacks->stack_a, "ra\n");
	else
		reverse_rotate(&stacks->stack_a, "rra\n");
}

void	move_b(t_manage *stacks, struct s_list *cheapest)
{
	int	chp_pos;

	chp_pos = position(stacks->stack_b, cheapest);
	if (chp_pos <= ft_lstsize(stacks->stack_b) / 2)
		rotate(&stacks->stack_b, "rb\n");
	else
		reverse_rotate(&stacks->stack_b, "rrb\n");
}
