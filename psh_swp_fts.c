/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_swp_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:51:17 by edforte           #+#    #+#             */
/*   Updated: 2024/07/12 13:33:27 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_manage *stacks)
{
	int	av;

	av = av_finder(stacks->stack_a);
	while (ft_lstsize(stacks->stack_a) > 3)
	{
		if (stacks->stack_a->content != stacks->min_a && \
		stacks->stack_a->content != av && \
		stacks->stack_a->content != stacks->max_a)
		{
			push(&(stacks->stack_a), &(stacks->stack_b), "pb\n");
		}
		else
			rotate(&stacks->stack_a, "ra\n");
	}
}

void	sort_a(t_manage *stacks)
{
	if (stacks->stack_a->content == stacks->max_a)
	{
		rotate(&stacks->stack_a, "ra\n");
		if (stacks->stack_a->content != stacks->min_a)
			swap(&stacks->stack_a, "sa\n");
	}
	else if (stacks->stack_a->next->content == stacks->max_a)
	{
		reverse_rotate(&stacks->stack_a, "rra\n");
		if (stacks->stack_a->content != stacks->min_a)
			swap(&stacks->stack_a, "sa\n");
	}
	else
	{
		if (stacks->stack_a->content != stacks->min_a)
			swap(&stacks->stack_a, "sa\n");
	}
}

void	push_a(t_manage *stacks)
{
	struct s_list	*cheapest;
	struct s_list	*best_node;

	while (stacks->stack_b)
	{
		moves_counter(stacks);
		cheapest = cheap_finder(stacks->stack_b);
		best_node = bnode_finder(stacks, cheapest->content);
		while (stacks->stack_a != best_node || stacks->stack_b != cheapest)
		{
			if (stacks->stack_a != best_node && stacks->stack_b != cheapest)
				double_mvs(stacks, best_node, cheapest);
			else if (stacks->stack_a != best_node)
				move_a(stacks, best_node);
			else if (stacks->stack_b != cheapest)
				move_b(stacks, cheapest);
		}
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
	}
}

void	final_sort(t_manage *stacks)
{
	struct s_list	*first;
	int				pos;

	first = stacks->stack_a;
	while (first && first->content != min_finder(stacks->stack_a))
		first = first->next;
	pos = position(stacks->stack_a, first);
	while (stacks->stack_a != first)
	{
		if (pos <= ft_lstsize(stacks->stack_a) / 2)
			rotate(&stacks->stack_a, "ra\n");
		else
			reverse_rotate(&stacks->stack_a, "rra\n");
	}
}
