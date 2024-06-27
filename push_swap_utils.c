/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:39 by edforte           #+#    #+#             */
/*   Updated: 2024/06/26 12:30:08 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i ++;
	}
	return (res * sign);
}

void	free_list(t_list *lst)
{
	if (lst->next)
		free_list(lst->next);
	free(lst);
}

static char	*ft_mkword(char const *str, int start, int end)
{
	int		i;
	char	*substr;

	i = 0;
	substr = (char *)malloc(((end - start) + 2) * sizeof(char));
	while (start <= end)
	{
		substr[i] = str[start];
		i ++;
		start ++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	wds_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i])
			count ++;
		while (s[i] && s[i] != c)
			i ++;
	}
	return (count);
}

static char	**memall(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc((1 + wds_count(s, c)) * sizeof(char *));
	if (!words)
		return (NULL);
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**words;
	int		count;

	words = memall(s, c);
	if (!words)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i ++;
			words[count++] = ft_mkword(s, start, (i - 1));
		}
	}
	words[count] = NULL;
	return (words);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[i] || b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i ++;
	}
	return (0);
}
t_list	*make_list(int ac, char **av)
{
	t_list	*a;
	t_list	*tmp;

	(av) ++;
	a = ft_lstnew(ft_atol(*av));
	tmp = a;
	while (ac > 1)
	{
		printf("%lu\n", ft_atol(*av));
		tmp->next = ft_lstnew(ft_atol(*av));
		tmp = tmp->next;
		(av) ++;
		ac --;
	}
	return (a);
}
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
