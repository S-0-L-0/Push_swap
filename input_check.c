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

static int av_are_nbrs(char **numbers)
{
	int		i;

	i = -1;
	while(*numbers)
	{
		if (*numbers[0] == '-')
			i ++;
		while ((*numbers)[++i])
		{
			if (ft_isdigit((*numbers)[i]) == 0)
				return(1);
		}
		i = -1;
		numbers ++;
	}
	return(0);
}

static int av_are_int(char **numbers)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (numbers[i])
	{
		nbr = ft_atol(numbers[i]);
		if ( nbr < (-2147483648) || nbr > (2147483647))
			return (1);
		i ++;
	}
	return (0);
}
static int av_are_double(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
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

int	checker(int ac, char **av)
{
	bool	flag;
	char	**numbers;

	numbers = av + 1;
	flag = false;
	if (ac == 2)
	{
		numbers = ft_split(*(av + 1), 32);
		flag = true;
	}
	if (av_are_nbrs(numbers) != 0 || av_are_int(numbers) != 0 || av_are_double(numbers) != 0)
	{
		write(2, "Error\n", 6);
		if (flag == true)
			free_matrix(numbers);
		return (1);
	}
	return (0);
}
