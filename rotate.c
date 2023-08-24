/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:15 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 01:22:34 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*tmp;

	if (ft_lstsize(*stack_a) <= 1)
		exit(1);
	head = *stack_a;
	tmp = head->next;
	ft_lstadd_back(stack_a, head);
	*stack_a = tmp;
}

void	rb(t_list **stack_b)
{
	t_list	*head;
	t_list	*tmp;

	if (ft_lstsize(*stack_b) <= 1)
		exit(1);
	head = *stack_b;
	tmp = head->next;
	ft_lstadd_back(stack_b, head);
	*stack_b = tmp;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 1)
		exit(1);
	ra(stack_a);
	if (ft_lstsize(*stack_b) <= 1)
		exit(1);
	rb(stack_b);
}
