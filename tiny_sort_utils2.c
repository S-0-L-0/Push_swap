/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:20:10 by edforte           #+#    #+#             */
/*   Updated: 2024/07/12 13:43:56 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_case(t_manage *stacks)
{
	rotate(&stacks->stack_a, "rra\n");
	push(&stacks->stack_b, &stacks->stack_a, "pa\n");
	swap(&stacks->stack_a, "sa\n");
	reverse_rotate(&stacks->stack_a, "rra\n");
}
