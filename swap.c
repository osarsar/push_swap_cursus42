/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:10 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 01:22:41 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*head;
	int		tmp;

	if (ft_lstsize(*stack_a) <= 1)
		exit(1);
	head = *stack_a;
	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
}

void	sb(t_list **stack_b)
{
	t_list	*head;
	int		tmp;

	if (ft_lstsize(*stack_b) <= 1)
		exit(1);
	head = *stack_b;
	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 1)
		exit(1);
	sa(stack_a);
	if (ft_lstsize(*stack_b) <= 1)
		exit(1);
	sb(stack_b);
}
