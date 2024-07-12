/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:47:02 by edforte           #+#    #+#             */
/*   Updated: 2024/07/12 13:29:34 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *lst)
{
	if (lst->next)
		free_list(lst->next);
	free(lst);
}

int	already_sorted(struct s_list *stack)
{
	struct s_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sorting(char **numbers)
{
	t_manage		stacks;

	if (numbers_size(numbers) > 1)
	{
		stacks = set_manege(numbers);
		if (already_sorted(stacks.stack_a) == 1)
		{
			if (numbers_size(numbers) <= 5)
				tiny_sort(&stacks);
			else
				push_swap(&stacks);
		}
		free_list(stacks.stack_a);
	}
}

int	ft_lstsize(struct s_list *lst)
{
	int				i;
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
