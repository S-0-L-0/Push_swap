/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:13 by edforte           #+#    #+#             */
/*   Updated: 2024/06/26 14:09:26 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int av_are_nbrs(int ac, char **av)
{
	int		i;
	char	**numbers;

	numbers = *av + 1; // questa cosa si puo fare? il primo av é il filename
	if (ac == 2)
		numbers = ft_split(*av + 1, 32);
	i = -1;
	while(*numbers) // prende pure il filename perche parte da av[0]
	{
		if (*numbers[0] == '-')
			i ++;
		while (*numbers[++i])
		{
			if (ft_isdigit(numbers[i]) == 0)
				return(1);
		}
		i = -1;
		numbers ++;
	}
	return(0);
}

static int av_are_int(int ac, char **av)
{
	int		i;
	long	nbr;
	char	**numbers;

	i = 1;
	nbr = 0;
	numbers = *av + 1; // questa cosa si puo fare? il primo av é il filename
	if (ac == 2)
		numbers = ft_split(*av + 1, 32);
	while (numbers[i])
	{
		nbr = ft_atol(numbers[i]);
		if (nbr < -2147483648 || nbr > 2147483647)
			return (1);
		i ++;
	}
	return (0);
}
static int av_are_double(int ac, char **av)
{
	char	**numbers;

	i = 0;
	j = 0;
	numbers = *av + 1; // questa cosa si puo fare? il primo av é il filename
	if (ac == 2)
		numbers = ft_split(*av + 1, 32);
}

int	checker(int ac, char **av)
{
	if (av_are_nbrs != 0 || av_are_int != 0 || av_are_double != 0)
	{
		write(2, "Error", 5);
		write(2, "\n", 1);
		return (1)
	}
}