/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:52:40 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 16:34:01 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "../push_swap.h"
# include "get_next_line.h"

void	other_case(char *input, t_list **stack_a, t_list **stack_b);
int		check_sort(t_list *stack_a);
void	check_ok(t_list *stack_a, t_list *stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
char	**split_stack(char **av);
int		creat_stack(t_list	*stack_a, char **split);
int		check_valid_stack(char *str);
void	check_same_number(t_list	*stack_a);
void	apply_LIS(t_list *i, t_list *j, t_list *headi, t_list *headj);
void	longest_increasing_subsequence(t_list *stack_a);
int		max_subsequence(t_list *stack_a);
int		ft_list_size(t_list *stack_a);
void	add_minus_one(t_list *stack_a, int len);
t_list	*find_max(t_list *stack_a);
t_list	*find_min(t_list *stack_a);
int		size_stack(t_list *stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
int		check_index(t_list *stack_a);
t_list	*tri_stack(t_list **stack_a, t_list **stack_b);
void	affiche_stack(t_list *stack_a, t_list *stack_b);
void	put_flags(t_list *stack_a, int len, int i, t_list *max);
void	ft_temp(int temp, t_list **stack_a, t_list **stack_b);
t_list	*put_flags_to_stack(t_list **t0, t_list **t2, t_list **b, t_list **a);
void	size_div_2(int len, t_list *head, int nbr);
void	size_no_div_2(int len, t_list *head, int nbr);
void	final_tri_stack(t_list **stack_a);
void	ft_norm(t_list *head, t_list **stack_a, t_list **stack_b);
void	modulation_stack(t_list **stack_a, t_list **stack_b, char *input);
int		ft_strcmp(char *s1, char *s2);
void	free_memory(t_list *stack_a, t_list *stack_b);
void	ag(char **str);
void	quit(t_list *stack_a, t_list *stack_b, char *input);
#endif
