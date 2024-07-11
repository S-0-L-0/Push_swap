/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:28 by edforte           #+#    #+#             */
/*   Updated: 2024/07/11 17:20:49 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap (t_manage *stacks)
{
	push_b(stacks);
	sort_a(stacks);
	push_a(stacks);
	final_sort(stacks);
	return ;
}
