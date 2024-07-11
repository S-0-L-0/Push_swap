/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:04:55 by edforte           #+#    #+#             */
/*   Updated: 2024/07/11 10:47:40 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_finder(struct s_list *stack_a)
{
	int		min;
	struct s_list	*tmp;

	min = 2147483647;
	tmp = stack_a;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}
int	av_finder(struct s_list *stack_a)
{
	struct s_list	*tmp;
	int				size;
	int				i;

	tmp = stack_a;
	size = ft_lstsize(tmp);
	i = 0;
	while (i < size/2)
	{
		tmp = tmp->next;
		i ++;
	}
	while (tmp->content == min_finder(stack_a) || tmp->content == max_finder(stack_a))
		tmp = tmp->next;
	i = tmp->content;
	return (i);
}
int	max_finder(struct s_list *stack_a)
{
	int		max;
	struct s_list	*tmp;

	max = -2147483648;
	tmp = stack_a;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

void	free_matrix(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i ++;
	}
	free (av);
}
