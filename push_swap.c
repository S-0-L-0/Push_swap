/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:28 by edforte           #+#    #+#             */
/*   Updated: 2024/06/25 16:51:01 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool check_input(int ac, char **av)
{
	int i = -1;
	while(*av)
	{
		while (*av[++i])
		{
			if (ft_isdigit(av[i]) == 0 || (i == 0 && (*av[i]) == '-'))
			{
				write(2, "Error\n", 6);
				return(false);
			}
		}
		i = -1;
		av ++;
	}
	return(true);
}
int main(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;
	char	**numbers = NULL;

	i = 1;
	a = NULL;
	b = NULL;
	if ( ac == 2)
		numbers = ft_split((*av + 1), 32);
	else
		numbers = av;
	if (check_input(ac, numbers) == false)
		return(1);
	if (ac > 2)
	{
		while (ac > 1)
		{
			make_list(&a, atoi(av[i]));
			ac --;
			i ++;
		}
	}
	return (0);
}