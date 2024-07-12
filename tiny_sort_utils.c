/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:05:11 by edforte           #+#    #+#             */
/*   Updated: 2024/07/12 13:43:43 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_list	*find_highest(struct s_list *list)
{
	struct s_list	*highest;
	struct s_list	*tmp;
	int				max;

	tmp = list;
	highest = NULL;
	max = -2147483648;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			highest = tmp;
		}
		tmp = tmp->next;
	}
	return (highest);
}

struct s_list	*find_shortest(struct s_list *list)
{
	struct s_list	*shortest;
	struct s_list	*tmp;
	int				min;

	tmp = list;
	shortest = NULL;
	min = 2147483647;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			shortest = tmp;
		}
		tmp = tmp->next;
	}
	return (shortest);
}

void	sort_a_nbr(t_manage *stacks)
{
	if (stacks->stack_b->content > stacks->stack_a->next->next->content)
	{
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
		rotate(&stacks->stack_a, "ra\n");
	}
	else if (stacks->stack_b->content < stacks->stack_a->content)
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
	else if (stacks->stack_b->content > stacks->stack_a->content && \
	stacks->stack_b->content < stacks->stack_a->next->content)
	{
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
		swap(&stacks->stack_a, "sa\n");
	}
	else if (stacks->stack_b->content > stacks->stack_a->next->content && \
	stacks->stack_b->content < stacks->stack_a->next->next->content)
	{
		reverse_rotate(&stacks->stack_a, "rra\n");
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
	}
}

void	sort_last(t_manage *stacks)
{
	if (stacks->stack_b->content > stacks->stack_a->next->next->next->content)
	{
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
		rotate(&stacks->stack_a, "ra\n");
	}
	else if (stacks->stack_b->content < stacks->stack_a->content)
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
	else if (stacks->stack_b->content > stacks->stack_a->content && \
	stacks->stack_b->content < stacks->stack_a->next->content)
	{
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
		swap(&stacks->stack_a, "sa\n");
	}
	else if (stacks->stack_b->content > stacks->stack_a->next->next->content)
	{
		reverse_rotate(&stacks->stack_a, "rra\n");
		push(&stacks->stack_b, &stacks->stack_a, "pa\n");
	}
	else if (stacks->stack_b->content > stacks->stack_a->next->content && \
	stacks->stack_b->content < stacks->stack_a->next->next->content)
		last_case(stacks);
}
