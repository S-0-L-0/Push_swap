/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:46:13 by edforte           #+#    #+#             */
/*   Updated: 2024/07/11 20:10:59 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_manage *stacks)
{
	if (ft_lstsize(stacks->stack_a) == 2)
		sort_2nbrs(stacks);
	else if (ft_lstsize(stacks->stack_a) == 3)
		sort_3nbrs(stacks);
	else if (ft_lstsize(stacks->stack_a) > 3)
		sort_to5nbrs(stacks);
}

void	sort_2nbrs(t_manage *stacks)
{
	if (stacks->stack_a->content > stacks->stack_a->next->content)
		swap(&stacks->stack_a, "sa\n");
}

void	sort_3nbrs(t_manage *stacks)
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

void	sort_to5nbrs(t_manage *stacks)
{
	while (ft_lstsize(stacks->stack_a) > 3)
			push(&stacks->stack_a, &stacks->stack_b, "pb\n");
	stacks->max_a = max_finder(stacks->stack_a);
	stacks->min_a = min_finder(stacks->stack_a);
	sort_3nbrs(stacks);
	if (ft_lstsize(stacks->stack_b) == 1)
	{
		sort_a_nbr(stacks);
	}
	else
	{
		sort_a_nbr(stacks);
		while (stacks->stack_a->content != min_finder(stacks->stack_a))
			rotate(&stacks->stack_a, "ra\n");
		sort_last(stacks);
		while (stacks->stack_a->content != min_finder(stacks->stack_a))
			rotate(&stacks->stack_a, "ra\n");
	}
}
