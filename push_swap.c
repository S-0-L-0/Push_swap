/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:28 by edforte           #+#    #+#             */
/*   Updated: 2024/06/26 12:37:39 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// || (i == 0 && (*av[i]) == '-')

static bool check_input(int ac, char **av)
{
	int i = -1;
	while(*av)
	{
		if (av[0] == '-')
			i ++;
		while (*av[++i])
		{
			if (ft_isdigit(av[i]) == 0)
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
			make_list(&a, ft_atol(av[i]));
			ac --;
			i ++;
		}
	}
	return (0);
}
// int main(...)
// dichiarazione stack;
// se ac < 2 -> return 1
// se av non sono numeri -> return 1
// se ac == 2 uso split
// uso atol, se nbrs > int max -> return 1
// se input corretto uso make_list
// lancio push_swap

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;

	a = NULL;
	b = NULL;
	if (ac < 2 || checker(ac, av) == 1)  // checker, verifica se ac == 2 o +, applica split,
		return (1);                         // controlla se sono state inserite lettere o numeri troppo grossi
	while (ac > 1)
	{
		a = make_list(&a, ft_atol(*av));
		(av) ++;
		ac --;
	}
	push_swap(a, b);
	return (0);
}
