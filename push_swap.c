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

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || checker(ac, av) == 1)
		return (1);
	a = make_list(ac, av);
	while (a->next)
	{
		//printf("%d\n", a->content);
		a = a->next;
	}
	(void)b;
	(void)a;

	return (0);
}
