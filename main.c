/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:46:03 by edforte           #+#    #+#             */
/*   Updated: 2024/07/12 13:47:54 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_list	*make_list(char **numbers)
{
	struct s_list	*a;

	a = ft_lstnew(ft_atol(*numbers));
	(numbers)++;
	while (*numbers)
	{
		insert_end(&a, ft_atol(*numbers));
		(numbers)++;
	}
	return (a);
}

t_manage	set_manege(char **numbers)
{
	t_manage	stacks;

	stacks.stack_a = make_list(numbers);
	stacks.stack_b = NULL;
	stacks.min_a = min_finder(stacks.stack_a);
	stacks.max_a = max_finder(stacks.stack_a);
	return (stacks);
}

int	main(int ac, char **av)
{
	char			**numbers;
	bool			flag;

	numbers = av + 1;
	flag = false;
	if (ac == 2)
	{
		numbers = ft_split(*(av + 1), 32);
		flag = true;
	}
	if (ac < 2 || checker(numbers) == 1)
	{
		if (flag == true)
			free_matrix(numbers);
		return (1);
	}
	sorting(numbers);
	if (flag == true)
		free_matrix(numbers);
	return (0);
}
