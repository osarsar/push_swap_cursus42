/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:31 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 13:12:33 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*head_next;

	head = *stack_b;
	head_next = head->next;
	ft_lstadd_front(stack_a, head);
	*stack_b = head_next;
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*head_1;
	t_list	*head_2;

	head_1 = *stack_a;
	head_2 = head_1->next;
	ft_lstadd_front(stack_b, head_1);
	*stack_a = head_2;
}

void	other_case(char *input, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(input, "ss\n") || !ft_strcmp(input, "sa\n")
		|| !ft_strcmp(input, "sb\n") || !ft_strcmp(input, "ra\n")
		|| !ft_strcmp(input, "rb\n") || !ft_strcmp(input, "rr\n")
		|| !ft_strcmp(input, "rra\n") || !ft_strcmp(input, "rrb\n")
		|| !ft_strcmp(input, "rrr\n") || !ft_strcmp(input, "pa\n")
		|| !ft_strcmp(input, "pb\n"))
		return ;
	else
		quit(*stack_a, *stack_b, input);
}
