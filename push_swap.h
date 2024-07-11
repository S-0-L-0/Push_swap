/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:09:18 by edforte           #+#    #+#             */
/*   Updated: 2024/07/11 18:40:47 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	int				content;
	int				moves;
	struct s_list	*next;
}	t_list;

typedef struct s_manage
{
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	int		min_a;
	int		max_a;
} t_manage;


void			push_swap (t_manage *stacks);
struct s_list	*ft_lstnew(int content);
void			insert_end(t_list **lst, long content);
long			ft_atol(const char *str);
struct s_list	*make_list(char **numbers);
char			**ft_split(char const *s, char c);
void			free_matrix(char **av);
int				ft_strcmp(const char *s1, const char *s2);
int				checker(char **numbers);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
void			push(struct s_list **source, struct s_list **dest, char *str);
void			reverse_rotate(struct s_list **list, char *str);
void			rotate(struct s_list **list, char *str);
void			swap(struct s_list **list, char *str);
int				ft_lstsize(struct s_list *lst);
t_manage		set_manege(char **numbers);
int				min_finder(struct s_list *stack_a);
int				av_finder(struct s_list *stack_a);
int				max_finder(struct s_list *stack_a);
void			push_b(t_manage *stacks);
void			sort_a(t_manage *stacks);
void			push_a(t_manage *stacks);
void			final_sort(t_manage *stacks);
void			sort_2nbrs(t_manage *stacks);
void			sort_3nbrs(t_manage *stacks);
void			sort_to5nbrs(t_manage *stacks);
void			moves_counter(t_manage *stacks);
struct s_list	*bNode_finder(t_manage *stacks, int content);
int				fc_calca(t_manage *stacks, int content);
struct s_list	*cheap_finder(struct s_list *list);
int				position(struct s_list *list, struct s_list *node);
void			tiny_sort(t_manage *stacks);
int				numbers_size(char **numbers);
struct s_list	*find_highest(struct s_list *list);
struct s_list	*find_shortest(struct s_list *list);
void			free_list(t_list *lst);
int				already_sorted(struct s_list *stack);
void			sort_a_nbr(t_manage *stacks);
void			sort_last(t_manage *stacks);

void			print_list(struct s_list *lst, char ch);
#endif